#include <rna.h>


RNA & RNA::mutate ()
{
	
}


std::ostream& operator<<(std::ostream& out, const RNA & seq_)
{
	for(auto &i: seq_.chain)
	{
		out << i << " ";
	}
	return out;
}