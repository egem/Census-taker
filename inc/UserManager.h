/*
 * UserManager.h
 *
 *  Created on: Mar 5, 2019
 *      Author: Ahmet Ege Mahlec
 */

#ifndef INC_USERMANAGER_H_
#define INC_USERMANAGER_H_


#include <iostream>
#include <cstring>

#include "User.h"
#include "UserDBRepository.h"

class UserManager
{
public:
    enum class Status
    {
        Success,
        InputError,
        UserNotFound,
        AlreadyDefinedUser,
        UsernameHasInvalidCharacter,
        WeakPasswordError,
        WrondPassword,
        PasswordHasInvalidCharacter,
        UndefinedError
    };

private:
    UserDBRepository& m_dbInstance;

    Status convertDBStatus(UserDBRepository::Status dbStatus);

    Status checkUsername(const std::string& username);
    Status checkPassword(const std::string& password);

public:
    UserManager(UserDBRepository& dbInstance);

    Status login(std::string username, std::string password);
    Status signup(User& newUser);

};



#endif /* INC_USERMANAGER_H_ */
