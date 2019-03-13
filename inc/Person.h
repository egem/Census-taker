/*
 * Person.h
 *
 *  Created on: Mar 5, 2019
 *      Author: Ahmet Ege Mahlec
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <cstring>
#include <ctime>

class Person
{
private:
    /* Parameters */
    std::string m_Name;
    std::string m_Surname;

    /* Optional Parameters */
    std::time_t m_Birthdate;
public:
    Person(std::string name, std::string surname);
    virtual ~Person() = default;

    std::string getName() const;
    void setName(std::string name);

    std::string getSurname() const;
    void setSurname(std::string surname);

    std::time_t getBirthdate();
    void setBirthdate(std::time_t birthdate);
};


#endif /* PERSON_H_ */
