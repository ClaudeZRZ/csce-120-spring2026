#pragma once

#include <vector>
#include "die.h"
#include "dice.h"

using std::vector;

class DiceCup {
    vector<Die> dice;

 public:
    DiceCup() : dice{} {}

    unsigned count() const { return dice.size(); }

    unsigned value() const {
        unsigned v = 0;
        for (const Die& d : dice) {
            v += d.value();
        }
        return v;
    }

    void add(Die d) {
        dice.push_back(d);
    }

    void add(Dice d) {
        for (unsigned i = 0; i < d.count(); i++) {
            dice.push_back(Die(d.sides()));
        }
    }

    void add(int number, int sides) {
        this->add(Dice(number, sides));
    }

    void roll() {
        for (Die& d : dice) {
            d.roll();
        }
    }
};
