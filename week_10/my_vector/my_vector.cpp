#include "my_vector.h"

void MyVector::pop_back() {
    // TODO(student)
    if (empty()) {
        throw std::out_of_range("vector is empty");
    }
    this->size_--;
}

size_t min(size_t a, size_t b) {
    return (a < b) ? a : b;
}

void MyVector::resize(size_t new_capacity) {
    // TODO(student)
    if (new_capacity == 0) {
        delete[] array_;
        array_ = nullptr;
        capacity_ = 0;
        size_ = 0;
        return;
    }

    // 1. Make a new array
    int* new_array = new int[new_capacity];

    // 2. Copy old array into new array
    //    Only copy the part that will fit
    size_t new_size = min(size_, new_capacity);
    for(size_t i = 0; i < new_size; i++) {
        new_array[i] = array_[i];
    }

    // 3. Delete old array
    delete[] array_;

    // 4. Update array to point to new array and update capacity (and size)
    array_ = new_array;
    capacity_ = new_capacity;
    size_ = new_size;
}

void MyVector::push_back(int value) {
    // TODO(student)
    if (capacity_ == 0 || array_ == nullptr) {
        array_ = new int[1];
        capacity_ = 1;
        size_ = 0;
    }
    if (size_ == capacity_) {
        resize(capacity_ * 2);
    }
    array_[size_] = value;
    size_++;
}

// All other code is provided.

int MyVector::at(size_t index) const {
    if (index >= this->size()) {
        throw std::out_of_range(
            "MyVector::at: index (which is " + std::to_string(index) + ")"
            " >= this->size() (which is " + std::to_string(this->size()) + ")");
    }
    return array_[index];
}
