#include <cstdlib>
#include <stdexcept>
#include "list.h"

void List::push_back(std::string value) {
    if (values_ == nullptr) {
        values_ = new std::string[1];
        capacity_ = 1;
        size_ = 0;
    }
    if (size_ == capacity_) {
        throw std::invalid_argument("invalid: list is full");
    }
    // add value to end of used portion
    values_[size_] = value;
    size_++;
}

void List::pop_back() {
    if (empty()) {
        throw std::invalid_argument("invalid: list is empty");
    }
    // decrement size of used portion
    size_--;
}

std::string List::at(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("at: index out of range");
    }
    return values_[index];
}

std::string List::front() {
    if (empty()) {
        throw std::out_of_range("front: empty list");
    }
    return values_[0];
}

std::string List::back() {
    if (empty()) {
        throw std::out_of_range("back: empty list");
    }
    return values_[size_ -1];
}
