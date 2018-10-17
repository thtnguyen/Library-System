#ifndef ALBUM_H
#define ALBUM_H

#include "thn9732_media.h"
#include <vector>

class Music_Album : public Media
{
public:
	Music_Album(string id, string cn, string t, string g, string ry, string ar, vector<string> tr): Media(id,cn,t,g), release_year{ry}, artist{ar}, tracks{tr} {Media::type = "Album";};
	string get_artist();
	string get_release_year();	
	virtual string to_string() const;
	void to_save_data(ofstream& ofs);
	friend ostream& operator<< (ostream& ost, const Music_Album& album);

private:
	string release_year;
	string artist;
	vector<string> tracks;
};

#endif
