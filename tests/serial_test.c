#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "serial.h"

START_TEST (test_serial_readline)
{

}
END_TEST

Suite *serial_suite(void)
{
    Suite *s = suite_create("SERIAL");
    TCase *tc_core = tcase_create("SerialCore");
    tcase_add_test(tc_core, test_serial_readline);
    suite_add_tcase(s, tc_core);

    return s;
}

