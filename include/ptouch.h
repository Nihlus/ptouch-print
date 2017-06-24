/*
	ptouch-print - Print labels with images or text on a Brother P-Touch
	
	Copyright (C) 2015-2017 Dominic Radermacher <blip@mockmoon-cybernetics.ch>

	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License version 3 as
	published by the Free Software Foundation
	
	This program is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software Foundation,
	Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <stdint.h>
#include <libusb-1.0/libusb.h>

struct _pt_tape_info {
	uint8_t mm;		/* Tape width in mm */
	uint8_t px;		/* Printing area in px */
};

#define FLAG_NONE		0
#define FLAG_UNSUP_RASTER	1
struct _pt_dev_info {
	int vid;		/* USB vendor ID */
	int pid;		/* USB product ID */
	char *name;
	int max_px;		/* Maximum pixel width that can be printed */
	int flags;
};
typedef struct _pt_dev_info *pt_dev_info;

struct _ptouch_dev {
	libusb_device_handle *h;
	uint8_t raw[32];
	uint8_t tape_width_mm;
	uint8_t tape_width_px;
	uint8_t status;
	uint8_t media_type;
	pt_dev_info devinfo;
};
typedef struct _ptouch_dev *ptouch_dev;

int ptouch_open(ptouch_dev *ptdev);
int ptouch_close(ptouch_dev ptdev);
int ptouch_send(ptouch_dev ptdev, uint8_t *data, int len);
int ptouch_init(ptouch_dev ptdev);
int ptouch_lf(ptouch_dev ptdev);
int ptouch_ff(ptouch_dev ptdev);
int ptouch_cutmark(ptouch_dev ptdev);
int ptouch_eject(ptouch_dev ptdev);
int ptouch_getstatus(ptouch_dev ptdev);
int ptouch_getmaxwidth(ptouch_dev ptdev);
int ptouch_rasterstart(ptouch_dev ptdev);
int ptouch_sendraster(ptouch_dev ptdev, uint8_t *data, int len);
