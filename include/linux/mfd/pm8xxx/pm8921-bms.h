/* Copyright (c) 2011-2013, 2016, The Linux Foundation. All rights
 * reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __PM8XXX_BMS_H
#define __PM8XXX_BMS_H

#include <linux/errno.h>
#include <linux/mfd/pm8xxx/batterydata-lib.h>

#if defined(CONFIG_PANTECH_PMIC_MAX17058)
#include <linux/types.h>
#endif

#define PM8921_BMS_DEV_NAME	"pm8921-bms"

#ifdef CONFIG_PANTECH_BMS_UPDATE
#define PANTECH_BMS_UPDATE_UI_FULL
#ifdef PANTECH_BMS_UPDATE_UI_FULL
#define UI_FULL_SOC     95  // UI FULL for SOC = 99% 
#endif
#endif

#ifdef CONFIG_PANTECH_BMS_BATTERY_TYPE
#if defined(CONFIG_MACH_MSM8960_STARQ)
#define BATTERY_ID_STD_MIN      330000
#define BATTERY_ID_STD_MAX     430000
#define BATTERY_ID_EXT_MIN      550000
#define BATTERY_ID_EXT_MAX      700000

// STANDARD BATTERY
#define CHG_MAX_VOLTAGE_STD 4200
#define CHG_MIN_VOLTAGE_STD 3600
#define CHG_RESUME_VOLTAGE_STD 50
#define CHG_TERM_CURRENT_STD 50
#define CHG_COOL_BAT_VOLTAGE_STD 4000
#define CHG_WARM_BAT_VOLTAGE_STD 4000
#define CHG_SAFETY_TIME_STD 600 //10hours
#define CHG_TTRKL_TIME_STD  30
//#define BMS_ITEST_STD  1166 // 3.55(UUC) = 3.2(v_failure) + x(i_test) * 300(rbatt) ; x = 1.166A, 305mohm(rbatt) = 185mohm(rbatt) * 1.65(1% rbatt scalefacor in room temperature )
//#define BMS_ITEST_STD  1333 // 3.6(UUC) = 3.2(v_failure) + x(i_test) * 300(rbatt) ; x = 1.333A, 305mohm(rbatt) = 185mohm(rbatt) * 1.65(1% rbatt scalefacor in room temperature )
#define BMS_ITEST_STD 1104

// LARGE BATTERY
#define CHG_MAX_VOLTAGE_EXT 4200
#define CHG_MIN_VOLTAGE_EXT 3600
#define CHG_RESUME_VOLTAGE_EXT 50
#define CHG_TERM_CURRENT_EXT 50
#define CHG_COOL_BAT_VOLTAGE_EXT 4000
#define CHG_WARM_BAT_VOLTAGE_EXT 4000
#define CHG_SAFETY_TIME_EXT 1080 //18hours
#define CHG_TTRKL_TIME_EXT  30
#define BMS_ITEST_EXT  1590 // cut-off 3.55
#elif defined (CONFIG_MACH_MSM8960_EF45K)
#define BATTERY_ID_STD_MIN      330000
#define BATTERY_ID_STD_MAX      430000
#define BATTERY_ID_EXT_MIN       45000
#define BATTERY_ID_EXT_MAX      110000

// STANDARD BATTERY
#define CHG_MAX_VOLTAGE_STD 4360 //4350
#define CHG_MIN_VOLTAGE_STD 3600
#define CHG_RESUME_VOLTAGE_STD 40 //50
#define CHG_TERM_CURRENT_STD 50
#define CHG_COOL_BAT_VOLTAGE_STD 4360 //4350
#define CHG_WARM_BAT_VOLTAGE_STD 4360 //4350
#define CHG_SAFETY_TIME_STD 600 //10hours
#define CHG_TTRKL_TIME_STD  64
//#define BMS_ITEST_STD  777 // 3.55(UUC) = 3.2(v_failure) + x(i_test) * 450(rbatt) ; x = 777A, 454mohm(rbatt) = 177mohm(rbatt) * 2.57(1% rbatt scalefacor in room temperature )
//#define BMS_ITEST_STD  888 // 3.6(UUC) = 3.2(v_failure) + x(i_test) * 450(rbatt) ; x = 888A, 454mohm(rbatt) = 177mohm(rbatt) * 2.57(1% rbatt scalefacor in room temperature )
//#define BMS_ITEST_STD  860
#define BMS_ITEST_STD  1060

// LARGE BATTERY
#define CHG_MAX_VOLTAGE_EXT 4360 //4350
#define CHG_MIN_VOLTAGE_EXT 3600
#define CHG_RESUME_VOLTAGE_EXT 40 //50
#define CHG_TERM_CURRENT_EXT 50
#define CHG_COOL_BAT_VOLTAGE_EXT 4360 //4350
#define CHG_WARM_BAT_VOLTAGE_EXT 4360 //4350
#define CHG_SAFETY_TIME_EXT 1080 //18hours
#define CHG_TTRKL_TIME_EXT  64
#define BMS_ITEST_EXT  575
#elif defined (CONFIG_MACH_MSM8960_EF47S)
#define BATTERY_ID_STD_MIN      330000
#define BATTERY_ID_STD_MAX      430000
#define BATTERY_ID_EXT_MIN       45000
#define BATTERY_ID_EXT_MAX      110000

// STANDARD BATTERY
#define CHG_MAX_VOLTAGE_STD 4360 //4350
#define CHG_MIN_VOLTAGE_STD 3600
#define CHG_RESUME_VOLTAGE_STD 40 //50
#define CHG_TERM_CURRENT_STD 50
#define CHG_COOL_BAT_VOLTAGE_STD 4360 //4350
#define CHG_WARM_BAT_VOLTAGE_STD 4360 //4350
#define CHG_SAFETY_TIME_STD 600 //10hours
#define CHG_TTRKL_TIME_STD  64
//#define BMS_ITEST_STD  777
//#define BMS_ITEST_STD  888
//#define BMS_ITEST_STD  860
#define BMS_ITEST_STD  1060

// LARGE BATTERY
#define CHG_MAX_VOLTAGE_EXT 4360 //4350
#define CHG_MIN_VOLTAGE_EXT 3600
#define CHG_RESUME_VOLTAGE_EXT 40 //50
#define CHG_TERM_CURRENT_EXT 50
#define CHG_COOL_BAT_VOLTAGE_EXT 4360 //4350
#define CHG_WARM_BAT_VOLTAGE_EXT 4360 //4350
#define CHG_SAFETY_TIME_EXT 1080 //18hours
#define CHG_TTRKL_TIME_EXT  64
#define BMS_ITEST_EXT  575
#elif defined (CONFIG_MACH_MSM8960_EF46L)
#define BATTERY_ID_STD_MIN      330000
#define BATTERY_ID_STD_MAX      430000
#define BATTERY_ID_EXT_MIN       45000
#define BATTERY_ID_EXT_MAX      110000

// STANDARD BATTERY
#define CHG_MAX_VOLTAGE_STD 4360 //4350
#define CHG_MIN_VOLTAGE_STD 3600
#define CHG_RESUME_VOLTAGE_STD 40 //50
#define CHG_TERM_CURRENT_STD 50
#define CHG_COOL_BAT_VOLTAGE_STD 4360 //4350
#define CHG_WARM_BAT_VOLTAGE_STD 4360 //4350
#define CHG_SAFETY_TIME_STD 600 //10hours
#define CHG_TTRKL_TIME_STD  64
//#define BMS_ITEST_STD  777
//#define BMS_ITEST_STD  888
//#define BMS_ITEST_STD  860
#define BMS_ITEST_STD  1060

// LARGE BATTERY
#define CHG_MAX_VOLTAGE_EXT 4360 //4350
#define CHG_MIN_VOLTAGE_EXT 3600
#define CHG_RESUME_VOLTAGE_EXT 40 //50
#define CHG_TERM_CURRENT_EXT 50
#define CHG_COOL_BAT_VOLTAGE_EXT 4360 //4350
#define CHG_WARM_BAT_VOLTAGE_EXT 4360 //4350
#define CHG_SAFETY_TIME_EXT 1080 //18hours
#define CHG_TTRKL_TIME_EXT  64
#define BMS_ITEST_EXT  575
#elif defined (CONFIG_MACH_MSM8960_EF44S)
#define BATTERY_ID_STD_MIN       330000
#define BATTERY_ID_STD_MAX       430000
#define BATTERY_ID_EXT_MIN       330000
#define BATTERY_ID_EXT_MAX       430000

// STANDARD BATTERY
#define CHG_MAX_VOLTAGE_STD      4360
#define CHG_MIN_VOLTAGE_STD      3600
#define CHG_RESUME_VOLTAGE_STD   30
#define CHG_TERM_CURRENT_STD     50
#define CHG_COOL_BAT_VOLTAGE_STD 4360
#define CHG_WARM_BAT_VOLTAGE_STD 4360
#define CHG_SAFETY_TIME_STD      600 //10hours
#define CHG_TTRKL_TIME_STD       64
#define BMS_ITEST_STD  1060

// LARGE BATTERY
#define CHG_MAX_VOLTAGE_EXT      4360
#define CHG_MIN_VOLTAGE_EXT      3600
#define CHG_RESUME_VOLTAGE_EXT   30
#define CHG_TERM_CURRENT_EXT     50
#define CHG_COOL_BAT_VOLTAGE_EXT 4360
#define CHG_WARM_BAT_VOLTAGE_EXT 4360
#define CHG_SAFETY_TIME_EXT      600 //10hours
#define CHG_TTRKL_TIME_EXT       64
#define BMS_ITEST_EXT  575
#elif defined (CONFIG_MACH_MSM8960_OSCAR)
#define BATTERY_ID_STD_MIN       330000
#define BATTERY_ID_STD_MAX       430000
#define BATTERY_ID_EXT_MIN        50000
#define BATTERY_ID_EXT_MAX       100000

// Standard Battery
#define CHG_MAX_VOLTAGE_STD      4360
#define CHG_MIN_VOLTAGE_STD      3600
#define CHG_RESUME_VOLTAGE_STD   60
#define CHG_TERM_CURRENT_STD     50
#define CHG_COOL_BAT_VOLTAGE_STD 4000
#define CHG_WARM_BAT_VOLTAGE_STD 4000
#define CHG_SAFETY_TIME_STD      512
#define CHG_TTRKL_TIME_STD       64
#define BMS_ITEST_STD  988 // cut-off 3.6

// External Battery
#define CHG_MAX_VOLTAGE_EXT      4360
#define CHG_MIN_VOLTAGE_EXT      3600
#define CHG_RESUME_VOLTAGE_EXT   60
#define CHG_TERM_CURRENT_EXT     50
#define CHG_COOL_BAT_VOLTAGE_EXT 4000
#define CHG_WARM_BAT_VOLTAGE_EXT 4000
#define CHG_SAFETY_TIME_EXT      512
#define CHG_TTRKL_TIME_EXT       64
#define BMS_ITEST_EXT  988 // cut-off 3.6
#elif defined (CONFIG_MACH_MSM8960_VEGAPVW)
#define BATTERY_ID_LG_STD_MIN       329000
#define BATTERY_ID_LG_STD_MAX       444000
#define BATTERY_ID_SS_STD_MIN       40000
#define BATTERY_ID_SS_STD_MAX       120000
#define BATTERY_ID_EXT_MIN       531000
#define BATTERY_ID_EXT_MAX       717000

// Standard Battery
#define CHG_MAX_VOLTAGE_STD      4350
#define CHG_MIN_VOLTAGE_STD      3600
#define CHG_RESUME_VOLTAGE_STD   50
#define CHG_TERM_CURRENT_STD     50
#define CHG_COOL_BAT_VOLTAGE_STD 4000
#define CHG_WARM_BAT_VOLTAGE_STD 4000
#define CHG_SAFETY_TIME_STD 600 //10hours
#define CHG_TTRKL_TIME_STD       64
#define BMS_ITEST_STD  1060

// External Battery
#define CHG_MAX_VOLTAGE_EXT      4350
#define CHG_MIN_VOLTAGE_EXT      3600
#define CHG_RESUME_VOLTAGE_EXT   50
#define CHG_TERM_CURRENT_EXT     50
#define CHG_COOL_BAT_VOLTAGE_EXT 4000
#define CHG_WARM_BAT_VOLTAGE_EXT 4000
#define CHG_SAFETY_TIME_EXT 1080 //18hours
#define CHG_TTRKL_TIME_EXT       64
#define BMS_ITEST_EXT  575

#elif defined (CONFIG_MACH_MSM8960_MAGNUS)
#define BATTERY_ID_SY_STD_MIN    30000
#define BATTERY_ID_SY_STD_MAX    130000
#define BATTERY_ID_SS_STD_MIN    330000
#define BATTERY_ID_SS_STD_MAX    430000
#define BATTERY_ID_EXT_MIN       BATTERY_ID_SS_STD_MIN
#define BATTERY_ID_EXT_MAX       BATTERY_ID_SS_STD_MAX

// Standard Battery
#define CHG_MAX_VOLTAGE_STD      4360
#define CHG_MIN_VOLTAGE_STD      3600
#define CHG_RESUME_VOLTAGE_STD   50
#define CHG_TERM_CURRENT_STD     50 
#define CHG_COOL_BAT_VOLTAGE_STD 4360
#define CHG_WARM_BAT_VOLTAGE_STD 4000
#define CHG_SAFETY_TIME_STD      600
#define CHG_TTRKL_TIME_STD       64
#define BMS_ITEST_STD  1060

// External Battery
#define CHG_MAX_VOLTAGE_EXT      4360
#define CHG_MIN_VOLTAGE_EXT      3600
#define CHG_RESUME_VOLTAGE_EXT   50
#define CHG_TERM_CURRENT_EXT     50
#define CHG_COOL_BAT_VOLTAGE_EXT 4360
#define CHG_WARM_BAT_VOLTAGE_EXT 4000
#define CHG_SAFETY_TIME_EXT      600
#define CHG_TTRKL_TIME_EXT       64
#define BMS_ITEST_EXT  575

#else
#define BATTERY_ID_STD_MIN      330000
#define BATTERY_ID_STD_MAX     430000
#define BATTERY_ID_EXT_MIN      550000
#define BATTERY_ID_EXT_MAX      700000

// STANDARD BATTERY
#define CHG_MAX_VOLTAGE_STD 4200
#define CHG_MIN_VOLTAGE_STD 3600
#define CHG_RESUME_VOLTAGE_STD 50
#define CHG_TERM_CURRENT_STD 50
#define CHG_COOL_BAT_VOLTAGE_STD 4200
#define CHG_WARM_BAT_VOLTAGE_STD 4200
#define CHG_SAFETY_TIME_STD 600 //10hours
#define CHG_TTRKL_TIME_STD  64
#define BMS_ITEST_STD  2000

// LARGE BATTERY
#define CHG_MAX_VOLTAGE_EXT 4200
#define CHG_MIN_VOLTAGE_EXT 3600
#define CHG_RESUME_VOLTAGE_EXT 50
#define CHG_TERM_CURRENT_EXT 50
#define CHG_COOL_BAT_VOLTAGE_EXT 4200
#define CHG_WARM_BAT_VOLTAGE_EXT 4200
#define CHG_SAFETY_TIME_EXT 1080 //18hours
#define CHG_TTRKL_TIME_EXT  64
#define BMS_ITEST_EXT  2000
#endif //defined(CONFIG_MACH_MSM8960_STARQ)

#ifdef FEATURE_PANTECH_BATTERY_DUMMY
#if defined (CONFIG_MACH_MSM8960_VEGAPVW) 
#define BATTERY_ID_DUMMY_MIN   980000
#define BATTERY_ID_DUMMY_MAX   1200000
#elif  defined (CONFIG_MACH_MSM8960_MAGNUS)
#define BATTERY_ID_DUMMY_MIN   980000
#define BATTERY_ID_DUMMY_MAX   1200000
#define BATTERY_ID_DUMMY_MIN_OLD   1420000
#define BATTERY_ID_DUMMY_MAX_OLD   1620000
#else
#define BATTERY_ID_DUMMY_MIN   1420000
#define BATTERY_ID_DUMMY_MAX   1620000
#endif
#endif /* FEATURE_PANTECH_BATTERY_DUMMY */
#endif


