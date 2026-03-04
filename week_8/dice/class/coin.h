#ifndef COIN_H_
#define COIN_H_

#include "die.h"

const unsigned HEADS = 1;
const unsigned TAILS = 2;

class Coin {
    Die die;

 public:
    Coin() : die{2} {}
    unsigned value() const { return die.value(); }
    void flip() { die.roll(); }
};

#endif  // COIN_H_
