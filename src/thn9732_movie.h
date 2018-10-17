#ifndef MOVIE_H
#define MOVIE_H

#include "thn9732_media.h"
#include <vector>
#include <sstream>

class Movie : public Media
{
public:
	Movie(string id, string cn, string t, string g, string ry, string p, string d, vector<string> la): Media(id,cn,t,g), release_year{ry}, producer{p}, director{d}, leading_actors{la} {Media::type = "Movie";};
	string get_director();
	virtual string to_string() const;
	void to_save_data (ofstream& ofs);
	friend ostream& operator<< (ostream& ost, const Movie& movie);

private:
	string release_year;
	string producer;
	string director;
	vector<string> leading_actors;
};

#endif
