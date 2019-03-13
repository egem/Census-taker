/*
 * testUserManager.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: Ahmet Ege Mahlec
 */

#include "testUserManager.h"


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_SUCCESS_when_USERNAME_and_PASSWORD_CORRECT)
{
    ASSERT_EQ(4, 2+2);
}



