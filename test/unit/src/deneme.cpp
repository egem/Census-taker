/*
 * deneme.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: Ahmet Ege Mahlec
 */


#include "UserManager.h"
#include "gtest/gtest.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(mysuite, mytest)
{
    ASSERT_EQ(4, 2+2);
}
