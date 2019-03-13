/*
 * testUserManager.h
 *
 *  Created on: Mar 8, 2019
 *      Author: Ahmet Ege Mahlec
 */

#ifndef TEST_UNIT_INC_TESTUSERMANAGER_H_
#define TEST_UNIT_INC_TESTUSERMANAGER_H_

#include <memory>

#include "gtest/gtest.h"

#include "UserManager.h"
#include "UserDBRepositoryStub.h"
#include "User.h"

class Login_Input_UsernameString_and_PasswordString : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

    std::unique_ptr<UserManager> m_UserManager;
    UserManager* m_UserManager;
    UserDBRepository* m_UserDBRepository;

public:
    Login_Input_UsernameString_and_PasswordString() :
        m_ClassName("UserManager"),
        m_FunctionName("Status login(std::string username, std::string password)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;

        m_UserManager = nullptr;
        m_UserDBRepository = nullptr;
    }

    virtual void SetUp()
    {
        if(nullptr != m_UserManager || nullptr != m_UserDBRepository)
            ASSERT_TRUE(false) << "Check Tear Down Method";

        std::vector<User> users =   {   User(Person("name1", "surname1"), "username1", "password1"),
                                        User(Person("name2", "surname2"), "username2", "password2"),
                                        User(Person("name3", "surname3"), "username3", "password3")
                                    };

        m_UserDBRepository = new UserDBRepositoryStub(users);
        m_UserManager = new UserManager(*m_UserDBRepository);

    }

    virtual void TearDown()
    {
        if(nullptr != m_UserDBRepository)
        {
            delete m_UserDBRepository;
            m_UserDBRepository = nullptr;
        }
    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};



#endif /* TEST_UNIT_INC_TESTUSERMANAGER_H_ */
