/*
 * serial.h
 *
 * Initialize serial connections
 */

#ifndef _SERIAL_H_
#define _SERIAL_H_

extern int serialport_init(const char* serialport, int baud);
extern int serial_set_color(int fd, int lightid, int r, int g, int b);

#endif
