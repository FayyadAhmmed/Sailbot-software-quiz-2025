def bound_to_180(angle):
    """Bounds the provided angle between [-180, 180) degrees.

    e.g.)
        bound_to_180(135) = 135.0
        bound_to_180(200) = -160.0

    Args:
        angle (float): The input angle in degrees.

    Returns:
        float: The bounded angle in degrees.
    """
    bound_to_360 = angle % 360
    if bound_to_360 >= 180:
        return float(bound_to_360 - 360)
    else:
        return float(bound_to_360)


def is_angle_between(first_angle, middle_angle, second_angle):
    """Determines whether an angle is between two other angles.

    e.g.)
        is_angle_between(0, 45, 90) = True
        is_angle_between(45, 90, 270) = False

    Args:
        first_angle (float): The first bounding angle in degrees.
        middle_angle (float): The angle in question in degrees.
        second_angle (float): The second bounding angle in degrees.

    Returns:
        bool: True when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, false otherwise.
    """
    first_angle = first_angle % 360
    middle_angle = middle_angle % 360
    second_angle = second_angle % 360

    first_second_difference = (second_angle - first_angle) % 360
    first_middle_difference = (middle_angle - first_angle) % 360

    # there is no definable middle
    if first_second_difference == 0 or first_second_difference == 180:
        return False

    # going "directly" from first to second is not the reflex angle
    if first_second_difference < 180:
        return 0 < first_middle_difference < first_second_difference

    # going "directly" from first to second is the reflex angle
    else:
        return first_middle_difference > first_second_difference
