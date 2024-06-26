/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <device/device.h>
#include <drivers/intel/gma/int15.h>
#include <southbridge/intel/bd82x6x/pch.h>
#include <pc80/i8254.h>

static void mainboard_final(void *unused)
{
        beep(2500, 100);
}

static void mainboard_enable(struct device *dev)
{
        install_intel_vga_int15_handler(GMA_INT15_ACTIVE_LFP_NONE,
			GMA_INT15_PANEL_FIT_DEFAULT,
			GMA_INT15_BOOT_DISPLAY_CRT, 0);
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
	.final = mainboard_final,
};
