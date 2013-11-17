#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <inttypes.h>
#include <string.h>

#include "serial.h"

int uart0_filestream = -1;

void serial_init(void)
{
    uart0_filestream = open(PORTNAME, O_RDWR | O_NOCTTY | O_NDELAY);

    if (uart0_filestream == -1)
    {
        //TODO error handling...
    }
}

void serial_config(void)
{
    struct termios options;
    tcgetattr(uart0_filestream, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);
}

void serial_println(const char *line, int len)
{
    if (uart0_filestream != -1) {
        int count = write(uart0_filestream, line, len);
        if (count < 0) {
            //TODO: handle errors...
        }

        count = write(uart0_filestream, "\n", 1);
        if (count < 0) {
            //TODO: handle errors...
        }
    }
}

void serial_readln(char *buffer, int len)
{
    char *b = buffer;
    int rx_length = -1;
    while(rx_length != 0) {
        rx_length = read(uart0_filestream, (void*)b, len);

        if (rx_length < 0) {
            //TODO: error handling...
        } else if (rx_length == 0) {
            //Nothing to receive
        } else {
            if (strchr(b, '\n') != NULL) {
                b[rx_length] = '\0';
                rx_length = 0;
            } else {
                b += rx_length;
                len -= rx_length;
            }
        }
    }
}

void serial_close(void)
{
    close(uart0_filestream);
}