struct pm8xxx_bms_core_data {
	unsigned int	batt_temp_channel;
	unsigned int	vbat_channel;
	unsigned int	ref625mv_channel;
	unsigned int	ref1p25v_channel;
	unsigned int	batt_id_channel;
};

/**
 * struct pm8921_bms_platform_data -
 * @batt_type:		allows to force chose battery calibration data
 * @r_sense_uohm:	sense resistor value in (micro Ohms)
 * @i_test:		current at which the unusable charger cutoff is to be
 *			calculated or the peak system current (mA)
 * @v_cutoff:		the loaded voltage at which the battery
 *			is considered empty(mV)
 * @enable_fcc_learning:	if set the driver will learn full charge
 *				capacity of the battery upon end of charge
 * @min_fcc_learning_soc:	minimum SOC as which CC counting for FCC
 *				learning can start
 * @min_fcc_ocv_pc:		minimum PC (lookup(OCV)) at which CC counting
 *				for FCC learning can start
 * @min_fcc_learning_samples:	Minimum number of FCC measurement cycles to be
 *				used for FCC update
 * @normal_voltage_calc_ms:	The period of soc calculation in ms when battery
 *				voltage higher than cutoff voltage
 * @low_voltage_calc_ms:	The period of soc calculation in ms when battery
 *				voltage is near cutoff voltage
 * @disable_flat_portion_ocv:	feature to disable ocv updates while in sleep
 * @ocv_dis_high_soc:		the high soc percent when ocv should be disabled
 * @ocv_dis_low_soc:		the low soc percent when ocv should be enabled
 * @low_voltage_detect:		feature to enable 0 SOC reporting on low volatge
 * @vbatt_cutoff_retries:	number of tries before we report a 0 SOC
 * @high_ocv_correction_limit_uv:	the max amount of OCV corrections
 *					allowed when ocv is high
 *					(higher than 3.8V)
 * @low_ocv_correction_limit_uv:	the max amount of OCV corrections
 *					allowed when ocv is low
 *					(lower or equal to 3.8V)
 * @hold_soc_est:		the min est soc below which the calculated soc
 *				is allowed to go to 0%
 */
