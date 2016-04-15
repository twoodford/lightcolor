#include <stdint.h>
#include "color.h"

#ifndef _CL_COMM_H_
#define _CL_COMM_H_

typedef uint8_t colorcmd;

#define COLORSET_MSG_ID 1
typedef struct colorset {
    uint8_t outid;
    color_rgb next_color;
} colorset_msg;

#define TIMESET_MSG_ID 2
typedef struct timeset {
    long time;
} timeset_msg;

#endif
