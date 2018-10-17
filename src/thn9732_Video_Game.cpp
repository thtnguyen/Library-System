#include "thn9732_Video_Game.h"
#include <sstream>
#include <iomanip>

string Video_Game::get_release_year()
{
	return release_year;
}

string Video_Game::get_studio()
{
	return studio;
}

string Video_Game::to_string() const
{
	stringstream ss;
	string id;
	ss << setw(5) << setfill('0') << id_number;
	getline(ss, id);
	return id+" - "+this->call_number+" - "+this->title+" - "+this->release_year+" - "+this->studio;
}

ostream& operator<< (ostream& ost, const Video_Game& vg)
{
	ost << vg.to_string();
	return ost;
}

void Video_Game::to_save_data(ofstream& ofs)
{
	ofs << type << endl;
	ofs << id_number << endl;
	ofs << call_number << endl;
	ofs << title << endl;
	ofs << genre << endl;
	ofs << release_year << endl;
	ofs << studio << endl;
	if(checked_out)
		ofs << "0" << endl;
	else
		ofs << "1" << endl;
}
