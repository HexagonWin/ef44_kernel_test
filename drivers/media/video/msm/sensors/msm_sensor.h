/* Copyright (c) 2011-2013,2015 The Linux Foundation. All rights reserved.
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

#ifndef MSM_SENSOR_H
#define MSM_SENSOR_H

#include <linux/module.h>
#include <linux/debugfs.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/uaccess.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <mach/camera.h>
#include <media/msm_camera.h>
#include <media/v4l2-subdev.h>
#include "msm_camera_i2c.h"
#include "msm_camera_eeprom.h"
#include "msm_sensor_common.h"
#if 1//def CONFIG_PANTECH_CAMERA
#define OV8820_ID 0x88
#define S5K3H2_ID 0x382B
#define YACD5C1SBDBC_ID 0xB4
#define S5K4ECGX_ID 0x5432
#define MT9V113_ID 0x0167

#define YACD5C1SBDBC_BRIGHTNESS_PARM 2
#define YACD5C1SBDBC_EFFECT_PARM 8
#define YACD5C1SBDBC_EXPOSURE_MODE_PARM 17
#define YACD5C1SBDBC_WB_PARM 8
#define YACD5C1SBDBC_PREVIEW_FPS_PARM 45//42//57//54//
#define YACD5C1SBDBC_PREVIEW_24FPS_PARM 116//243
#define YACD5C1SBDBC_REFLECT_PARM 2
#define YACD5C1SBDBC_CHECK_ZSL_PARM 4

#endif

#ifdef CONFIG_PANTECH_CAMERA
    struct msm_camera_i2c_reg_conf (*bright_cfg_settings)[YACD5C1SBDBC_BRIGHTNESS_PARM];
    uint8_t bright_cfg_settings_size;
    struct msm_camera_i2c_reg_conf (*effect_cfg_settings)[YACD5C1SBDBC_EFFECT_PARM];
    uint8_t effect_cfg_settings_size;
    struct msm_camera_i2c_reg_conf (*exposure_mode_cfg_settings)[YACD5C1SBDBC_EXPOSURE_MODE_PARM];
    uint8_t exposure_mode_cfg_settings_size;
    struct msm_camera_i2c_reg_conf (*wb_cfg_settings)[YACD5C1SBDBC_WB_PARM];
    uint8_t wb_cfg_settings_size;
    struct msm_camera_i2c_reg_conf (*preview_fps_cfg_settings)[YACD5C1SBDBC_PREVIEW_FPS_PARM];
    uint8_t preview_fps_cfg_settings_size;
    struct msm_camera_i2c_reg_conf (*preview_24fps_for_motion_detect_cfg_settings)[YACD5C1SBDBC_PREVIEW_24FPS_PARM];
    uint16_t preview_24fps_for_motion_detect_cfg_settings_size;    
    struct msm_camera_i2c_reg_conf (*reflect_cfg_settings)[YACD5C1SBDBC_REFLECT_PARM];
    uint8_t reflect_cfg_settings_size;       
    struct msm_camera_i2c_reg_conf (*checkzsl_cfg_settings)[YACD5C1SBDBC_CHECK_ZSL_PARM];
    uint8_t checkzsl_cfg_settings_size;
#endif
#ifdef CONFIG_PANTECH_CAMERA_TUNER
    int (*sensor_set_tuner) (struct tuner_cfg);
#endif
#ifdef CONFIG_PANTECH_CAMERA
    int (*sensor_set_brightness) (struct msm_sensor_ctrl_t *, int8_t); // brightness);
    int (*sensor_set_effect) (struct msm_sensor_ctrl_t *, int8_t); // effect);
    int (*sensor_set_exposure_mode) (struct msm_sensor_ctrl_t *, int8_t); // exposure);
    int (*sensor_set_wb) (struct msm_sensor_ctrl_t *, int8_t); // wb);
    int (*sensor_set_preview_fps) (struct msm_sensor_ctrl_t *, int8_t); // preview_fps);     
    int (*sensor_set_auto_focus) (struct msm_sensor_ctrl_t *, int8_t);
    int (*sensor_set_scene_mode) (struct msm_sensor_ctrl_t *, int8_t); 
    int (*sensor_set_reflect) (struct msm_sensor_ctrl_t *, int8_t); // reflect);     
    int (*sensor_set_antibanding) (struct msm_sensor_ctrl_t *, int8_t);
    int (*sensor_set_antishake) (struct msm_sensor_ctrl_t *, int8_t);
    int (*sensor_set_led_mode) (struct msm_sensor_ctrl_t *, int8_t);
    int (*sensor_check_af) (struct msm_sensor_ctrl_t *, int8_t);
    int (*sensor_set_continuous_af) (struct msm_sensor_ctrl_t *, int8_t);
    int (*sensor_set_focus_rect) (struct msm_sensor_ctrl_t *, int32_t, int8_t * f_info);
    int (*sensor_set_hdr) (struct msm_sensor_ctrl_t *);
    int (*sensor_set_metering_area) (struct msm_sensor_ctrl_t *, int32_t, int8_t * f_info);
    int (*sensor_set_ojt_ctrl) (struct msm_sensor_ctrl_t *, int8_t);
#if 1 //def F_PANTECH_CAMERA_FIX_CFG_AE_AWB_LOCK
    int (*sensor_set_aec_lock) (struct msm_sensor_ctrl_t *, int8_t);
    int (*sensor_set_awb_lock) (struct msm_sensor_ctrl_t *, int8_t);
#endif
    int (*sensor_get_frame_info) (struct msm_sensor_ctrl_t *, void __user *argp, int8_t *);
    int (*sensor_lens_stability) (struct msm_sensor_ctrl_t *);
    int (*sensor_get_eeprom_data) (struct msm_sensor_ctrl_t *, struct sensor_cfg_data *);//void *);//eeprom
    int (*sensor_set_focus_mode) (struct msm_sensor_ctrl_t *, int8_t); //FOCUS_MODE
#endif

void msm_sensor_start_stream(struct msm_sensor_ctrl_t *s_ctrl);
void msm_sensor_stop_stream(struct msm_sensor_ctrl_t *s_ctrl);
void msm_sensor_group_hold_on(struct msm_sensor_ctrl_t *s_ctrl);
void msm_sensor_group_hold_off(struct msm_sensor_ctrl_t *s_ctrl);

int32_t msm_sensor_set_fps(struct msm_sensor_ctrl_t *s_ctrl,
			struct fps_cfg   *fps);
int32_t msm_sensor_write_exp_gain1(struct msm_sensor_ctrl_t *s_ctrl,
		uint16_t gain, uint32_t line, int32_t luma_avg, uint16_t fgain);
int32_t msm_sensor_write_exp_gain2(struct msm_sensor_ctrl_t *s_ctrl,
		uint16_t gain, uint32_t line, int32_t luma_avg, uint16_t fgain);
int32_t msm_sensor_set_sensor_mode(struct msm_sensor_ctrl_t *s_ctrl,
	int mode, int res);
int32_t msm_sensor_mode_init(struct msm_sensor_ctrl_t *s_ctrl,
			int mode, struct sensor_init_cfg *init_info);
int32_t msm_sensor_get_output_info(struct msm_sensor_ctrl_t *,
		struct sensor_output_info_t *);
int32_t msm_sensor_config(struct msm_sensor_ctrl_t *s_ctrl,
			void __user *argp);
int32_t msm_sensor_power_up(struct msm_sensor_ctrl_t *s_ctrl);
int32_t msm_sensor_power_down(struct msm_sensor_ctrl_t *s_ctrl);

int32_t msm_sensor_match_id(struct msm_sensor_ctrl_t *s_ctrl);
int msm_sensor_i2c_probe(struct i2c_client *client,
	const struct i2c_device_id *id);

int32_t msm_sensor_platform_probe(struct platform_device *pdev, void *data);
int32_t msm_sensor_platform_dev_probe(struct platform_device *pdev,
					void *data);
int32_t msm_sensor_power(struct v4l2_subdev *sd, int on);

int32_t msm_sensor_v4l2_s_ctrl(struct v4l2_subdev *sd,
	struct v4l2_control *ctrl);

int32_t msm_sensor_v4l2_query_ctrl(
	struct v4l2_subdev *sd, struct v4l2_queryctrl *qctrl);

int msm_sensor_s_ctrl_by_index(struct msm_sensor_ctrl_t *s_ctrl,
	struct msm_sensor_v4l2_ctrl_info_t *ctrl_info, int value);

int msm_sensor_s_ctrl_by_enum(struct msm_sensor_ctrl_t *s_ctrl,
		struct msm_sensor_v4l2_ctrl_info_t *ctrl_info, int value);

int msm_sensor_v4l2_enum_fmt(struct v4l2_subdev *sd, unsigned int index,
			enum v4l2_mbus_pixelcode *code);

int msm_sensor_write_init_settings(struct msm_sensor_ctrl_t *s_ctrl);
int msm_sensor_write_res_settings
	(struct msm_sensor_ctrl_t *s_ctrl, uint16_t res);

int32_t msm_sensor_write_output_settings(struct msm_sensor_ctrl_t *s_ctrl,
	uint16_t res);

void msm_sensor_adjust_frame_lines1(struct msm_sensor_ctrl_t *s_ctrl);
void msm_sensor_adjust_frame_lines2(struct msm_sensor_ctrl_t *s_ctrl);

int32_t msm_sensor_setting(struct msm_sensor_ctrl_t *s_ctrl,
			int update_type, int res);

int32_t msm_sensor_setting1(struct msm_sensor_ctrl_t *s_ctrl,
			int update_type, int res);

int msm_sensor_enable_debugfs(struct msm_sensor_ctrl_t *s_ctrl);

long msm_sensor_subdev_ioctl(struct v4l2_subdev *sd,
			unsigned int cmd, void *arg);

int32_t msm_sensor_get_csi_params(struct msm_sensor_ctrl_t *s_ctrl,
		struct csi_lane_params_t *sensor_output_info);

struct msm_sensor_ctrl_t *get_sctrl(struct v4l2_subdev *sd);
int32_t msm_sensor_free_sensor_data(struct msm_sensor_ctrl_t *s_ctrl);

#define VIDIOC_MSM_SENSOR_CFG \
	_IOWR('V', BASE_VIDIOC_PRIVATE + 4, void __user *)

#define VIDIOC_MSM_SENSOR_RELEASE \
	_IO('V', BASE_VIDIOC_PRIVATE + 11)

#define VIDIOC_MSM_SENSOR_CSID_INFO\
	_IOWR('V', BASE_VIDIOC_PRIVATE + 12, struct msm_sensor_csi_info *)

#endif