struct pm8921_bms_platform_data {
	struct pm8xxx_bms_core_data	bms_cdata;
	enum battery_type		battery_type;
	int				r_sense_uohm;
	unsigned int			i_test;
	unsigned int			v_cutoff;
	unsigned int			calib_delay_ms;
	unsigned int			max_voltage_uv;
	unsigned int			rconn_mohm;
	unsigned int			alarm_low_mv;
	unsigned int			alarm_high_mv;
	int				enable_fcc_learning;
	int				min_fcc_learning_soc;
	int				min_fcc_ocv_pc;
	int				min_fcc_learning_samples;
	int				shutdown_soc_valid_limit;
	int				ignore_shutdown_soc;
	int				adjust_soc_low_threshold;
	int				chg_term_ua;
	int				normal_voltage_calc_ms;
	int				low_voltage_calc_ms;
	int				disable_flat_portion_ocv;
	int				ocv_dis_high_soc;
	int				ocv_dis_low_soc;
	int				low_voltage_detect;
	int				vbatt_cutoff_retries;
	int				high_ocv_correction_limit_uv;
	int				low_ocv_correction_limit_uv;
	int				hold_soc_est;
	int				disable_bms;
};

#if defined(CONFIG_PM8921_BMS) || defined(CONFIG_PM8921_BMS_MODULE)
#ifdef CONFIG_PANTECH_BMS_BATTERY_TYPE
extern struct pm8921_bms_battery_data  pantech_battery_std;
extern struct pm8921_bms_battery_data  pantech_battery_ext;
#else
#endif
/**
 * pm8921_bms_get_vsense_avg - return the voltage across the sense
 *				resitor in microvolts
 * @result:	The pointer where the voltage will be updated. A -ve
 *		result means that the current is flowing in
 *		the battery - during battery charging
 *
 * RETURNS:	Error code if there was a problem reading vsense, Zero otherwise
 *		The result won't be updated in case of an error.
 *
 *
 */
