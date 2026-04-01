#include <iostream>
#include <cassert>
#include "my_vector.h"

void test_pop_back();
void test_push_back();
void test_resize();

int main() {
    test_pop_back();
    test_resize();
    test_push_back();

    std::cout << __func__ << " : all tests passing\n" << std::endl;

    return 0;
}

struct FakeVector {
    int* array_;
    size_t capacity_;
    size_t size_;
};

void test_pop_back() {
    std::cout <<
    "Given an empty MyVector\n"
    "When I `pop_back`\n"
    "Then a `std::out_of_range` exception should be thrown\n"
    "And the size should be 0\n"
    "And the capacity should be 0\n"
    << std::endl;
    {
        MyVector vector;

        bool out_of_range_thrown = false;
        try {
            vector.pop_back();
        } catch (const std::out_of_range&) {
            out_of_range_thrown = true;

        } catch (...) {}
        assert(out_of_range_thrown);
        assert(vector.size() == 0);
        assert(vector.capacity() == 0);
    }

    std::cout <<
    "Given a MyVector with capacity 7 and size 0\n"
    "When I `pop_back`\n"
    "Then a `std::out_of_range` exception should be thrown\n"
    "And the size should be 0\n"
    "And the capacity should be 7\n"
    << std::endl;
    {
        MyVector vector;
        FakeVector* fv = reinterpret_cast<FakeVector*>(&vector);
        fv->array_ = new int[7];
        fv->capacity_ = 7;
        fv->size_ = 0;

        bool out_of_range_thrown = false;
        try {
            vector.pop_back();
        } catch (const std::out_of_range&) {
            out_of_range_thrown = true;

        } catch (...) {}
        assert(out_of_range_thrown);
        assert(vector.size() == 0);
        assert(vector.capacity() == 7);
    }

    std::cout <<
    "Given a MyVector with capacity 7 and size 3: {8, 6, 7}\n"
    "When I `pop_back`\n"
    "Then the size should be 2\n"
    "And the capacity should be 7\n"
    "And the back be 6\n"
    << std::endl;
    {
        MyVector vector;
        FakeVector* fv = reinterpret_cast<FakeVector*>(&vector);
        fv->array_ = new int[7] {8, 6, 7};
        fv->capacity_ = 7;
        fv->size_ = 3;

        vector.pop_back();

        assert(vector.size() == 2);
        assert(vector.capacity() == 7);
        assert(vector.back() == 6);
    }

    std::cout <<
    "Given a MyVector with capacity 5 and size 5: {1, 2, 3, 4, 5}\n"
    "When I `pop_back`\n"
    "Then the size should be 4\n"
    "And the capacity should be 5\n"
    "And the back should be 4\n"
    << std::endl;
    {
        MyVector vector;
        FakeVector* fv = reinterpret_cast<FakeVector*>(&vector);
        fv->array_ = new int[5] {1, 2, 3, 4, 5};
        fv->capacity_ = 5;
        fv->size_ = 5;

        vector.pop_back();

        assert(vector.size() == 4);
        assert(vector.capacity() == 5);
        assert(vector.back() == 4);
    }

    std::cout << __func__ << " : all tests passing\n" << std::endl;
}

