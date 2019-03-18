/*
 * testUserManager.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: Ahmet Ege Mahlec
 */

#include <iostream>

#include "testUserManager.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_SUCCESS_when_USERNAME_and_PASSWORD_CORRECT)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::Success;
    UserManager::Status output;

    std::string username = m_RegisteredUsers[0].getUsername();
    std::string password = m_RegisteredUsers[0].getPassword();

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_INPUT_ERROR_when_USERNAME_EMPTY)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::InputError;
    UserManager::Status output;

    std::string username = "";
    std::string password = m_RegisteredUsers[0].getPassword();

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_INPUT_ERROR_when_USERNAME_HAS_SPACE)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::InputError;
    UserManager::Status output;

    std::string username = m_RegisteredUsers[0].getUsername();
    std::string password = m_RegisteredUsers[0].getPassword();

    username.insert(username.begin(), ' ');

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_INPUT_ERROR_when_PASSWORD_EMPTY)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::InputError;
    UserManager::Status output;

    std::string username = m_RegisteredUsers[0].getUsername();
    std::string password = "";

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_INPUT_ERROR_when_PASSWORD_HAS_SPACE)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::InputError;
    UserManager::Status output;

    std::string username = m_RegisteredUsers[0].getUsername();
    std::string password = m_RegisteredUsers[0].getPassword();

    password.insert(password.begin(), ' ');

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_USER_NOT_FOUND_when_USERNAME_ONE_CHARACTER_DIFFERENT)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::UserNotFound;
    UserManager::Status output;

    std::string username = m_RegisteredUsers[0].getUsername();
    std::string password = m_RegisteredUsers[0].getPassword();

    username[0] = username[0] == 'e' ? 'g' : 'e';

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_USER_NOT_FOUND_when_INPUT_USERNAME_CONTAIN_CORRECT_USERNAME)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::UserNotFound;
    UserManager::Status output;

    std::string username = m_RegisteredUsers[0].getUsername();
    std::string password = m_RegisteredUsers[0].getPassword();

    username.append(std::string("x"));

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_USER_NOT_FOUND_when_USER_UNREGISTERED)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::UserNotFound;
    UserManager::Status output;

    std::string username = m_UnregisteredUsers[0].getUsername();
    std::string password = m_UnregisteredUsers[0].getPassword();

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_WRONG_PASSWORD_when_PASSWORD_ONE_CHARACTER_DIFFERENT)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::WrongPassword;
    UserManager::Status output;

    std::string username = m_RegisteredUsers[0].getUsername();
    std::string password = m_RegisteredUsers[0].getPassword();

    password[0] = password[0] == 'e' ? 'g' : 'e';

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}

TEST_F(Login_Input_UsernameString_and_PasswordString, test_RETURN_WRONG_PASSWORD_when_INPUT_PASSWORD_CONTAIN_CORRECT_PASSWORD)
{
    /************************** Arrange **************************/
    UserManager::Status expectedOutput = UserManager::Status::WrongPassword;
    UserManager::Status output;

    std::string username = m_RegisteredUsers[0].getUsername();
    std::string password = m_RegisteredUsers[0].getPassword();

    password.append(std::string("x"));

    /************************** Act **************************/
    output = m_UserManager->login(username, password);

    /************************** Assert **************************/
    ASSERT_EQ(UserManager::getStatusMessage(expectedOutput), UserManager::getStatusMessage(output)) << TestInfo();
}



