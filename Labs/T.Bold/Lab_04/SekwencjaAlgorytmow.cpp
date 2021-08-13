#include "SekwencjaAlgorytmow.h"

void SekwencjaAlgorytmow::add(std::function<Argumenty(const Argumenty&)> fun)
{
    _algo.push_back(fun);
}

Argumenty SekwencjaAlgorytmow::procesuj(const Argumenty& args)
{
    Argumenty ret = args;
    for(auto it: _algo)
    {
        ret = it(ret);
    }
    return ret;
}

