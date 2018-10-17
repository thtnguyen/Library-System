#ifndef LIBRARY_H
#define LIBRARY_H

#include <memory>
#include "thn9732_media.h"
#include "thn9732_book.h"
#include "thn9732_movie.h"
#include "thn9732_TV_Show.h"
#include "thn9732_Video_Game.h"
#include "thn9732_Music_Album.h"
#include "thn9732_Bundle.h"
#include "thn9732_Librarian.h"
#include "thn9732_Customer.h"
#include "thn9732_Transaction.h"
#include "thn9732_gui.h"

class Library
{
public:
	/*~Library()
	{
		vector<Media*>::iterator it = medias.begin();
		for(;it != medias.end();it++)
			delete (&(*it));
	};*/
	void create_new_media();
	void create_new_bundle();
	void create_new_librarian();
	void create_new_customer();
	void create_new_transaction();
	void save(string file_name);
	void load(string file_name);
	void default_save();
	void default_load();
	void print_catalog();
	void load_media(ifstream& ifs, string delimiter, vector<shared_ptr<Media>>& list);

private:
	vector<shared_ptr<Media>> medias;
	vector<Transaction> transactions;
	vector<Customer> customers;
	vector<Librarian> librarians;
	vector<Bundle> bundles;
	friend class Controller;
	friend class gui;

};

#endif
