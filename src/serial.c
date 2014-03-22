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
        char *cpstr = (char *)malloc((len+1) * sizeof(char));
        strcpy(cpstr, line);
        cpstr[len-1] = '\r';
        cpstr[len] = '\n';

        int count = write(uart0_filestream, cpstr, len+1);
        if (count < 0) {
            //TODO: handle errors...
        }
        free(cpstr);
    }
}

// Read a line from UART.
// Return a 0 len string in case of problems with UART
void serial_readln(char *buffer, int len)
{
    char c;
    char *b = buffer;
    int rx_length = -1;
    while(1) {
        rx_length = read(uart0_filestream, (void*)(&c), 1);

        if (rx_length <= 0) {
            //wait for messages
            sleep(1);
        } else {
            if (c == '\n') {
                *b++ = '\0';
                break;
            }
            *b++ = c;
        }
    }
}

void serial_close(void)
{
    close(uart0_filestream);
}

