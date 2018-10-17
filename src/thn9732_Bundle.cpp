#include "thn9732_Bundle.h"
#include <iterator>
#include <sstream>
#include <iomanip>

string Bundle::to_string() const
{
	stringstream ss;
	string info;
	ss << name << " - " << setw(5) << setfill('0') << id;
	getline(ss, info);
	if(checked_out)
		return info+" - NOT AVAILABLE";
	else
		return info+ " - AVAILABLE";
}


bool Bundle::is_available()
{
	if(checked_out)
		return false;
	else
		return true;
}

string Bundle::get_id()
{
	return id;
}

string Bundle::get_name()
{
	return name;
}

void Bundle::to_save_data(ofstream& ofs)
{
	ofs << name << endl;
	ofs << id << endl;
	for(shared_ptr<Media> m : medias)
		m->to_save_data(ofs);
	ofs << "END MEDIA" << endl;
	if(checked_out)
		ofs << "0" << endl;
	else
		ofs << "1" << endl;

}

