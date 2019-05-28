/*
 *	iovec manipulation routines.
 *
 *
 *		This program is free software; you can redistribute it and/or
 *		modify it under the terms of the GNU General Public License
 *		as published by the Free Software Foundation; either version
 *		2 of the License, or (at your option) any later version.
 *
 *	Fixes:
 *		Andrew Lunn	:	Errors in iovec copying.
 *		Pedro Roque	:	Added memcpy_fromiovecend and
 *					csum_..._fromiovecend.
 *		Andi Kleen	:	fixed error handling for 2.1
 *		Alexey Kuznetsov:	2.1 optimisations
 *		Andi Kleen	:	Fix csum*fromiovecend for IPv6.
 */

#include <linux/errno.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/net.h>
#include <linux/in6.h>
#include <asm/uaccess.h>
#include <asm/byteorder.h>
#include <net/checksum.h>
#include <net/sock.h>

/*
 *	Verify iovec. The caller must ensure that the iovec is big enough
 *	to hold the message iovec.
 *
 *	Save time not doing access_ok. copy_*_user will make this work
 *	in any case.
 */

int verify_iovec(struct msghdr *m, struct iovec *iov, struct sockaddr_storage *address, int mode)
{
	int size, ct, err;

	if (m->msg_name && m->msg_namelen) {
		if (mode == VERIFY_READ) {
			void __user *namep;
			namep = (void __user __force *) m->msg_name;
			err = move_addr_to_kernel(namep, m->msg_namelen,
						  address);
			if (err < 0)
				return err;
		}
		m->msg_name = address;
	} else {
		m->msg_name = NULL;
		m->msg_namelen = 0;
	}

	size = m->msg_iovlen * sizeof(struct iovec);
	if (copy_from_user(iov, (void __user __force *) m->msg_iov, size))
		return -EFAULT;

	m->msg_iov = iov;
	err = 0;

	for (ct = 0; ct < m->msg_iovlen; ct++) {
		size_t len = iov[ct].iov_len;

		if (len > INT_MAX - err) {
			len = INT_MAX - err;
			iov[ct].iov_len = len;
		}
		err += len;
	}

	return err;
}

/*
 *	And now for the all-in-one: copy and checksum from a user iovec
 *	directly to a datagram
 *	Calls to csum_partial but the last must be in 32 bit chunks
 *
 *	ip_build_xmit must ensure that when fragmenting only the last
 *	call to this function will be unaligned also.
 */
int csum_partial_copy_fromiovecend(unsigned char *kdata, struct iovec *iov,
				 int offset, unsigned int len, __wsum *csump)
{
	__wsum csum = *csump;
	int partial_cnt = 0, err = 0;

	/* Skip over the finished iovecs */
	while (offset >= iov->iov_len) {
		offset -= iov->iov_len;
		iov++;
	}

	while (len > 0) {
		u8 __user *base = iov->iov_base + offset;
		int copy = min_t(unsigned int, len, iov->iov_len - offset);

		offset = 0;

		/* There is a remnant from previous iov. */
		if (partial_cnt) {
			int par_len = 4 - partial_cnt;

			/* iov component is too short ... */
			if (par_len > copy) {
				if (copy_from_user(kdata, base, copy))
					goto out_fault;
				kdata += copy;
				base += copy;
				partial_cnt += copy;
				len -= copy;
				iov++;
				if (len)
					continue;
				*csump = csum_partial(kdata - partial_cnt,
							 partial_cnt, csum);
				goto out;
			}
			if (copy_from_user(kdata, base, par_len))
				goto out_fault;
			csum = csum_partial(kdata - partial_cnt, 4, csum);
			kdata += par_len;
			base  += par_len;
			copy  -= par_len;
			len   -= par_len;
			partial_cnt = 0;
		}

		if (len > copy) {
			partial_cnt = copy % 4;
			if (partial_cnt) {
				copy -= partial_cnt;
				if (copy_from_user(kdata + copy, base + copy,
						partial_cnt))
					goto out_fault;
			}
		}

		if (copy) {
			csum = csum_and_copy_from_user(base, kdata, copy,
							csum, &err);
			if (err)
				goto out;
		}
		len   -= copy + partial_cnt;
		kdata += copy + partial_cnt;
		iov++;
	}
	*csump = csum;
out:
	return err;

out_fault:
	err = -EFAULT;
	goto out;
}
EXPORT_SYMBOL(csum_partial_copy_fromiovecend);

unsigned long iov_pages(const struct iovec *iov, int offset,
			unsigned long nr_segs)
{
	unsigned long seg, base;
	int pages = 0, len, size;

	while (nr_segs && (offset >= iov->iov_len)) {
		offset -= iov->iov_len;
		++iov;
		--nr_segs;
	}

	for (seg = 0; seg < nr_segs; seg++) {
		base = (unsigned long)iov[seg].iov_base + offset;
		len = iov[seg].iov_len - offset;
		size = ((base & ~PAGE_MASK) + len + ~PAGE_MASK) >> PAGE_SHIFT;
		pages += size;
		offset = 0;
	}

	return pages;
}
EXPORT_SYMBOL(iov_pages);
