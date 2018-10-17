#include "thn9732_book.h"
#include <sstream>
#include <iomanip>

string Book::get_author()
{
	return author;
}

string Book::to_string() const
{
	stringstream ss;
	string id;
	ss << setw(5) << setfill('0') << id_number;
	getline(ss, id);
	return id+" - "+this->call_number+" - "+this->title+" - "+this->author;
}

void Book::to_save_data(ofstream& ofs)
{	
	ofs << type << endl;
	ofs << id_number << endl;
	ofs << call_number << endl;
	ofs << title << endl;
	ofs << genre << endl;
	ofs << author << endl;
	ofs << copyright_year << endl;
	if(checked_out)
		ofs << "0" << endl;
	else
		ofs << "1" << endl;
	
}

ostream& operator<< (ostream& ost, const Book& book)
{
	ost << book.to_string();
	return ost;
}
