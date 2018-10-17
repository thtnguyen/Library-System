#ifndef BUNDLE_H
#define BUNDLE_H

#include "thn9732_media.h"
#include <vector>
#include <memory>

using namespace std;

class Bundle
{
public:
	Bundle(string n, string i): name{n}, id{i}, checked_out{false} {};
	Bundle(string n, string i, vector<shared_ptr<Media>> m, bool status): name(n), id(i), medias(m), checked_out(status) {};
	bool is_available();
	string get_id();
	string get_name();
	void to_save_data(ofstream& ofs);
	string to_string() const;

private:
	friend class Library;
	friend class Controller;
	friend class gui;
	string name, id;
	vector<shared_ptr<Media>> medias;
	bool checked_out;
};

#endif