int pm8921_bms_get_vsense_avg(int *result);

/**
 * pm8921_bms_get_battery_current - return the battery current based on vsense
 *				resitor in microamperes
 * @result:	The pointer where the voltage will be updated. A -ve
 *		result means that the current is flowing in
 *		the battery - during battery charging
 *
 * RETURNS:	Error code if there was a problem reading vsense, Zero otherwise
 *		The result won't be updated in case of an error.
 *
 */
int pm8921_bms_get_battery_current(int *result);

/**
 * pm8921_bms_get_percent_charge - returns the current battery charge in percent
 *
 */
int pm8921_bms_get_percent_charge(void);

/**
 * pm8921_bms_get_fcc - returns fcc in mAh of the battery depending on its age
 *			and temperature
 *
 */
int pm8921_bms_get_fcc(void);

/**
 * pm8921_bms_charging_began - function to notify the bms driver that charging
 *				has started. Used by the bms driver to keep
 *				track of chargecycles
 */
void pm8921_bms_charging_began(void);
/**
 * pm8921_bms_charging_end - function to notify the bms driver that charging
 *				has stopped. Used by the bms driver to keep
 *				track of chargecycles
 */
void pm8921_bms_charging_end(int is_battery_full);

void pm8921_bms_calibrate_hkadc(void);
/**
 * pm8921_bms_get_simultaneous_battery_voltage_and_current
 *		- function to take simultaneous vbat and vsense readings
 *		  this puts the bms in override mode but keeps coulumb couting
 *		  on. Useful when ir compensation needs to be implemented
 */
