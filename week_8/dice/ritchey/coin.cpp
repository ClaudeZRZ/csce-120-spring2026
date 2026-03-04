#include "coin.h"

Coin::Coin() : die{1,2} {}

void Coin::flip() {
    die.roll();
}

unsigned Coin::value() const {
    return die.value();
}

std::ostream& operator<<(std::ostream& os, const Coin& coin) {
    switch(coin.value()) {
        case HEADS:
            return os << "heads";
        case TAILS:
            return os << "tails";
        default:
            return os << "?????";
    }
}
