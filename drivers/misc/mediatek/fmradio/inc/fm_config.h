#ifndef __FM_CONFIG_H__
#define __FM_CONFIG_H__

#include "fm_typedef.h"
#include "fm_rds.h"
#include "fm_dbg.h"
#include "fm_err.h"
#include "fm_stdlib.h"
#include "fm_interface.h"
/* band */
#define FM_BAND_UNKNOWN 0
#define FM_BAND_UE      1	/* US/Europe band  87.5MHz ~ 108MHz (DEFAULT) */
#define FM_BAND_JAPAN   2	/* Japan band      76MHz   ~ 90MHz */
#define FM_BAND_JAPANW  3	/* Japan wideband  76MHZ   ~ 108MHz */
#define FM_BAND_SPECIAL 4	/* special   band  between 76MHZ   and  108MHz */
#define FM_BAND_DEFAULT FM_BAND_UE
#define FM_RAIDO_BAND FM_BAND_UE
#define FM_FREQ_MIN  FM_RX_BAND_FREQ_L
#define FM_FREQ_MAX  FM_RX_BAND_FREQ_H

#define FM_UE_FREQ_MIN  8750
#define FM_UE_FREQ_MAX  10800
#define FM_JP_FREQ_MIN  7600
#define FM_JP_FREQ_MAX  10800

#define FM_RX_BAND_FREQ_L     8750	/* FM radio special band low freq(Default 87.5MHz) */
#define FM_RX_BAND_FREQ_H     10800	/* FM radio special band high freq(Default 108.0MHz) */
/* TX */
#define FM_TX_SCAN_HOLE_LOW  9230	/* 92.3MHz~95.4MHz should not show to user */
#define FM_TX_SCAN_HOLE_HIGH 9540	/* 92.3MHz~95.4MHz should not show to user */

/* space */
#define FM_SPACE_UNKNOWN    0
#define FM_SPACE_100K       1
#define FM_SPACE_200K       2
#define FM_SPACE_50K        5

#ifdef CONFIG_MTK_FM_50KHZ_SUPPORT
#define FM_SPACE_DEFAULT    FM_SPACE_50K
#else
#define FM_SPACE_DEFAULT    FM_SPACE_100K
#endif

#define FM_TX_SCAN_UP	(0)
#define FM_TX_SCAN_DOWN	(1)
#define FM_TX_SCAN_MAX 10
#define FM_TX_SCAN_MIN 1

/* seek direction */
#define FM_SEEK_UP          0
#define FM_SEEK_DOWN        1

#define FM_CHIP_AR1000 0x1000
#define FM_CHIP_MT5192 0x91
#define FM_CHIP_MT5193 0x92
#define FM_CHIP_MT6616 0x6616
#define FM_CHIP_MT6626 0x6626
#define FM_CHIP_MT6628 0x6628
#define FM_CHIP_MT6620 0x6620
#define FM_CHIP_MT6627 0x6627
#define FM_CHIP_MT6580 0x6580
#define FM_CHIP_UNSUPPORTED 0xffff

enum fm_cfg_parser_state {
	FM_CFG_STAT_NONE = 0,
	FM_CFG_STAT_GROUP,
	FM_CFG_STAT_KEY,
	FM_CFG_STAT_VALUE,
	FM_CFG_STAT_COMMENT
};

typedef enum fm_cfg_parser_state fm_cfg_parser_state_t;

#define COMMENT_CHAR '#'
#define DELIMIT_CHAR '='

#define isspace(a) ((a) == 0x20)

#define FAKE_CH_MAX 10
#define FM_CUST_CFG_PATH "/etc/fm_cust.cfg"

struct fm_rx_cust_cfg {
	fm_s32 desene_rssi_th;
	fm_s32 pamd_th;
	fm_s32 mr_th;
	fm_s32 atdc_th;
	fm_s32 prx_th;
	fm_s32 atdev_th;
	fm_s32 short_ana_rssi_th;
	fm_s32 long_ana_rssi_th;
	fm_s32 cqi_th;
/* fm_u16 mr_th; */
	fm_s32 smg_th;
	fm_s32 scan_ch_size;
	fm_s32 seek_space;
	fm_s32 band;
	fm_s32 band_freq_l;
	fm_s32 band_freq_h;
	fm_s32 scan_sort;
	fm_s32 fake_ch[FAKE_CH_MAX];
	fm_s32 fake_ch_num;
	fm_s32 fake_ch_rssi_th;
	fm_s32 deemphasis;
	fm_s32 osc_freq;
};

