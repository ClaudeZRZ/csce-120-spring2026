#include <iostream>
#include "dice.h"
#include "coin.h"
#include "dice_cup.h"

int main() {
    std::cout << "Rolling 5d20 until value at least 60..." << std::endl;
    Dice dice_5d20(5, 20);
    unsigned i = 0;
    do {
        i += 1;
        dice_5d20.roll();
        std::cout << i << ") rolled " << dice_5d20 << "\n";
    } while (dice_5d20.value() < 60);

    std::cout << "----------" << std::endl;

    std::cout << "Flipping a coin until it lands on heads 5 times..." << std::endl;
    Coin coin;
    i = 0;
    unsigned total = 0;
    while (total < 5) {
        coin.flip();
        i += 1;
        std::cout << i << ") flipped " << coin << "\n";
        if (coin.value() == HEADS) {
            total++;
        }
    }

    std::cout << "----------" << std::endl;

    std::cout << "Rolling a cup of {8d6, 7d5, 3d9} once..." << std::endl;
    DiceCup cup;
    cup.add_dice({8, 6});
    cup.add_dice({7, 5});
    cup.add_dice({3, 9});
    cup.roll();
    std::cout << cup << std::endl;

    return 0;
}
