/*
 * lighcontrol.c
 *
 * Command line interface to LED light strip
 */

#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "serial.h"

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("%s: Usage\n", argv[0]);
        printf(" lightcontrol [serial port path]\n");
        return -1;
    }

    int fd = serialport_init(argv[1], 9600);
    if (fd == -1) {
        printf("%s: Fatal error", argv[0]);
        return -1;
    }

    bool cont = true;
    while (cont) {
        char *line = readline("lightcontrol> ");
        char *cmd = strsep(&line, " ");
        if (strcmp(cmd, "quit") == 0) {
            cont = false;
        } else if (strcmp(cmd, "color")) {
            int lightid = atoi(strsep(&line, " "));
            int r = atoi(strsep(&line, " "));
            int g = atoi(strsep(&line, " "));
            int b = atoi(strsep(&line, " "));
            if(lightid < 0 || r < 0 || g < 0 || b < 0) {
                printf("Error: Invalid command arguments");
            } else if (r > 255 || g > 255 || b > 255) {
                printf("Error: Color values must be in range 0-255");
            } else {
                serial_set_color(fd, lightid, r, g, b);
            }
        } else {
            printf("Invalid command %s\n", cmd);
        }
    }
    return 0;
}
