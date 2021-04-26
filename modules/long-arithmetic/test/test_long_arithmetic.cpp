// Copyright 2021 Chistov Vladimir

#include <gtest/gtest.h>
#include "include/long_arithmetic.h"


TEST(Chistov_long_arithmetic, Constructor) {
    bigInt bi;
    bigInt bi2("123456789");
    bigInt bi3(123456789);
    ASSERT_EQ(0, bi);
    ASSERT_EQ(bi3, bi2);
}



TEST(Chistov_long_arithmetic, Compare) {
    bigInt bi("2");
    bi = bi.pow(1000);
    bigInt f = 1;
    bigInt bi2 = bi;
    for (bigInt i = 2; i <= bigInt(100); ++i) f *= i;

    ASSERT_TRUE(f != bi);
    ASSERT_TRUE(f <= bi);
    ASSERT_TRUE(f < bi);
    ASSERT_TRUE(bi >= f);
    ASSERT_TRUE(bi > f);
    ASSERT_TRUE(bi2 <= bi);
    ASSERT_TRUE(bi2 >= bi);
    ASSERT_TRUE(bi2 == bi);
}

TEST(Chistov_long_arithmetic, Addition_Subtractoin) {
    bigInt bi("10000000000000"), bi2, bi3, bi4("20000000000000"),
        bi5("000123456789");
    bi3 = bi;
    bi3 += bi5;
    bi2 = bi3;
    bi2 -= bi5;
    ASSERT_EQ(bi + bi2, bi4);
    ASSERT_EQ(bi3 - bi2, bi5);
    ASSERT_EQ(bi++, bi2);
    ASSERT_EQ(bi, bi2 + 1);
    ASSERT_EQ(bi--, bi2 + 1);
    ASSERT_EQ(bi, bi2);
    ASSERT_EQ(++bi2, bi2 + 1);
    ASSERT_EQ(--bi2, bi2 - 1);
    ASSERT_EQ(+bi, bi);
    ASSERT_EQ(-bi, 0 - bi);
}

TEST(Chistov_long_arithmetic, Multiplication_Division) {
    bigInt bi("10000000000000"), bi2, bi3, bi4("20000000000000"),
        bi5("000123456789"), bi6, bi7, bi8;
    bi3 = bi;
    bi3 += bi5;
    bi2 = bi3;
    bi2 -= bi5;
    bi6 = bi5;
    bi6 *= bi3;
    bi7 = bi6;
    bi7 /= bi3;
    bi8 = 10;
    ASSERT_EQ(bi * 2, bi4);
    ASSERT_EQ(bi4 / 2, bi);
    ASSERT_EQ(bi3 * bi5, bi6);
    ASSERT_EQ(bi6 / bi3, bi7);
    ASSERT_EQ(bi3 % bi2, bi5);
    ASSERT_EQ(bi8.pow(13), bi2);
}

TEST(Chistov_long_arithmetic, Logic) {
    bigInt bi("1234567891112131415"), bi2, bi3;
    bi2 = bi - 1;
    bi3 = -bi;
    ASSERT_TRUE(bi.odd());
    ASSERT_TRUE(bi2.even());
    ASSERT_ANY_THROW(bi / 0);
}
