#include "test_helpers.h"

#include "coin.h"

int main() {
    start_tests

    Coin coin;
    expect_between(coin.value(), TAILS, HEADS);

    // when not flipped, value should not change
    unsigned value = coin.value();
    expect_equal(coin.value(), value);
    expect_equal(coin.value(), value);
    expect_equal(coin.value(), value);

    // when flipped, value should change
    unsigned heads = 0;
    unsigned tails = 0;
    for (int i = 0; i < 1000; i++) {
        coin.flip();
        switch (coin.value()) {
            case HEADS:
                heads++;
                break;
            case TAILS:
                tails++;
                break;
        }
    }
    expect_equal(heads + tails, 1000);
    expect_between(heads, 1, 999);
    expect_between(tails, 1, 999);

    end_tests

    return 0;
}
