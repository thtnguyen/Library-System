#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Media{
public:
	Media(string id, string cn, string t, string g): id_number{id}, call_number{cn}, title{t}, genre{g}, checked_out{false}, type{"Media"} {};
	string get_id();
	string get_title();
	string get_call_num();
	virtual string to_string() const = 0;
	bool is_available();
	virtual void to_save_data(ofstream& ofs);

protected:
	friend class Library;
	friend class Controller;
	string type;
	string id_number;
	string call_number;
	string title;
	string genre;
	bool checked_out;
};

#endif
