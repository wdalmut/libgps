#ifndef _NMEA_H_
#define _NMEA_H_

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct gpgga {
    // Latitude eg: 4124.8963 (XXYY.ZZKK.. DEG, MIN, SEC.SS)
    double latitude;
    // Latitude eg: N
    char lat;
    // Longitude eg: 08151.6838 (XXXYY.ZZKK.. DEG, MIN, SEC.SS)
    double longitude;
    // Longitude eg: W
    char lon;
    // Quality 0, 1, 2
    uint8_t quality;
    // Number of satellites: 1,2,3,4,5...
    uint8_t satellites;
    // Altitude eg: 280.2 (Meters above mean sea level)
    double altitude;
};
typedef struct gpgga gpgga_t;

struct gprmc {
    double latitude;
    char lat;
    double longitude;
    char lon;
    double speed;
    double course;
};
typedef struct gprmc gprmc_t;

void nmea_parse_gpgga(char *, gpgga_t *);
void nmea_parse_gprmc(char *, gprmc_t *);

#endif

