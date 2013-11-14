#ifndef _GPS_H_
#define _GPS_H_

struct location {
    double latitude;
    double longitude;
};
typedef struct location loc_t;

// Initialize device
extern void gps_init(void);
// Activate device
extern void gps_on(void);
// Get the actual location
extern void gps_location(loc_t *);


// Turn off device (low-power consumption)
extern void gps_off(void);

#endif
