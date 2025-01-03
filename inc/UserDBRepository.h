/*
 * IDatabaseManager.h
 *
 *  Created on: Mar 5, 2019
 *      Author: Ahmet Ege Mahlec
 */

#ifndef INC_USERDBREPOSITORY_H_
#define INC_USERDBREPOSITORY_H_

#include <exception>

#include "User.h"

class UserDBRepository
{
public:
    enum class Status
    {
        Success,
        UserNotFound,
        AlreadyDefinedUser
    };

    class UserNotFound : public std::exception
    {
        char const* what () const throw ()
        {
            return "User not found";
        }
    };

    virtual ~UserDBRepository() = default;

    virtual bool isUserExist(std::string username) const = 0;

    virtual Status getUser(std::string username, User& userFound) const = 0;
    virtual User getUser(std::string username) const noexcept(false) = 0;

    virtual Status setUser(User const& newUser) = 0;

    virtual Status getUserPassword(std::string username, std::string& password) const = 0;
    virtual std::string getUserPassword(std::string username) const noexcept(false) = 0;

    virtual Status setUserPassword(std::string username, std::string password) = 0;

};

#endif /* INC_USERDBREPOSITORY_H_ */
