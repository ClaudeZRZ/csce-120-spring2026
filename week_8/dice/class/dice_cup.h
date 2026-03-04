#pragma once

#include <vector>

using std::vector;

class DiceCup {
    vector<Dice> dice;

 public:
    DiceCup() : dice{} {}
    unsigned count() const {
        unsigned v = 0;
        for (const Dice& d : dice) {
            v += d.count();
        }
        return v;
    }
    unsigned value() const {
        unsigned v = 0;
        for (const Dice& d : dice) {
            v += d.value();
        }
        return v;
    }
    void add(Dice d) {
        dice.push_back(d);
    }
    void roll() {
        for (Dice& d : dice) {
            d.roll();
        }
    }
};
