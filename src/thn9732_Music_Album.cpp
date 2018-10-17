#include "thn9732_Music_Album.h"
#include <sstream>
#include <iomanip>

string Music_Album::get_release_year()
{
	return release_year;
}

string Music_Album::get_artist()
{
	return artist;
}

string Music_Album::to_string() const
{
	stringstream ss;
	string id;
	ss << setw(5) << setfill('0') << id_number;
	getline(ss, id);
	return id+" - "+this->call_number+" - "+this->title+" - "+this->artist+" - "+this->release_year;
}

ostream& operator<< (ostream& ost, const Music_Album& album)
{
	ost << album.to_string();
	return ost;
}

void Music_Album::to_save_data(ofstream& ofs)
{
	ofs << type << endl;
	ofs << id_number << endl;
	ofs << call_number << endl;
	ofs << title << endl;
	ofs << genre << endl;
	ofs << release_year << endl;
	ofs << artist << endl;
	ofs << "Tracks" << endl;
	for(string name : tracks)
		ofs << name << endl;
	ofs << ";" << endl;
	if(checked_out)
		ofs << "0" << endl;
	else
		ofs << "1" << endl;
}
