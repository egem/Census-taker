/*
 * testUserManager.h
 *
 *  Created on: Mar 8, 2019
 *      Author: Ahmet Ege Mahlec
 */

#ifndef TEST_UNIT_INC_TESTUSERMANAGER_H_
#define TEST_UNIT_INC_TESTUSERMANAGER_H_

#include <memory>
#include <utility>

#include "gtest/gtest.h"

#include "UserManager.h"
#include "UserDBRepositoryStub.h"
#include "User.h"

class Login_Input_UsernameString_and_PasswordString : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    std::unique_ptr<UserManager> m_UserManager;
    std::unique_ptr<UserDBRepository> m_UserDBRepository;
    std::vector<User> m_RegisteredUsers;
    std::vector<User> m_UnregisteredUsers;


    Login_Input_UsernameString_and_PasswordString() :
        m_ClassName("UserManager"),
        m_FunctionName("Status login(std::string username, std::string password)"),
        m_RegisteredUsers(
                                {
                                    User(Person("registered_name1", "registered_surname1"), "registered_username1", "registered_password1"),
                                    User(Person("registered_name2", "registered_surname2"), "registered_username2", "registered_password2"),
                                    User(Person("registered_name3", "registered_surname3"), "registered_username3", "registered_password3")
                                }
                        ),
        m_UnregisteredUsers(
                                {
                                    User(Person("unregistered_name1", "unregistered_surname1"), "unregistered_username1", "unregistered_password1"),
                                    User(Person("unregistered_name2", "unregistered_surname2"), "unregistered_username2", "unregistered_password2"),
                                    User(Person("unregistered_name3", "unregistered_surname3"), "unregistered_username3", "unregistered_password3")
                                }
                            )
    {
        m_TestInfo          << "Class Name    : " << m_ClassName    << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;

    }

    virtual void SetUp()
    {
        if(m_UserManager || m_UserDBRepository)
            ASSERT_TRUE(false) << "Check Tear Down Method";

        std::unique_ptr<UserDBRepository> userDBRepository(new UserDBRepositoryStub(m_RegisteredUsers));
        std::unique_ptr<UserManager> userManager(new UserManager(*userDBRepository));

        m_UserDBRepository = std::move(userDBRepository);
        m_UserManager = std::move(userManager);

    }

    virtual void TearDown()
    {
        m_UserManager.release();
        m_UserDBRepository.release();
    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};



#endif /* TEST_UNIT_INC_TESTUSERMANAGER_H_ */
