/*
 * UserManager.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: Ahmet Ege Mahlec
 */

#include "UserManager.h"


UserManager::UserManager(UserDBRepository& dbInstance)
:m_dbInstance(dbInstance)
{

}

UserManager::Status UserManager::convertDBStatus(UserDBRepository::Status dbStatus)
{
    switch(dbStatus)
    {
        case UserDBRepository::Status::Success:
        {
            return Status::Success;
        }
        break;
        case UserDBRepository::Status::UserNotFound:
        {
            return Status::UserNotFound;
        }
        break;
        case UserDBRepository::Status::AlreadyDefinedUser:
        {
            return Status::AlreadyDefinedUser;
        }
        break;
        default:
        {
            return Status::UndefinedError;
        }
        break;
    }

}

UserManager::Status UserManager::checkUsername(const std::string& username)
{
    // TODO: Implement later. Protect against SQL injection.
    return Status::Success;
}

UserManager::Status UserManager::checkPassword(const std::string& password)
{
    // TODO: Implement later. Protect against SQL injection.
    return Status::Success;
}

UserManager::Status UserManager::login(std::string username, std::string password)
{
    std::string userPassword;
    UserDBRepository::Status dbStatus;
    Status status;

    status = checkUsername(username);

    if(Status::Success != status)
        return status;

    status = checkPassword(password);

    if(Status::Success != status)
        return status;

    dbStatus = m_dbInstance.getUserPassword(username, userPassword);

    if(UserDBRepository::Status::Success == dbStatus)
    {
        if(userPassword == password)
        {
            return Status::Success;
        }
        else
        {
            return Status::WrondPassword;
        }
    }
    else
    {
        return convertDBStatus(dbStatus);
    }

}

UserManager::Status UserManager::signup(User& newUser)
{
    UserDBRepository::Status dbStatus;
    Status status;

    status = checkUsername(newUser.getUsername());

    if(Status::Success != status)
        return status;

    status = checkPassword(newUser.getPassword());

    if(Status::Success != status)
        return status;

    dbStatus = m_dbInstance.setUser(newUser.getUsername(), newUser);

    return convertDBStatus(dbStatus);
}
