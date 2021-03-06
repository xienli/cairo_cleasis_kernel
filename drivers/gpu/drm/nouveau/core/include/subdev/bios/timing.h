#ifndef __NVBIOS_TIMING_H__
#define __NVBIOS_TIMING_H__

struct nvbios_ramcfg;

u16 nvbios_timingTe(struct nouveau_bios *,
		    u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *snr, u8 *ssz);
u16 nvbios_timingEe(struct nouveau_bios *, int idx,
		    u8 *ver, u8 *hdr, u8 *cnt, u8 *len);
u16 nvbios_timingEp(struct nouveau_bios *, int idx,
		    u8 *ver, u8 *hdr, u8 *cnt, u8 *len,
		    struct nvbios_ramcfg *);

#endif
