#include "Dir.h"


Dir::Dir(const std::string &s): File(std::move(s))
{

}

Dir::~Dir()
{   
    std::cout << "Deleting Dir: " << _name << std::endl;

    for( auto it: _files) 
    {
		delete it;
	}
}

void Dir::operator += (File *file)
{
    file->spaces(_spaces);
    _files.push_back(file);
}

void Dir::add(File *file)
{
   *this += file;
}

Dir * Dir::findDir(const std::string &s)
{
    return this;
}

void Dir::print(std::ostream &out) const
{
    for( size_t i = 0; i < _spaces; i++ )
	{
        out << " ";
    }

	out << getName() << " (DIR)" << "\n";

	for( auto it: _files) 
    {
		it->print(out);
	}

}

