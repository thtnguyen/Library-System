#include "thn9732_Librarian.h"
#include <sstream>
#include <iterator>
#include <fstream>

string Librarian::get_id()
{
	return id;
}

string Librarian::to_string() const
{
	return id+" - "+this->name;
}

ostream& operator<< (ostream& ost, const Librarian& lbrn)
{
	ost << lbrn.to_string();
	return ost;
}

Librarian& Librarian::operator= (const Librarian &rhs)
{
	if(this != &rhs)
	{
		name = rhs.name;
		id = rhs.id;	
	}
	return *this;
}

void Librarian::to_save_data(ofstream& ofs)
{
	ofs << name << endl;
	ofs << id << endl;
}
