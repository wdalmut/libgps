# GPS library

The GPS library

## Build it

In order to obtain `libgps.a`

```shell
$ make
$ sudo make install
```

## Use it

This project is mainly created for Raspberry ARM boards. After you have
compiled the source code on the target or cross-compiling you can include it
in your application

```c
#include <gps.h>
```

The library mainly exposes few methods

 * `gps_init` - Initialize the communication
 * `gps_on` - Activate the GPS device
 * `gps_location` - Expose data from GPS (latitude, longitude, speed, course, altitude)
 * `gps_off` - Turn off the GPS device

This project abstracts all datas and replies in:

 * Decimal Degrees for latitudes and logitudes (46.235325, 7.12521)
   * Not degrees (42° 53' 23.25'' North - 4° 22' 46.3'' West)
 * Knots for speeds
 * Degrees for angles (course)
 * Meters for altitude

### Example - Position logging

Create a simple `position_logger.c` file (you can find all in the examples folder)

```c
#include <stdio.h>
#include <stdlib.h>
#include <gps.h>

int main(void) {
    // Open
    gps_init();

    loc_t data;

    while (1) {
        gps_location(&data);

        printf("%lf %lf\n", data.latitude, data.longitude);
    }

    return EXIT_SUCCESS;
}
```

Compile it

```shell
$ gcc -o position_logger position_logger.c -lgps -lm
```

Run it

```shell
$ ./position_logger
```
You will see your data directly in console:

```shell
45.071060 7.646363
45.071082 7.646385
45.071078 7.646387
45.071060 7.646373
45.071048 7.646358
45.071052 7.646372
45.071057 7.646392
45.071062 7.646397
45.071062 7.646383
45.071073 7.646395
45.071082 7.646403
45.071082 7.646403
45.071080 7.646395
45.071083 7.646392
45.071088 7.646393
```

You can rotate the output to
files

```shell
$ ./position_logger >> position.log
```

That's all...

## Tested components

This library is tested with:

 * Adafruit Ultimate GPS Breakout - 66 channel w/10 Hz updates - Version 3

