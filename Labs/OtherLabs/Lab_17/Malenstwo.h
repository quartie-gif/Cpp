#pragma once

#include <iostream>



struct Malenstwo
{
    Malenstwo(int val): _val(val)
    {

    }    

    int& wartosc()
    {
        return _val;
    }

    void * operator new (size_t size)
    {
        void *ptr = (void *)malloc(100*sizeof(Malenstwo));
        return ptr;
    }
    
    void operator delete(void* ptr)
    {
        
    }

    int _val;
};

struct MalenstwoSamoSprzatacz
{
    MalenstwoSamoSprzatacz(Malenstwo)
    {

    }

    MalenstwoSamoSprzatacz* operator -> ()
    {
        return this;
    }

    

};