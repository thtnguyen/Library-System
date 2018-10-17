#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "thn9732_media.h"
#include "thn9732_Customer.h"
#include "thn9732_Bundle.h"

class Librarian
{
public:
	Librarian(string n, string id): name{n}, id{id} {};
	Librarian(): Librarian("name", "999") {};
	void to_save_data(ofstream& ofs);
	string get_id();
	string to_string() const;
	friend ostream& operator<< (ostream& ost, const Librarian& lbrn);
	Librarian& operator= (const Librarian &rhs);

private:
	string name;
	string id;
};

#endif
