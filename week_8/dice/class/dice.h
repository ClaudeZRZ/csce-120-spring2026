#ifndef DICE_H_
#define DICE_H_

#include <iostream>
#include <vector>
#include "die.h"

using std::vector;

class Dice {
    vector<Die> dice;

 public:
    Dice(int, int);
    unsigned count() const;
    unsigned sides() const;
    unsigned value() const;
    void roll();
};

std::ostream& operator<<(std::ostream& os, const Dice& dice);

#endif  // DICE_H_
