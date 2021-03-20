# include "List.h"

void List::insert(int x)
{
    m_list.push_back(x);
}
void List::print(const char* text) const
{
    std::cout<< text << "[";
    for(auto i : m_list)
    {
        std::cout << " " << i;
    }
    std::cout << "]" << std::endl;
}

int& List::operator [] (int index)
{
    return m_list.at(index);
}

List List::filter(const std::function<bool(int)>& fun) {

    List temp;
    for(auto i : m_list)
    {
        if(fun(i))
        {
            temp.m_list.push_back(i);
        }
    }
    return temp;
}
