#include <iostream>
#include <cassert>
#include "list.h"

int main() {
    // given a list that can hold 20 items
    List list(20);

    // then the list's capacity should be 20
    // and the list's size should be 0
    // and the list should be empty
    assert(list.capacity() == 20);
    assert(list.size() == 0);
    assert(list.empty());

    list.push_back("milk");  // should add "milk" to the end of the list

    assert(list.capacity() == 20);
    assert(list.size() == 1);
    assert(!list.empty());
    assert(list.at(0) == "milk");
    assert(list.front() == "milk");
    assert(list.back() == "milk");

    list.pop_back();         // should remove the last element of the list

    assert(list.capacity() == 20);
    assert(list.size() == 0);
    assert(list.empty());

    // TODO: what if push_back on full list?
    // given a full list
    // when i try to add a value
    // then an exception should be thrown
    {
        List list(1);
        list.push_back("1");
        bool exception_thrown = false;
        try {
            list.push_back("2");
            // bad.
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);
    }

    // TODO: what about default constructor
    // Answer: not allowed

    // TODO: what if push_back on default (empty) list?
    // Answer: not allowed

    // TODO: what if index out of bounds for at?
    // given a list
    // when I try to access out of bounds
    // then an exception should be thrown
    {
        List list(1);
        bool exception_thrown = false;
        try {
            list.at(0);
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);
    }
    {
        List list(1);
        list.push_back("1");
        bool exception_thrown = false;
        try {
            list.at(1);
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);
    }

    // TODO: what if front on empty?
    {
        List list(1);
        bool exception_thrown = false;
        try {
            list.front();
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);
    }
    // TODO: what if back on empty?
    {
        List list(1);
        bool exception_thrown = false;
        try {
            list.back();
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);
    }
    // TODO: what is pop_back on empty?
    {
        List list(1);
        bool exception_thrown = false;
        try {
            list.pop_back();
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);
    }

    // TODO: what about memory leaks?
    // compile with -fsanitize=address to detect
    // define destructor to prevent

    // TODO: what if try to create list with capacity 0?
    // given a list with capacity 0
    // then capacity and size should be 0
    // and empty should be true
    // and at, back, front, push_back, pop_back should all throw exceptions
    {
        List list(0);

        assert(list.capacity() == 0);
        assert(list.size() == 0);
        assert(list.empty());

        bool exception_thrown = false;
        try {
            list.at(0);
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);

        exception_thrown = false;
        try {
            list.back();
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);

        exception_thrown = false;
        try {
            list.front();
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);

        exception_thrown = false;
        try {
            list.push_back("x");
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);

        exception_thrown = false;
        try {
            list.pop_back();
        } catch (...) {
            exception_thrown = true;
        }
        assert(exception_thrown);
    }

    std::cout << "all tests passing (so try harder!)" << std::endl;
}
