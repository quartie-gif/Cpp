#include "File.h"

File *File::get(std::string s)
{
    if(_name==s) return this;
    else return nullptr;
}

void File::print(std::ostream &out) const
{
    for(size_t i=0;i<_spaces;i++) {
        out<<" ";
    }
    out << _name <<" (FILE)\n";
}
