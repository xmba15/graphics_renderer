/**
 * @file    TestDataContainer.cpp
 *
 * @brief   Test Datacontainer
 *
 * @author  btran
 *
 * @date    2019-05-26
 *
 * Copyright (c) organization
 *
 */

#include "DataContainer.hpp"
#include "gtest/gtest.h"
#include <time.h>

class TestDataContainer : public ::testing::Test
{
 protected:
    void SetUp() override
    {
        start_time_ = time(nullptr);
    }

    void TearDown() override
    {
        const time_t end_time = time(nullptr);

        // expect test time less than 5 sec
        EXPECT_LE(end_time - start_time_, 5);
    }

    time_t start_time_;

    using Vec4d = graphics::DataContainer<double, 4>;
};

TEST_F(TestDataContainer, TestInitialization)
{
    double data[] = {1, 2, 3, 4};
    Vec4d v(data);
    EXPECT_EQ(v.size(), 4);

    auto it = v.begin();
    EXPECT_EQ(*it, 1);
    it += 4;

    EXPECT_EQ(it, v.end());
}

TEST_F(TestDataContainer, TestArithmeticOperators)
{
    double data1[] = {1, 2, 3, 4};
    double data2[] = {-1, -2, 3, 4};
    double dataSum[] = {0, 0, 6, 8};

    Vec4d v1(data1), v2(data2), vSum(dataSum);

    {
        EXPECT_EQ(vSum, v1 + v2);
    }

    {
        vSum /= 2;
        double expected[] = {0, 0, 3, 4};

        EXPECT_EQ(vSum, Vec4d(expected));

        double norm = vSum.l2norm();

        EXPECT_EQ(norm, 5);
    }
}
