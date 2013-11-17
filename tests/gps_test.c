#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "gps.h"

START_TEST (test_gps_convert_deg_to_dec)
{
    double lat = 3334.2313457;
    double lon = 11211.0576940;

    gps_convert_deg_to_dec(&lat, 'N', &lon, 'W');

    char buf[48];

    snprintf(buf, sizeof(buf), "The readed latitude is: %f", lat);
    ck_assert_msg(lat == 33.573093, buf);

    snprintf(buf, sizeof(buf), "The readed longitude is: %f", lon);
    ck_assert_msg(lon == -112.184936, buf);
}
END_TEST

Suite *gps_suite(void)
{
    Suite *s = suite_create("GPS");
    TCase *tc_core = tcase_create("GpsCore");
    tcase_add_test(tc_core, test_gps_convert_deg_to_dec);
    suite_add_tcase(s, tc_core);

    return s;
}

