from standard_calc import bound_to_180, is_angle_between


""" Tests for bound_to_180() """


def test_bound_basic1():
    # given cases
    assert bound_to_180(0) == 0
    assert bound_to_180(200) == -160

    # 180 and above
    assert bound_to_180(180) == -180
    assert bound_to_180(360) == 0
    assert bound_to_180(361) == 1

    # negative angles
    assert bound_to_180(-1) == -1
    assert bound_to_180(-180) == -180
    assert bound_to_180(-181) == 179
    assert bound_to_180(-360) == 0
    assert bound_to_180(-361) == -1


""" Tests for is_angle_between() """


def test_between_basic1():
    # given cases
    assert is_angle_between(0, 1, 2)
    assert is_angle_between(0, 45, 90)
    assert not is_angle_between(45, 90, 270)

    # undefined "middle"
    assert not is_angle_between(0, 0, 90)
    assert not is_angle_between(0, 90, 0)
    assert not is_angle_between(0, 45, 180)

    # "direct" path is not reflex
    assert is_angle_between(0, 45, 90)
    assert not is_angle_between(0, 135, 90)

    # "direct" path is reflex
    assert not is_angle_between(0, 45, 270)
    assert is_angle_between(0, 350, 270)

    # wrap-around
    assert is_angle_between(350, 0, 10)
    assert not is_angle_between(350, 180, 10)
