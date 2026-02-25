#include <iomanip>
#include <sstream>
#include <string>
#include "player.h"

void Player::set_name(const std::string& new_name) {
    name_ = new_name;
}

void Player::set_jersey_number(unsigned int new_jersey_number) {
    jersey_number_ = new_jersey_number;
}

void Player::set_position(const std::string& new_position) {
    position_ = new_position;
}

std::string Player::name() const {
    return name_;
}

std::string Player::position() const {
    return position_;
}

unsigned int Player::jersey_number() const {
    return jersey_number_;
}

std::string Player::print() const {
    std::ostringstream oss;
    oss << std::setw(16) << name_
        << " #" << std::setw(2) << jersey_number_
        << " " << position_;
    return oss.str();
}
