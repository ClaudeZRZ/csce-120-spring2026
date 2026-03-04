#include "test_helpers.h"

#include "dice_cup.h"

int main() {
    start_tests

    DiceCup cup;
    expect_equal(cup.value(), 0);

    cup.add_dice({3, 6});
    cup.add_dice({2, 8});
    expect_between(cup.value(), 5, 34);

    cup.roll();
    expect_between(cup.value(), 5, 34);

    // when not rolled, value should not change
    unsigned value = cup.value();
    expect_equal(cup.value(), value);
    expect_equal(cup.value(), value);
    expect_equal(cup.value(), value);

    // when rolled, value should change
    // need a lot of rolls so rare rolls like 5 and 34 will show up
    unsigned count[35] = {0};
    for (int i = 0; i < 100000; i++) {
        cup.roll();
        count[cup.value()]++;
    }
    unsigned total = 0;
    for (int i = 5; i <= 34; i++) {
        total += count[i];
        std::cout << "count["<<i<<"]="<<count[i]<<std::endl;
        expect_between(count[i], 1, 99999);
    }
    expect_equal(total, 100000);

    end_tests

    return 0;
}
