#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <math.h>

#include "helpers.h"
#include "gps.h"

START_TEST (test_gps_convert_deg_to_dec)
{
    double lat = 3334.2313457;
    double lon = 11211.0576940;

    gps_convert_deg_to_dec(&lat, 'N', &lon, 'E');

    char buf[48];

    snprintf(buf, sizeof(buf), "The readed latitude is: %lf, want %lf", lat, 33.570522);
    ck_assert_double_eq(33.570522, lat, buf);

    snprintf(buf, sizeof(buf), "The readed longitude is: %lf, want %lf", lon, 112.184295);
    ck_assert_double_eq(112.184295, lon, buf);
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

