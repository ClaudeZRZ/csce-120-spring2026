#include <iostream>
#include <random>
#include "dice.h"

Dice::Dice(PositiveInteger num_dice, PositiveInteger num_sides) : number_of_dice{num_dice}, number_of_sides{num_sides}, current_value{num_dice} {}

unsigned Dice::count() const { return number_of_dice.get_value(); }

unsigned Dice::sides() const { return number_of_sides.get_value(); }

unsigned Dice::value() const { return current_value.get_value(); }

void Dice::roll() {
    unsigned value = 0;
    for (unsigned i = 0; i < count(); i += 1) {
        value += (rand() % sides()) + 1;
    }
    current_value = value;
}

bool Dice::operator==(const Dice& rhs) const {
    return this->number_of_dice == rhs.number_of_dice
        && this->number_of_sides == rhs.number_of_sides
        && this->current_value == rhs.current_value;
}

std::ostream& operator<<(std::ostream& os, const PositiveInteger& p) {
    return os << p.get_value();
}

std::ostream& operator<<(std::ostream& os, const Dice& d) {
    return os << d.count() << "d" << d.sides() << ": " << d.value();
}
