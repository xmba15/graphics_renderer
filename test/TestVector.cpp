/**
 * @file    TestVector.hpp
 *
 * @brief   Test Vector
 *
 * @author  btran
 *
 * @date    2019-05-26
 *
 * Copyright (c) organization
 *
 */

#include "gtest/gtest.h"
#include <Vector.hpp>
#include <time.h>

class TestVector : public ::testing::Test
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

    using Vec3d = graphics::Vector<double, 3>;
};

TEST_F(TestVector, TestInitialization)
{
    double data[] = {1, 2, 3};
    Vec3d v(data);

    {
        EXPECT_EQ(v.size(), 3);

        auto it = v.begin();
        EXPECT_EQ(*it, 1);
        it += 3;

        EXPECT_EQ(it, v.end());
    }

    {
        EXPECT_EQ(v.x(), data[0]);
        EXPECT_EQ(v.y(), data[1]);
        EXPECT_EQ(v.z(), data[2]);
    }
}

TEST_F(TestVector, TestArithmeticOperators)
{
    double data1[] = {1, 2, 3};
    double data2[] = {-1, 2, 3};
    double dataSum[] = {0, 4, 6};

    Vec3d v1(data1), v2(data2), vSum(dataSum);

    {
        EXPECT_EQ(vSum, v1 + v2);
    }

    {
        vSum /= 2;
        double expectedArr[] = {0, 2, 3};

        EXPECT_EQ(vSum, Vec3d(expectedArr));

        double norm = vSum.l2norm();
        double expected = std::sqrt(2 * 2 + 3 * 3);

        EXPECT_EQ(norm, expected);
    }
}
