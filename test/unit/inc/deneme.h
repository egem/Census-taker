/*
 * deneme.h
 *
 *  Created on: Mar 8, 2019
 *      Author: Ahmet Ege Mahlec
 */

#ifndef TEST_UNIT_INC_DENEME_H_
#define TEST_UNIT_INC_DENEME_H_


class Deneme : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    Deneme() :
        m_ClassName("LinkedList<T>"),
        m_FunctionName("bool insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;
    }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};


#endif /* TEST_UNIT_INC_DENEME_H_ */
