#include "Functors.h"

Functors::divisibleBy::divisibleBy(int i): m_number(i)
{

}

bool Functors::divisibleBy::operator()(int num) const {
    return (num % m_number) == 0;
}

Functors::greaterThan::greaterThan(int i): m_number(i)
{

}

bool Functors::greaterThan::operator()(int num) const {
    return num>m_number;
}
