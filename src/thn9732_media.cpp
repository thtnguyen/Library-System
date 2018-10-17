#include "thn9732_media.h"
#include <sstream>

string Media::get_id()
{
	return id_number;
}

string Media::get_title()
{
	return title;
}

string Media::get_call_num()
{
	return call_number;
}

bool Media::is_available()
{
	if(checked_out)
		return false;
	else
		return true;
}

void Media::to_save_data(ofstream& ofs)
{

}
