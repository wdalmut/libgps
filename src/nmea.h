#ifndef _NMEA_H_
#define _NMEA_H_

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct gpgga {
    double latitude;
    char lat;
    double longitude;
    char lon;
    uint8_t quality;
    uint8_t satellites;
    double altitude;
};
typedef struct gpgga gpgga_t;

void nmea_parse_gpgga(char *, gpgga_t *);

#endif

