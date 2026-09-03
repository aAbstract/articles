import module as m


def test_add_nums():
    assert m.add_nums(5, 6) == 11
    assert m.add_nums(2, 3) == 5
    assert m.add_nums(4, 9) == 13
