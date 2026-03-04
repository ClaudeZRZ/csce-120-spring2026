#ifndef COIN_H_
#define COIN_H_

#include "dice.h"

const unsigned TAILS = 1;
const unsigned HEADS = 2;

class Coin {
    Dice die;

 public:
    /**
     * Construct a new coin.
     */
    Coin();

    /**
     * Flip the coin.
     * Change value randomly to either `HEADS` or `TAILS`
     */
    void flip();

    /**
     * The side of the coin which is showing, either `HEADS` or `TAILS`
     */
    unsigned value() const;
};

/**
 * Insert a Coin object into an output stream.
 *
 * @param os output stream
 * @param coin Coin
 * @returns the updated output stream
 */
std::ostream& operator<<(std::ostream& os, const Coin& coin);

#endif  // COIN_H_
