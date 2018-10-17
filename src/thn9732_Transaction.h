#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "thn9732_media.h"
#include "thn9732_book.h"
#include "thn9732_movie.h"
#include "thn9732_TV_Show.h"
#include "thn9732_Video_Game.h"
#include "thn9732_Music_Album.h"
#include "thn9732_Bundle.h"
#include "thn9732_Librarian.h"
#include "thn9732_Customer.h"
#include "thn9732_Date.h"
#include <vector>
#include <memory>

class Transaction
{
public:
	Transaction(string tn, Date co, Date ci, Librarian l, Customer c, vector<shared_ptr<Media>> m, vector<Bundle> b, Date d): transaction_number{tn}, check_out_date{co}, check_in_date{ci}, librarian{l}, customer{c}, media(m), bundles{b}, due_date{d} {};
	double calculate_fee();
	void to_save_data(ofstream& ofs);
	//calculates # of days between the end and start months (only for WHOLE months between the dates) 
	int calculate_month_days(int start_m, int end_m, int start_d, int end_d); 

private:
	string transaction_number;
	Date check_out_date;
	Date check_in_date;
	Librarian librarian;
	Customer customer;
	vector<shared_ptr<Media>> media;
	vector<Bundle> bundles;
	Date due_date;
	friend class Controller;
	friend class Library;
	friend class gui;
};

#endif
