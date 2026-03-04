#include "test_helpers.h"

#include <iostream>
#include "dice.h"
#include "dice.h"  // on purpose to check header guards

void test_1d6();
void test_2d10();
void test_20d2();
void test_invalid_dice();
void test_equality();

int main() {
    test_1d6();
    test_2d10();
    test_20d2();
    test_invalid_dice();
    test_equality();

    return 0;
}

void test_1d6() {
    start_tests

    // one 6-sided dice
    Dice dice_1d6(1, 6);

    // default should be snake eyes (all 1s)
    expect_equal(dice_1d6.count(), 1);
    expect_equal(dice_1d6.sides(), 6);
    expect_equal(dice_1d6.value(), 1);

    dice_1d6.roll();

    // roll should result in a value between 1 and 6
    expect_between(dice_1d6.value(), 1, 6);

    end_tests
}

void test_2d10() {
    start_tests

    // two 10-sided dice
    Dice dice_2d10(2, 10);

    // default should be snake eyes (all 1s)
    expect_equal(dice_2d10.count(), 2);
    expect_equal(dice_2d10.sides(), 10);
    expect_equal(dice_2d10.value(), 2);

    dice_2d10.roll();

    // roll should result in a value between 2 and 20
    expect_between(dice_2d10.value(), 2, 20);

    end_tests
}

void test_20d2() {
    start_tests

    // twenty 2-sided dice
    Dice dice_20d2(20, 2);

    // default should be snake eyes (all 1s)
    expect_equal(dice_20d2.count(), 20);
    expect_equal(dice_20d2.sides(), 2);
    expect_equal(dice_20d2.value(), 20);

    dice_20d2.roll();

    // roll should result in a value between 20 and 40
    expect_between(dice_20d2.value(), 20, 40);

    end_tests
}

void test_invalid_dice() {
    start_tests

    expect_throw(Dice(0, 2));
    expect_throw(Dice(2, 0));
    expect_throw(Dice(-1, 2));
    expect_throw(Dice(2, -1));
    expect_throw(Dice(0, 0));
    expect_throw(Dice(-1, -1));
    expect_throw(Dice(3.14, 2.73));

    end_tests
}

void test_equality() {
    start_tests

    Dice dice_2d6_1(2, 6);
    Dice dice_2d6_2(2, 6);
    Dice dice_1d12(1, 12);

    expect_equal(dice_2d6_1, dice_2d6_2);
    expect_not_equal(dice_2d6_1, dice_1d12);

    end_tests
}
