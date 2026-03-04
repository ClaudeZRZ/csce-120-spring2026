#ifndef DICE_H_
#define DICE_H_

#include <iostream>
#include <stdexcept>

/**
 * A positive integer.
 */
class PositiveInteger {
    unsigned value;

 public:
    /**
     * Construct a new positive integer.
     * This is a converting constructor for `unsigned` -> `PositiveInteger`.
     *
     * @param n unsigned integer value
     * @throws `std::invalid_argument` if `n` is not positive
     */
    PositiveInteger(unsigned n) : value{n} {
        if (n == 0) {
            throw std::invalid_argument("PositiveInteger: 0 is not positive");
        }
    }
    /**
     * Construct a new positive integer.
     * This is a converting constructor for `signed` -> `PositiveInteger`.
     *
     * @param n signed integer value
     * @throws `std::invalid_argument` if `n` is not positive
     */
    PositiveInteger(signed n) : value{static_cast<unsigned>(n)} {
        if (n <= 0) {
            throw std::invalid_argument("PositiveInteger: " + std::to_string(n) + " is not positive");
        }
    }

    /**
     * Construct a new positive integer.
     * This is a converting constructor for `double` -> `PositiveInteger`.
     *
     * @param n floating point value
     * @throws `std::invalid_argument` if `n` is not positive
     */
    PositiveInteger(double f) : value{} {
        throw std::invalid_argument("PositiveInteger: " + std::to_string(f) + " is not an integer");
    }

    /**
     * The value of the object.
     */
    unsigned get_value() const { return value; }

    /**
     * Compare this PositiveInteger with another for equality.
     *
     * @param rhs another PositiveInteger
     * @returns `true` iff this PositiveInteger and `rhs` have the same value
     */
    bool operator==(const PositiveInteger& rhs) const { return this->value == rhs.value; }
};

/**
 * Insert a PositiveInteger object into an output stream.
 *
 * @param os output stream
 * @param p PositiveInteger object
 * @returns the updated output stream
 */
std::ostream& operator<<(std::ostream& os, const PositiveInteger& p);

/**
 * A set of n k-sided dice.
 */
class Dice {
    PositiveInteger number_of_dice;
    PositiveInteger number_of_sides;
    PositiveInteger current_value;

 public:
    /**
     * Construct a set of dice with the given number and sides
     *
     * @param num_dice the number of dice
     * @param num_sides the number of sides on each die
     */
    Dice(PositiveInteger num_dice, PositiveInteger num_sides);

    /**
     * The number of dice.
     */
    unsigned count() const;

    /**
     * The number of sides on each die.
     */
    unsigned sides() const;

    /**
     * The value currently showing on the dice.
     */
    unsigned value() const;

    /**
     * Roll the dice.
     */
    void roll();

    /**
     * Compare this Dice with another for equality.
     *
     * @param rhs the other Dice object
     * @returns `true` iff this Dice and `rhs` have the same number of dice, sides, and value
     */
    bool operator==(const Dice& rhs) const;
};

/**
 * Insert a Dice object into an output stream.
 *
 * @param os output stream
 * @param dice Dice object
 * @returns the updated output stream
 */
std::ostream& operator<<(std::ostream& os, const Dice& dice);

#endif  // DICE_H_
