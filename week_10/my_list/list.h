#ifndef LIST_H_
#define LIST_H_

#include <cstdlib>
#include <string>

/**
 * A fixed-size list of strings.
 */
class List {
    std::string* values_;
    size_t capacity_;
    size_t size_;

    /**
     * Default construction is not allowed.
     */
    List();

 public:

    /**
     * Construct a new list with the given capacity.
     */
    List(size_t capacity) : values_{new std::string[capacity]}, capacity_{capacity}, size_{0} {}

    /**
     * Destruct a list.
     */
    ~List() { delete[] values_; }

    /**
     * The capacity of the list.
     * How many elements it can hold.
     */
    size_t capacity() const { return capacity_; }

    /**
     * The size of the list.
     * How many elements is actually holds.
     */
    size_t size() const { return size_; }

    /**
     * `true` if the list is empty (size is 0)
     */
    bool empty() const { return size_ == 0; }

    /**
     * Add the value to the end of the list.
     *
     * @throws an exception if the list is full
     */
    void push_back(std::string value);

    /**
     * Remove the value at the end of the list.
     *
     * @throws an exception is the list is empty
     */
    void pop_back();

    /**
     * The value at the given index in the list.
     *
     * @throws an exception if the index is out of bounds
     */
    std::string at(size_t index);

    /**
     * The value at the front of the list.
     * The first element.
     *
     * @throws an exception if the list is empty
     */
    std::string front();

    /**
     * The value at the back of the list.
     * The last element.
     *
     * @throws an exception if the list is empty
     */
    std::string back();
};

#endif  // LIST_H_
