#include "dice.h"

#include <iostream>

Dice::Dice(int number, int sides) : dice{} {
    if (number <= 0) {
        throw std::invalid_argument("dice: number must be positive");
    }
    for (int i = 0; i < number; i++) {
        dice.push_back(Die(sides));
    }
}

unsigned Dice::count() const { return dice.size(); }

unsigned Dice::sides() const { return dice.front().sides(); }

unsigned Dice::value() const {
    unsigned v = 0;
    for (const Die& d : dice) {
        v += d.value();
    }
    return v;
}

void Dice::roll() {
    for (Die& d : this->dice) {
        d.roll();
    }
}

std::ostream& operator<<(std::ostream& os, const Dice& dice) {
    os << dice.count() << "d" << dice.sides() << ": " << dice.value();
    return os;
}
