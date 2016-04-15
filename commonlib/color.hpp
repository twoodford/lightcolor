/*
 * color.hpp
 * Color handling for LED strips
 * 
 * Copyright (C) 2016 Tim Woodford.  All rights reserved.
 *
 */

class ColorScheme {
    public:
        /* 
         * Get the color for a particular segment at a particular time.
         * time is a Unix-epoch time
         * segment identifies a segment of the LEDs
         */
        virtual color_rgb GetColorAtTime(long time, int segment) = 0;
        /*
         * Set the number of LED segments available in hardware.
         *
         * This can be used to give the color scheme a hint as to 
         * how to utilize the available lights.
         */
        virtual int SetNumSegments(long time);
};
