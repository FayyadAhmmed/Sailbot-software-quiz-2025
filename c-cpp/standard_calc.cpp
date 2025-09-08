#include "stdbool.h"
#include "standard_calc.h"
#include "math.h"

/**
 * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle) {
    float bound_to_360 = fmodf(angle, 360.0f);

    if (bound_to_360 >= 180) {
        return (float) (bound_to_360 - 360);
    } else if (bound_to_360 >= 180) {
        return (float) (bound_to_360 + 360);
    } else {
        return (float) bound_to_360;
    }
}

/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 * 
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle) {
    first_angle = fmodf(first_angle, 360);
    middle_angle = fmodf(middle_angle, 360);
    second_angle = fmodf(second_angle, 360);

    float first_second_difference = fmodf((second_angle - first_angle), 360);
    float first_middle_difference = fmodf((middle_angle - first_angle), 360);

    // there is no definable middle
    if (first_second_difference == 0 || first_second_difference == 180) {
        return false;
    }

    // going "directly" from first to second is not the reflex angle
    if (first_second_difference < 180) {
        return (0 < first_middle_difference) && (first_middle_difference < first_second_difference);
    }

    // going "directly" from first to second is the reflex angle
    else {
        return first_middle_difference > first_second_difference;
    }

}
