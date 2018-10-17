#ifndef BOOK_H
#define BOOK_H

#include "thn9732_media.h"

class Book : public Media
{
public:
	Book(string id, string cn, string t, string g, string a, string cy): Media(id,cn,t,g), author{a}, copyright_year{cy} {Media::type = "Book";};
	string get_author();
	virtual string to_string() const;
	void to_save_data(ofstream& ofs);
	friend ostream& operator<< (ostream& ost, const Book& book);

private:
	string author;
	string copyright_year;
};

#endif
