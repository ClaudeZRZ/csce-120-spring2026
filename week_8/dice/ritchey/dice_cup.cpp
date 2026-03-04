#include <vector>
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

unsigned DiceCup::value() const {
    unsigned v = 0;
    for (const Dice& d : dice) {
        v += d.value();
    }
    return v;
}

std::ostream& operator<<(std::ostream& os, const DiceCup& cup) {
    for (const Dice& d : cup.dice) {
        os << d << '\n';
    }
    os << "-------\n";
    os << "tot: " << cup.value();

    return os;
}