struct fm_tx_cust_cfg {
	fm_s32 scan_hole_low;
	fm_s32 scan_hole_high;
	fm_s32 power_level;
	fm_s32 pamd_th;
	fm_s32 mr_th;
	fm_s32 smg_th;
};
typedef struct {
	struct fm_rx_cust_cfg rx_cfg;
	struct fm_tx_cust_cfg tx_cfg;
	fm_audio_info_t aud_cfg;
} fm_cust_cfg;

enum fm_cust_cfg_op {
	FM_CFG_RX_RSSI_TH_LONG = 0,
	FM_CFG_RX_RSSI_TH_SHORT,
	FM_CFG_RX_CQI_TH,
	FM_CFG_RX_MR_TH,
	FM_CFG_RX_SMG_TH,
	FM_CFG_RX_SCAN_CH_SIZE,
	FM_CFG_RX_SEEK_SPACE,
	FM_CFG_RX_BAND,
	FM_CFG_RX_BAND_FREQ_L,
	FM_CFG_RX_BAND_FREQ_H,
	FM_CFG_RX_SCAN_SORT,
	FM_CFG_RX_FAKE_CH_NUM,
	FM_CFG_RX_FAKE_CH_RSSI,
	FM_CFG_RX_FAKE_CH,
	FM_CFG_RX_DEEMPHASIS,
	FM_CFG_RX_OSC_FREQ,

	FM_CFG_TX_SCAN_HOLE_LOW,
	FM_CFG_TX_SCAN_HOLE_HIGH,
	FM_CFG_TX_PWR_LEVEL,
	FM_CFG_MAX
};

typedef fm_s32(*CFG_HANDLER) (fm_s8 *grp, fm_s8 *key, fm_s8 *val, fm_cust_cfg *cfg);
extern fm_s32 to_upper_n(fm_s8 *str, fm_s32 len);
extern fm_s32 check_hex_str(fm_s8 *str, fm_s32 len);
extern fm_s32 check_dec_str(fm_s8 *str, fm_s32 len);
extern fm_s32 ascii_to_hex(fm_s8 *in_ascii, fm_u16 *out_hex);
extern fm_s32 ascii_to_dec(fm_s8 *in_ascii, fm_s32 *out_dec);
extern fm_s32 trim_string(fm_s8 **start);
extern fm_s32 trim_path(fm_s8 **start);
extern fm_s32 cfg_parser(fm_s8 *buffer, CFG_HANDLER handler, fm_cust_cfg *cfg);
extern fm_s32 cfg_item_match(fm_s8 *src_key, fm_s8 *src_val, fm_s8 *dst_key, fm_s32 *dst_val);

extern fm_s32 fm_cust_config(const fm_s8 *filepath);
extern fm_u16 fm_cust_config_fetch(enum fm_cust_cfg_op op_code);
#ifdef MT6628_FM
extern fm_s32 MT6628fm_cust_config_setup(const fm_s8 *filepath);
extern fm_u16 MT6628fm_cust_config_fetch(enum fm_cust_cfg_op op_code);
#endif
#ifdef MT6620_FM
extern fm_s32 MT6620fm_cust_config_setup(const fm_s8 *filepath);
extern fm_u16 MT6620fm_cust_config_fetch(enum fm_cust_cfg_op op_code);
#endif
#ifdef MT6627_FM
extern fm_s32 MT6627fm_cust_config_setup(const fm_s8 *filepath);
extern fm_u16 MT6627fm_cust_config_fetch(enum fm_cust_cfg_op op_code);
#endif
#ifdef MT6580_FM
extern fm_s32 MT6580fm_cust_config_setup(const fm_s8 *filepath);
extern fm_u16 MT6580fm_cust_config_fetch(enum fm_cust_cfg_op op_code);
#endif
#ifdef MT6630_FM
extern fm_s32 MT6630fm_cust_config_setup(const fm_s8 *filepath);
extern fm_u16 MT6630fm_cust_config_fetch(enum fm_cust_cfg_op op_code);
#endif

#endif /* __FM_CONFIG_H__ */
