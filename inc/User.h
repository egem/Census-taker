/*
 * User.h
 *
 *  Created on: Mar 5, 2019
 *      Author: Ahmet Ege Mahlec
 */

#ifndef INC_USER_H_
#define INC_USER_H_

#include <iostream>
#include <cstring>

#include "Person.h"

class User : public Person
{
private:
    std::string m_Username;
    std::string m_Password;

public:
    User() = default;
    User(Person person, std::string username, std::string password);
    virtual ~User() = default;

    std::string getPassword() const;
    User& setPassword(std::string password);

    std::string getUsername() const;
    User& setUsername(std::string username);
};


#endif /* INC_USER_H_ */
