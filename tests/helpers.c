#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>

#include "helpers.h"

void ck_assert_double_eq(double exp, double val, char *msg)
{
    ck_assert_msg(fabs(val - exp) < TEST_EPSILON, msg);
}
