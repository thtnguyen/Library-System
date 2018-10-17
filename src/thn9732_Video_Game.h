#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H

#include "thn9732_media.h"

class Video_Game : public Media
{
public:
	Video_Game(string id, string cn, string t, string g, string ry, string st): Media(id,cn,t,g), release_year{ry}, studio{st} {Media::type = "Game";};
	string get_release_year();
	string get_studio();
	virtual string to_string () const;
	void to_save_data(ofstream& ofs);
	friend ostream& operator<< (ostream& ost, const Video_Game& vg);

private:
	string release_year;
	string studio;
};

#endif
