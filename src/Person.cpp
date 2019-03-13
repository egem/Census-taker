/*
 * Person.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: Ahmet Ege Mahlec
 */

#include "Person.h"

Person::Person(std::string name, std::string surname)
: m_Name(name), m_Surname(surname), m_Birthdate(0)
{

}

std::string Person::getName() const
{
    return m_Name;
}

void Person::setName(std::string name)
{
    m_Name = name;
}

std::string Person::getSurname() const
{
    return m_Surname;
}

void Person::setSurname(std::string surname)
{
    m_Surname = surname;
}

std::time_t Person::getBirthdate()
{
    return m_Birthdate;
}

void Person::setBirthdate(std::time_t birthdate)
{
    m_Birthdate = birthdate;
}

