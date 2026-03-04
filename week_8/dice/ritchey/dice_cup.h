#ifndef DICE_CUP_H_
#define DICE_CUP_H_

#include <vector>
#include "dice.h"

using std::vector;

class DiceCup {
    vector<Dice> dice;

 public:
    /**
     * Construct an empty cup of dice.
     */
    DiceCup();

    /**
     * Add dice to the cup.
     *
     * @param d Dice to add
     */
    void add_dice(Dice d);

    /**
     * Roll the dice in the cup.
     */
    void roll();

    /**
     * The total value currently showing on the dice in the cup.
     */
    unsigned value() const;

    friend std::ostream& operator<<(std::ostream&, const DiceCup&);
};

/**
 * Insert a DiceCup object into an output stream
 *
 * @param os output stream
 * @param cup the cup of dice
 * @returns the updated output stream
 */
std::ostream& operator<<(std::ostream& os, const DiceCup& cup);

#endif  // DICE_CUP_H_
