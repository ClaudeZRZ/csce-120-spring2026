#ifndef TEST_HELPERS_H_
#define TEST_HELPERS_H_

#include <iostream>
#include <exception>
#include <iomanip>

#define start_tests \
unsigned tests_passed = 0;\
unsigned tests_failed = 0;

#define end_tests \
std::cout << "\n";\
std::cout << "in " << __func__ << ":\n";\
std::cout << std::setw(2) << tests_passed << " tests passed\n";\
std::cout << std::setw(2) << tests_failed << " tests failed\n";\
std::cout << "\n";\
if (tests_failed) {\
    std::cout << "some tests failed\n";\
} else {\
    std::cout << "all tests passing\n";\
}\
std::cout << std::endl;\

#define expect_equal(actual, expected) try {\
    auto actual_value = actual;\
    auto expected_value = expected;\
    if (!(actual_value == expected_value)) {\
        std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
        std::cout << "Expected " << #actual << " == " << #expected << "\n";\
        std::cout << "     Got " << actual_value << " != " << expected_value << std::endl;\
        tests_failed++;\
    } else {\
        std::cout << "[PASS] " << #actual << " == " << #expected << std::endl;\
        tests_passed++;\
    }\
} catch (const std::exception& err) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected exception, what: " << err.what()<< std::endl;\
    tests_failed++;\
} catch (...) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected non-std::exception" << std::endl;\
    tests_failed++;\
}

#define expect_not_equal(actual, expected) try {\
    auto actual_value = actual;\
    auto expected_value = expected;\
    if (actual_value == expected_value) {\
        std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
        std::cout << "Expected " << #actual << " != " << #expected << "\n";\
        std::cout << "     Got " << actual_value << " == " << expected_value << std::endl;\
        tests_failed++;\
    } else {\
        std::cout << "[PASS] " << #actual << " != " << #expected << std::endl;\
        tests_passed++;\
    }\
} catch (const std::exception& err) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected exception, what: " << err.what()<< std::endl;\
    tests_failed++;\
} catch (...) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected non-std::exception" << std::endl;\
    tests_failed++;\
}

#define expect_between(actual, expected_lower, expected_upper) try {\
    unsigned actual_value = actual;\
    unsigned expected_lower_value = expected_lower;\
    unsigned expected_upper_value = expected_upper;\
    if (!(actual_value >= expected_lower_value)) {\
        std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
        std::cout << "Expected " << #expected_lower << " <= " << #actual << "\n";\
        std::cout << "     Got " << expected_lower_value << " > " <<  actual_value << std::endl;\
        tests_failed++;\
    } else if (!(actual_value <= expected_upper_value)) {\
        std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
        std::cout << "Expected " << #actual << " <= " << #expected_upper << "\n";\
        std::cout << "     Got " << actual_value << " > " << expected_upper_value << std::endl;\
        tests_failed++;\
    } else {\
        std::cout << "[PASS] " << #expected_lower << " <= " << #actual << " <= " << #expected_upper << std::endl;\
        tests_passed++;\
    }\
} catch (const std::exception& err) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected exception, what: " << err.what()<< std::endl;\
    tests_failed++;\
} catch (...) {\
    std::cout << "[FAIL] " << __func__ << ":" <<__LINE__ << "\n";\
    std::cout << "unexpected non-std::exception" << std::endl;\
    tests_failed++;\
}

#define expect_throw(expression) try{\
    expression;\
    std::cout << "[FAIL] " << __func__ << ":" << __LINE__ << "\n";\
    std::cout << "expected " << #expression << " to throw an exception, but nothing thrown" << std::endl;\
    tests_failed++;\
} catch (...) {\
    std::cout << "[PASS] " << #expression << " threw an exception" << std::endl;\
    tests_passed++;\
}

#endif  // TEST_HELPERS_H_
