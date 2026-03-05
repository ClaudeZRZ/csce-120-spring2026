#include <vector>
#include <numeric>
#include "dice_cup.h"

using std::vector;

DiceCup::DiceCup() : dice{} {}

void DiceCup::add_dice(Dice d) {
    dice.push_back(d);
}

void DiceCup::roll() {
    for (Dice& d : dice) {
        d.roll();
    }
}

unsigned operator+(unsigned lhs, const Dice& rhs) {
    return lhs + rhs.value();
}

unsigned DiceCup::value() const {
    return std::accumulate(dice.begin(), dice.end(), 0);
}

std::ostream& operator<<(std::ostream& os, const DiceCup& cup) {
    for (const Dice& d : cup.dice) {
        os << d << '\n';
    }
    os << "-------\n";
    os << "tot: " << cup.value();

    return os;
}
