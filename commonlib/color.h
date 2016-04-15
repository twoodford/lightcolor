/*
 * color.h
 * Color handling for LED strips
 *
 * Copyright (C) 2016 Tim Woodford.  All rights reserved.
 *
 */
#include<stdint.h>

#ifndef _CL_COLOR_H_
#define _CL_COLOR_H_

// RGB Color for interchange with Arduino
typedef struct color_rgb {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_rgb;

#endif
