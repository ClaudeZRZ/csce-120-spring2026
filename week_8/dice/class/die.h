#ifndef DIE_H_
#define DIE_H_

#include <cstdlib>
#include <stdexcept>

class Die {
    unsigned sides_;
    unsigned value_;

 public:
    explicit Die(int sides) : sides_{static_cast<unsigned>(sides)}, value_{1} {
        if (sides <= 0) {
            throw std::invalid_argument("die: sides must be positive");
        }
    }
    unsigned sides() const { return sides_; }
    unsigned value() const { return value_; }
    void roll() {
        value_ = (rand() % sides_) + 1;
    }
};

#endif  // DIE_H_
