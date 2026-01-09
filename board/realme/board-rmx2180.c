// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) Ryo "evilMyQueen" Yamada <evilMyQueen@mainlining.org> 
 */

#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>

static struct video_info rmx2180_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 736,
	.height = 1600,
	.stride = 4,
	.address = (void *)0x7b890000
};

int rmx2180_drv(void)
{
	REGISTER_DRIVER("simplefb", simplefb_probe, &rmx2180_fb);
	return 0;
}

struct board_data board_ops = {
	.name = "realme-rmx2180",
	.ops = {
		.drivers_init = rmx2180_drv,
	},
	.quirks = 0
};