int pm8921_bms_get_simultaneous_battery_voltage_and_current(int *ibat_ua,
								int *vbat_uv);
/**
 * pm8921_bms_get_current_max
 *	- function to get the max current that can be drawn from
 *	  the battery before it dips below the min allowed voltage
 */
int pm8921_bms_get_current_max(void);
#ifdef CONFIG_PANTECH_BMS_UPDATE
/**
 * pm8921_bms_get_percent - returns the battery in percent
 *
 */
#if defined(CONFIG_PANTECH_PMIC_MAX17058)

/**
 * pm8921_bms_cc_uah -	function to get the coulomb counter based charge. Note
 *			that the coulomb counter are reset when the current
 *			consumption is low (below 8mA for more than 5 minutes),
 *			This will lead in a very low coulomb counter charge
 *			value upon wakeup from sleep.
 */
int pm8921_bms_cc_uah(int *cc_uah);

/**
 * pm8921_bms_battery_removed -	function to be called to tell the bms that
 *			the battery is removed. The bms resets its internal
 *			history data used to report soc.
 */
void pm8921_bms_battery_removed(void);
/**
 * pm8921_bms_battery_inseted -	function to be called to tell the bms that
 *			the battery was inserted. The bms initiates calculations
 *			for reporting soc.
 */
