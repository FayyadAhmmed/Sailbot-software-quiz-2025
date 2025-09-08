#include "stdio.h"
#include "cutest/CuTest.h"
#include "standard_calc.h"

/**************** Tests for bound_to_180() *******************/
void test_bound_basic1(CuTest *tc) {
    CuAssertDblEquals(tc, 0, bound_to_180(0), 0.0001);

    // given cases
    CuAssertDblEquals(tc, 0, bound_to_180(0), 0.0001);
    CuAssertDblEquals(tc, -160, bound_to_180(200), 0.0001);

    // 180 and above
    CuAssertDblEquals(tc, -180, bound_to_180(180), 0.0001);
    CuAssertDblEquals(tc, 0, bound_to_180(360), 0.0001);
    CuAssertDblEquals(tc, 1, bound_to_180(361), 0.0001);

    // negative angles
    CuAssertDblEquals(tc, -1, bound_to_180(-1), 0.0001);
    CuAssertDblEquals(tc, -180, bound_to_180(-180), 0.0001);
    CuAssertDblEquals(tc, 179, bound_to_180(-181), 0.0001);
    CuAssertDblEquals(tc, 0, bound_to_180(-360), 0.0001);
    CuAssertDblEquals(tc, -1, bound_to_180(-361), 0.0001);
}

/**************** Tests for is_angle_between() *******************/
void test_between_basic1(CuTest *tc) {
    // given cases
    CuAssertTrue(tc, is_angle_between(0, 1, 2));
    CuAssertTrue(tc, is_angle_between(0, 45, 90));
    CuAssertTrue(tc, !is_angle_between(45, 90, 270));

    // undefined "middle"
    CuAssertTrue(tc, !is_angle_between(0, 0, 90));
    CuAssertTrue(tc, !is_angle_between(0, 90, 0));
    CuAssertTrue(tc, !is_angle_between(0, 45, 180));

    // "direct" path is not reflex
    CuAssertTrue(tc, is_angle_between(0, 45, 90));
    CuAssertTrue(tc, !is_angle_between(0, 135, 90));

    // "direct" path is reflex
    CuAssertTrue(tc, !is_angle_between(0, 45, 270));
    CuAssertTrue(tc, is_angle_between(0, 350, 270));

    // wrap-around
    CuAssertTrue(tc, is_angle_between(350, 0, 10));
    CuAssertTrue(tc, !is_angle_between(350, 180, 10));

}

int main(int argc, char const *argv[]) {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_bound_basic1);
    SUITE_ADD_TEST(suite, test_between_basic1);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    return suite->failCount > 0 ? 1 : 0;
}
