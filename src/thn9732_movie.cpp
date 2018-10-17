#include "thn9732_movie.h"
#include <iomanip>

string Movie::get_director()
{
	return director;
}

string Movie::to_string() const
{
	stringstream ss;
	string id;
	ss << setw(5) << setfill('0') << id_number;
	getline(ss,id);
	return id+" - "+this->call_number+" - "+this->title+" - "+this->director;
}

ostream& operator<< (ostream& ost, const Movie& movie)
{
	ost << movie.to_string();
	return ost;
}

void Movie::to_save_data(ofstream& ofs)
{
	ofs << type << endl;
	ofs << id_number << endl;
	ofs << call_number << endl;
	ofs << title << endl;
	ofs << genre << endl;
	ofs << release_year << endl;
	ofs << producer << endl;
	ofs << director << endl;
	for(string name : leading_actors)
		ofs << name << endl;
	ofs << ";" << endl;
	if(checked_out)
		ofs << "0" << endl;
	else
		ofs << "1" << endl;
}