void test_push_back() {
    std::cout <<
    "Given an empty MyVector\n"
    "When I push_back 7\n"
    "Then the capacity should be at least 1\n"
    "And the size should be 1\n"
    "And the front should be 7\n"
    "And the back should be 7\n"
    "And the `array_` pointer should not be null\n"
    << std::endl;
    {
        MyVector vector;

        vector.push_back(7);

        assert(vector.capacity() >= 1);
        assert(vector.size() == 1);
        assert(vector.front() == 7);
        assert(vector.back() == 7);
        assert(vector.array() != nullptr);
    }

    std::cout <<
    "Given a MyVector with capacity 3 and size 2: {1, 2}\n"
    "When I push_back 3\n"
    "Then the capacity should be 3\n"
    "And the size should be 3\n"
    "And the front should be 1\n"
    "And the back should be 3\n"
    "And the `array_` pointer should be the same\n"
    << std::endl;
    {
        MyVector vector;
        FakeVector* fv = reinterpret_cast<FakeVector*>(&vector);
        fv->array_ = new int[3] {1, 2};
        fv->capacity_ = 3;
        fv->size_ = 2;

        const int* original_array = vector.array();

        vector.push_back(3);

        assert(vector.capacity() >= 3);
        assert(vector.size() == 3);
        assert(vector.front() == 1);
        assert(vector.back() == 3);
        assert(vector.array() == original_array);
    }

    std::cout <<
    "Given a MyVector with capacity 3 and size 3: {1, 2, 3}\n"
    "When I push_back 4\n"
    "Then the capacity should be at least 4\n"
    "And the size should be 4\n"
    "And the front should be 1\n"
    "And the back should be 4\n"
    "And the `array_` pointer should be different\n"
    << std::endl;
    {
        MyVector vector;
        FakeVector* fv = reinterpret_cast<FakeVector*>(&vector);
        fv->array_ = new int[3] {1, 2, 3};
        fv->capacity_ = 3;
        fv->size_ = 3;

        const int* original_array = vector.array();

        vector.push_back(4);

        assert(vector.capacity() >= 4);
        assert(vector.size() == 4);
        assert(vector.front() == 1);
        assert(vector.back() == 4);
        assert(vector.array() != original_array);
    }

    std::cout << __func__ << " : all tests passing\n" << std::endl;
}

void test_resize() {
    std::cout <<
    "Given an empty MyVector\n"
    "When I resize it to have capacity 7\n"
    "Then the capacity should be 7\n"
    "And the size should be 0\n"
    "And the `array_` pointer should be different\n"
    << std::endl;
    {
        MyVector vector;
        const int* original_array = vector.array();

        vector.resize(7);

        assert(vector.capacity() == 7);
        assert(vector.size() == 0);
        assert(vector.array() != original_array);
    }

    std::cout <<
    "Given a MyVector with capacity 3 and size 2: {6, 7}\n"
    "When I resize it to have capacity 12\n"
    "Then the capacity should be 12\n"
    "And the size should be 2\n"
    "And the front should be 6\n"
    "And the back should be 7\n"
    "And the `array_` pointer should be different\n"
    << std::endl;
    {
        MyVector vector;
        FakeVector* fv = reinterpret_cast<FakeVector*>(&vector);
        fv->array_ = new int[3] {6, 7};
        fv->capacity_ = 3;
        fv->size_ = 2;

        const int* original_array = vector.array();

        vector.resize(12);

        assert(vector.capacity() == 12);
        assert(vector.size() == 2);
        assert(vector.front() == 6);
        assert(vector.back() == 7);
        assert(vector.array() != original_array);
    }

    std::cout <<
    "Given a MyVector with capacity 30 and size 20: {1, 2,..., 20}\n"
    "When I resize it to have capacity 10\n"
    "Then the capacity should be 10\n"
    "And the size should be 10\n"
    "And the front should be 1\n"
    "And the back should be 10\n"
    "And the `array_` pointer should be different\n"
    << std::endl;
    {
        MyVector vector;
        FakeVector* fv = reinterpret_cast<FakeVector*>(&vector);
        fv->array_ = new int[30];
        for (int i = 1; i <= 20; i++) {
            fv->array_[i-1] = i;
        }
        fv->capacity_ = 30;
        fv->size_ = 20;

        const int* original_array = vector.array();

        vector.resize(10);

        assert(vector.capacity() == 10);
        assert(vector.size() == 10);
        assert(vector.front() == 1);
        assert(vector.back() == 10);
        assert(vector.array() != original_array);
    }

    std::cout <<
    "Given a MyVector with capacity 3 and size 2: {6, 7}\n"
    "When I resize it to have capacity 0\n"
    "Then the capacity should be 0\n"
    "And the size should be 0\n"
    "And the `array_` pointer should be null\n"
    << std::endl;
    {
        MyVector vector;
        FakeVector* fv = reinterpret_cast<FakeVector*>(&vector);
        fv->array_ = new int[3] {6, 7};
        fv->capacity_ = 3;
        fv->size_ = 2;

        vector.resize(0);

        assert(vector.capacity() == 0);
        assert(vector.size() == 0);
        assert(vector.array() == nullptr);
    }

    std::cout << __func__ << " : all tests passing\n" << std::endl;
}
