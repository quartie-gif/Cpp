

#include "FilterCriteria.h"

void FilterCriteria::add(std::function<bool(int)> fun)
{
    m_fun.push_back(fun);
}

int FilterCriteria::size() const {
    return m_fun.size();
}

const std::function<bool(int)>& FilterCriteria::get(int i) const {
    return m_fun.at(i);
}



