obj-$(CONFIG_CRYPTO_DEV_QAT) += intel_qat.o
intel_qat-objs := adf_cfg.o \
	adf_ctl_drv.o \
	adf_dev_mgr.o \
	adf_init.o \
	adf_accel_engine.o \
	adf_aer.o \
	adf_transport.o \
	qat_crypto.o \
	qat_algs.o \
	qat_uclo.o \
	qat_hal.o

intel_qat-$(CONFIG_DEBUG_FS) += adf_transport_debug.o
