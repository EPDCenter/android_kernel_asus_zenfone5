/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#include "ia_css_types.h"
#include "sh_css_defs.h"
#include "ia_css_debug.h"
#include "csc/csc_1.0/ia_css_csc.host.h"
#include "assert_support.h"
#include "vamem.h"

#include "ia_css_gc2.host.h"

const struct ia_css_cc_config default_yuv2rgb_cc_config = {
	12,
	{4096, -4096, 4096, 4096, 4096, 0, 4096, -4096, -4096}
};

const struct ia_css_cc_config default_rgb2yuv_cc_config = {
	13,
	{2449, 4809, 934, -1382, -2714, 4096, 4096, -3430, -666}
};

void
ia_css_yuv2rgb_encode(struct sh_css_isp_csc_params *to,
		  const struct ia_css_cc_config *from)
{
	ia_css_encode_cc(to, from);
}

void
ia_css_rgb2yuv_encode(struct sh_css_isp_csc_params *to,
		  const struct ia_css_cc_config *from)
{
	ia_css_encode_cc(to, from);
}

void
ia_css_r_gamma_vamem_encode(struct sh_css_isp_rgb_gamma_vamem_params *to,
		  const struct ia_css_rgb_gamma_table *from)
{
	memcpy (&to->gc,  &from->data, sizeof(to->gc));
}

void
ia_css_g_gamma_vamem_encode(struct sh_css_isp_rgb_gamma_vamem_params *to,
		  const struct ia_css_rgb_gamma_table *from)
{
	memcpy (&to->gc,  &from->data, sizeof(to->gc));
}

void
ia_css_b_gamma_vamem_encode(struct sh_css_isp_rgb_gamma_vamem_params *to,
		  const struct ia_css_rgb_gamma_table *from)
{
	memcpy (&to->gc,  &from->data, sizeof(to->gc));
}

void
ia_css_yuv2rgb_dump(const struct sh_css_isp_csc_params *yuv2rgb,
		    unsigned level)
{
	ia_css_cc_dump(yuv2rgb, level, "YUV to RGB Conversion");
}

void
ia_css_rgb2yuv_dump(const struct sh_css_isp_csc_params *rgb2yuv,
		    unsigned level)
{
	ia_css_cc_dump(rgb2yuv, level, "RGB to YUV Conversion");
}

void
ia_css_rgb_gamma_table_debug_dtrace(const struct ia_css_rgb_gamma_table *config, unsigned level)
{
	(void)config;
	(void)level;
}

