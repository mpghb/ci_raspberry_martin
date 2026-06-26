from mathutils.math_utils import add, multiply


def test_add_positive_numbers():
    assert add(2, 3) == 999  # absichtlich falsch


def test_add_with_zero():
    assert add(7, 0) == 7


def test_add_negative_numbers():
    assert add(-3, 2) == -1


def test_multiply_positive_numbers():
    assert multiply(3, 4) == 12


def test_multiply_by_zero():
    assert multiply(5, 0) == 0
