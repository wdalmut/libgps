#include <stdio.h>
#include <stdlib.h>
#include <check.h>

Suite *nmea_suite(void);
Suite *serial_suite(void);
Suite *gps_suite(void);

int main(void)
{
    int number_failed;

    Suite *s = nmea_suite();
    Suite *s2 = serial_suite();
    Suite *s3 = gps_suite();

    SRunner *sr = srunner_create(s);
    srunner_add_suite(sr, s2);
    srunner_add_suite(sr, s3);
    srunner_run_all(sr, CK_VERBOSE);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
