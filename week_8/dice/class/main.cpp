#include <cassert>

#include <iostream>
#include <stdexcept>
#include "die.h"
#include "dice.h"
#include "coin.h"
#include "dice_cup.h"

using std::cout, std::endl;

void test_die();
void test_dice();
void test_coin();
void test_dice_cup();

int main() {
    test_die();
    test_dice();
    test_coin();
    test_dice_cup();

    Dice dice(6, 7);
    for (int i = 0; i < 3; i++) {
        dice.roll();
        cout << dice << endl;
    }
}

void test_die() {
    try {
        Die d_neg1(-1);
        assert(false && "-1 sides is invalid -> expected exception");
    } catch (const std::invalid_argument&) {
        // good.
    } catch (...) {
        assert(false && "expected std::invalid_argument");
    }

    try {
        Die d0(0);
        assert(false && "0 sides is invalid -> expected exception");
    } catch (const std::invalid_argument&) {
        // good.
    } catch (...) {
        assert(false && "expected std::invalid_argument");
    }

    Die d6(6);  // a 6-sided die
    assert(d6.sides() == 6);
    assert(1 <= d6.value() && d6.value() <= 6);
    d6.roll();
    assert(1 <= d6.value() && d6.value() <= 6);
    unsigned value = d6.value();
    bool value_changed = false;
    for (int i = 0; i < 100 && !value_changed; i++) {
        d6.roll();
        if (d6.value() != value) {
            value_changed = true;
        }
    }
    assert(value_changed);

    std::cout << "all tests passing in " << __func__ << std::endl;
}

void test_dice() {
    try {
        Dice dice(-1, 2);
        assert(false && "-1 count is invalid -> expected exception");
    } catch (const std::invalid_argument&) {
        // good.
    } catch (...) {
        assert(false && "expected std::invalid_argument");
    }

    try {
        Dice dice(1, -1);
        assert(false && "-1 sides is invalid -> expected exception");
    } catch (const std::invalid_argument&) {
        // good.
    } catch (...) {
        assert(false && "expected std::invalid_argument");
    }

    try {
        Dice dice(0, 2);
        assert(false && "0 count is invalid -> expected exception");
    } catch (const std::invalid_argument&) {
        // good.
    } catch (...) {
        assert(false && "expected std::invalid_argument");
    }

    try {
        Dice dice(1, 0);
        assert(false && "0 sides is invalid -> expected exception");
    } catch (const std::invalid_argument&) {
        // good.
    } catch (...) {
        assert(false && "expected std::invalid_argument");
    }

    Dice dice(2, 6);  // 2d6
    assert(dice.count() == 2);
    assert(dice.sides() == 6);
    assert(2 <= dice.value() && dice.value() <= 12);
    dice.roll();
    assert(2 <= dice.value() && dice.value() <= 12);

    unsigned value = dice.value();
    bool value_changed = false;
    for (int i = 0; i < 100 && !value_changed; i++) {
        dice.roll();
        if (dice.value() != value) {
            value_changed = true;
        }
    }
    assert(value_changed);

    std::cout << "all tests passing in " << __func__ << std::endl;
}

void test_coin() {
    Coin coin;
    assert(coin.value() == HEADS || coin.value() == TAILS);
    coin.flip();
    assert(coin.value() == HEADS || coin.value() == TAILS);

    unsigned value = coin.value();
    bool value_changed = false;
    for (int i = 0; i < 100 && !value_changed; i++) {
        coin.flip();
        if (coin.value() != value) {
            value_changed = true;
        }
    }
    assert(value_changed);

    std::cout << "all tests passing in " << __func__ << std::endl;
}

void test_dice_cup() {
    DiceCup dice;
    assert(dice.value() == 0);
    assert(dice.count() == 0);
    dice.roll();

    dice.add(Dice(3, 6));
    assert(3 <= dice.value() && dice.value() <= 18);
    assert(dice.count() == 3);

    dice.add(Dice(2, 8));
    assert(5 <= dice.value() && dice.value() <= 34);
    assert(dice.count() == 5);

    unsigned value = dice.value();
    bool value_changed = false;
    for (int i = 0; i < 100 && !value_changed; i++) {
        dice.roll();
        if (dice.value() != value) {
            value_changed = true;
        }
    }
    assert(value_changed);

    std::cout << "all tests passing in " << __func__ << std::endl;
}
