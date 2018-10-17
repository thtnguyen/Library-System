#ifndef TV_H
#define TV_H

#include "thn9732_media.h"
#include <vector>

class TV_Show_Season : public Media
{
public:
	TV_Show_Season(string id, string cn, string t, string g, string ry, string p, vector<string> d, vector<string> la, string sn): Media(id,cn,t,g),release_year{ry},producer{p},directors{d},leading_actors{la},season_number{sn} {Media::type = "TV";};
	string get_season_num();
	string get_producer();
	virtual string to_string() const;
	void to_save_data(ofstream& ofs);
	friend ostream& operator<< (ostream& ost, const TV_Show_Season& tv_show);

private:
	string release_year;
	string producer;
	vector<string> directors;
	vector<string> leading_actors;
	string season_number;
};

#endif
