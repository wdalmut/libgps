#include "gps.h"
#include <stdio.h>
#include <stdlib.h>

extern void gps_init(void) {

}

extern void gps_on(void) {

}

extern void gps_location(loc_t *coord) {
    coord->latitude  = 43.941866f;
    coord->longitude = 7.828637f;
}

extern void gps_off(void) {

}


