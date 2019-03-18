/*
 * UserDBRepositoryStub.h
 *
 *  Created on: Mar 8, 2019
 *      Author: Ahmet Ege Mahlec
 */

#ifndef TEST_UNIT_INC_USERDBREPOSITORYSTUB_H_
#define TEST_UNIT_INC_USERDBREPOSITORYSTUB_H_

#include <cstring>
#include <vector>

#include "UserDBRepository.h"

class UserDBRepositoryStub : public UserDBRepository
{
public:
    std::vector<User> m_Users;

    UserDBRepositoryStub() = default;

    UserDBRepositoryStub(std::vector<User> users) : m_Users(users){}

    bool isUserExist(std::string username) const
    {
        for(User const& user : m_Users)
        {
            if(user.getUsername() == username)
                return true;
        }

        return false;
    }

    Status getUser(std::string username, User& userFound) const
    {
        for(User const& user : m_Users)
        {
            if(user.getUsername() == username)
            {
                userFound = user;
                return Status::Success;
            }
        }

        return Status::UserNotFound;
    }

    User getUser(std::string username) const noexcept(false)
    {
        for(User const& user : m_Users)
        {
            if(user.getUsername() == username)
            {
                return user;
            }
        }

        throw UserNotFound();
    }

    Status setUser(User const& user)
    {
        if(true == isUserExist(user.getUsername()))
            return Status::AlreadyDefinedUser;

        m_Users.push_back(user);
        return Status::Success;
    }

    Status getUserPassword(std::string username, std::string& password) const
    {
        for(User const& user : m_Users)
        {
            if(user.getUsername() == username)
            {
                password = user.getPassword();
                return Status::Success;
            }
        }

        return Status::UserNotFound;
    }

    std::string getUserPassword(std::string username) const noexcept(false)
    {
        for(User const& user : m_Users)
        {
            if(user.getUsername() == username)
                return user.getPassword();
        }

        throw UserNotFound();
    }

    Status setUserPassword(std::string username, std::string password)
    {
        for(User& user : m_Users)
        {
            if(user.getUsername() == username)
            {
                user.setPassword(password);
                return Status::Success;
            }
        }

        return Status::UserNotFound;
    }

};



#endif /* TEST_UNIT_INC_USERDBREPOSITORYSTUB_H_ */