void pm8921_bms_battery_inserted(void);
#else
static inline int pm8921_bms_get_vsense_avg(int *result)
{
	return -ENXIO;
}
static inline int pm8921_bms_get_battery_current(int *result)
{
	return -ENXIO;
}
static inline int pm8921_bms_get_percent_charge(void)
{
	return -ENXIO;
}
static inline int pm8921_bms_get_fcc(void)
{
	return -ENXIO;
}
static inline void pm8921_bms_charging_began(void)
{
}
static inline void pm8921_bms_charging_end(int is_battery_full)
{
}
static inline void pm8921_bms_calibrate_hkadc(void)
{
}
static inline int pm8921_bms_get_simultaneous_battery_voltage_and_current(
						int *ibat_ua, int *vbat_uv)
{
	return -ENXIO;
}
static inline int pm8921_bms_get_rbatt(void)
{
	return -EINVAL;
}
#ifdef CONFIG_PANTECH_BMS_UPDATE
#if defined(CONFIG_PANTECH_PMIC_MAX17058)
static inline int pm8921_bms_get_percent(bool max17058_uses);
{
	return -ENXIO;
}
#else 
static inline int pm8921_bms_get_percent(void)
{
	return -ENXIO;
}
static inline int pm8921_bms_cc_uah(int *cc_uah)
{
	return -ENXIO;
}
static inline int pm8921_bms_get_current_max(void)
{
	return -ENXIO;
}
static inline void pm8921_bms_battery_removed(void) {}
static inline void pm8921_bms_battery_inserted(void) {}
#endif

#endif
