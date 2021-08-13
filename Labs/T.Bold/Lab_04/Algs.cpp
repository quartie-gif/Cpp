#include "Algs.h"

Argumenty minimum(const Argumenty & args)
{
    double min = args[0];
    for (size_t i = 0; i<args.getSize(); ++i)
    {
        if (min > args[i])
            min = args[i];
    }

    return Argumenty::pojedynczy(min);
}

Argumenty sum (const Argumenty & args)
{
    double sum = 0;

    for(size_t i = 0; i<args.getSize(); ++i)
    {
        sum += args[i];
    }
    return Argumenty::pojedynczy(sum); 
}

Argumenty sq (const Argumenty & args)
{
    Argumenty ret(args.getSize());
    for (int i = 0; i < ret.getSize(); ++i)
    {
        ret(i,sqrt(args[i]));
    }
    return ret;
}