#pragma once

#include<string>
#include<iostream>
#include<QString>

class Person
{
public:
    //Constructor
    Person(const QString& name, const QString& surname, const QString& phonenumber,const QString& country, bool isWoman):
        m_name(name),
        m_surname(surname),
        m_phonenumber(phonenumber),
         m_country(country),
        m_isWoman(isWoman)
    {}

    //Destructor

    ~Person() {}

    //Setters

    //Getters

    QString data() const
    {
        return m_name + " " + m_surname  + " " + m_phonenumber + " " + m_country + (!m_isWoman?"(Man) ":"(Woman) ") + "\n";
    }
private:
    QString m_name, m_surname, m_phonenumber, m_country;
    bool m_isWoman;
};



