#ifndef PROVIDED_MY_VECTOR_H_
#define PROVIDED_MY_VECTOR_H_

#include <cstdlib>
#include <stdexcept>

class MyVector {
    int* array_;
    size_t capacity_;
    size_t size_;

 public:
    /**
     * Construct an empty vector.
     */
    MyVector() : array_{nullptr}, capacity_{0}, size_{0} {}

    /**
     * The underlying array.
     * For testing purposes only.
     */
    const int* array() const { return array_; }

    /**
     * The capacity of the vector.
     * I.e. the number of elements the vector can hold.
     */
    size_t capacity() const { return capacity_; }

    /**
     * The size of the vector.
     * I.e. the number of elements the vector actually holds.
     */
    size_t size() const { return size_; }

    /**
     * `true` if the vector is empty (size is 0).
     */
    bool empty() const { return size_ == 0; }

    /**
     * Get the value of the element at `index`.
     */
    int at(size_t index) const;

    /**
     * Get the value of the last element.
     */
    int back() const { return at(size_ - 1); }

    /**
     * Get the value of the first element.
     */
    int front() const { return at(0); }

    /**
     * Change the capacity to `new_capacity`.
     */
    void resize(size_t new_capacity);

    /**
     * Add `value` at the back (end).
     */
    void push_back(int value);

    /**
     * Remove the value at the back (end).
     *
     * @throws `std::out_of_range` if the vector is empty.
     */
    void pop_back();
};

#endif  // PROVIDED_MY_VECTOR_H_
