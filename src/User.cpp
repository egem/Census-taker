/*
 * User.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: Ahmet Ege Mahlec
 */

#include "User.h"

User::User(Person person, std::string username, std::string password)
: Person(person), m_Username(username), m_Password(password)
{

}


std::string User::getPassword() const
{
    return m_Password;
}

User& User::setPassword(std::string password)
{
    m_Password = password;

    return *this;
}

std::string User::getUsername() const
{
    return m_Username;
}

User& User::setUsername(std::string username)
{
    m_Username = username;

    return *this;
}
