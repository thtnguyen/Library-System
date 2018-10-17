#include "thn9732_TV_Show.h"
#include <sstream>
#include <iomanip>

string TV_Show_Season::get_season_num()
{
	return season_number;
}

string TV_Show_Season::get_producer()
{
	return producer;
}

string TV_Show_Season::to_string() const
{
	stringstream ss;
	string id;
	ss << setw(5) << setfill('0') << id_number;
	getline(ss, id);
	return id+" - "+this->call_number+" - "+this->title+" - Season "+this->season_number+" - "+this->producer;
}

ostream& operator<< (ostream& ost, const TV_Show_Season& tv_show)
{
	ost << tv_show.to_string();
	return ost;
}

void TV_Show_Season::to_save_data(ofstream& ofs)
{
	ofs << type << endl;
	ofs << id_number << endl;
	ofs << call_number << endl;
	ofs << title << endl;
	ofs << genre << endl;
	ofs << release_year << endl;
	ofs << producer << endl;
	ofs << season_number << endl;
	for(string name : directors)
		ofs << name << endl;
	ofs << "Actors" << endl;
	for(string name : leading_actors)
		ofs << name << endl;
	ofs << ";" << endl;
	if(checked_out)
		ofs << "0" << endl;
	else
		ofs << "1" << endl;
}
