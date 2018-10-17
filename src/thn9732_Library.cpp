#include "thn9732_Library.h"
#include "thn9732_View.h"
#include <iterator>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

void Library::create_new_media()
{
	int choice = gui::create_media_options();
	switch(choice)
	{
		case 1: {//book
				
					string id = gui::create_prompt("Library System - ID", "Enter the item's ID number");
					for(shared_ptr<Media> m : medias)
						if(m->get_id() == id)
						{
							gui::message("Error", "There is already an existing media with that ID number.");
							return;
						}
					string cn = gui::create_prompt("Library System - Call Number", "Enter the call number");
					for(shared_ptr<Media> m : medias)
						if(m->get_call_num() == cn)
						{
							gui::message("Error", "There is already an existing media with that call number.");
							return;
						}
					string t = gui::create_prompt("Library System - Title", "Enter the title");
					string g = gui::create_prompt("Library System - Genre", "Enter the genre");
					string a = gui::create_prompt("Library System - Author", "Enter the author");
					string cy = gui::create_prompt("Library System - Copyright Year", "Enter the copyright year");
					shared_ptr<Media> mptr (new Book(id, cn, t, g, a, cy));
					medias.push_back(mptr);
					break;
				  }

		case 2:{//movie

					string id = gui::create_prompt("Library System - ID", "Enter the item's ID number");
					for(shared_ptr<Media> m : medias)
						if(m->get_id() == id)
						{
							gui::message("Error", "There is already an existing media with that ID number.");
							return;
						}
					string cn = gui::create_prompt("Library System - Call Number", "Enter the call number");
					for(shared_ptr<Media> m : medias)
						if(m->get_call_num() == cn)
						{
							gui::message("Error", "There is already an existing media with that call number.");
							return;
						}
					string t = gui::create_prompt("Library System - Title", "Enter the title");
					string g = gui::create_prompt("Library System - Genre", "Enter the genre");
					string ry = gui::create_prompt("Library System - Release Year", "Enter the release year");
					string d = gui::create_prompt("Library System - Movie Director", "Enter the movie director");
					string p = gui::create_prompt("Library System - Movie Producer", "Enter the movie producer");
					vector<string> actors;

					string name = gui::multiple_prompts("Library System - Leading Actors", "Enter a leading actor of the movie");
					while(name != "null")
					{
						actors.push_back(name);
						name = gui::multiple_prompts("Library System - Leading Actors", "Enter another leading actor of the movie");
					}
					shared_ptr<Media> mptr (new Movie(id, cn, t, g, ry, d, p, actors));
					medias.push_back(mptr);
					break;
				}

		case 3:{//tv show

					string id = gui::create_prompt("Library System - ID", "Enter the item's ID number");
					for(shared_ptr<Media> m : medias)
						if(m->get_id() == id)
						{
							gui::message("Error", "There is already an existing media with that ID number.");
							return;
						}
					string cn = gui::create_prompt("Library System - Call Number", "Enter the call number");
					for(shared_ptr<Media> m : medias)
						if(m->get_call_num() == cn)
						{
							gui::message("Error", "There is already an existing media with that call number.");
							return;
						}
					string t = gui::create_prompt("Library System - Title", "Enter the title");
					string g = gui::create_prompt("Library System - Genre", "Enter the genre");
					string ry = gui::create_prompt("Library System - Release Year", "Enter the release year");
					string sn = gui::create_prompt("Library System - Season Number", "Enter the season number");
					string p = gui::create_prompt("Library System - Movie Producer", "Enter the show producer");	
					vector<string> directors, actors;
					

					string name = gui::multiple_prompts("Library System - Directors", "Enter a director of the show");
					while(name != "null")
					{
						directors.push_back(name);
						name = gui::multiple_prompts("Library System - Directors", "Enter another director of the show");	
					}

					name = gui::multiple_prompts("Library System - Leading Actors", "Enter a leading actor of the show");
					while(name != "null")
					{
						actors.push_back(name);
						name = gui::multiple_prompts("Library System - Leading Actors", "Enter another leading actor of the show");	
					}

					shared_ptr<Media> mptr (new TV_Show_Season(id, cn, t, g, ry, p, directors, actors, sn));
					medias.push_back(mptr);
					break;
				  }

		case 4:{//video game

					string id = gui::create_prompt("Library System - ID", "Enter the item's ID number");
					for(shared_ptr<Media> m : medias)
						if(m->get_id() == id)
						{
							gui::message("Error", "There is already an existing media with that ID number.");
							return;
						}
					string cn = gui::create_prompt("Library System - Call Number", "Enter the call number");
					for(shared_ptr<Media> m : medias)
						if(m->get_call_num() == cn)
						{
							gui::message("Error", "There is already an existing media with that call number.");
							return;
						}
					string t = gui::create_prompt("Library System - Title", "Enter the title");
					string g = gui::create_prompt("Library System - Genre", "Enter the genre");
					string ry = gui::create_prompt("Library System - Release Year", "Enter the release year");
					string s = gui::create_prompt("Library System - Studio", "Enter the game studio");
				
					shared_ptr<Media> mptr (new Video_Game(id,cn,t,g,ry,s));
					medias.push_back(mptr);
					break;
				  }

		case 5:{//music album
					string id = gui::create_prompt("Library System - ID", "Enter the item's ID number");
					for(shared_ptr<Media> m : medias)
						if(m->get_id() == id)
						{
							gui::message("Error", "There is already an existing media with that ID number.");
							return;
						}
					string cn = gui::create_prompt("Library System - Call Number", "Enter the call number");
					for(shared_ptr<Media> m : medias)
						if(m->get_call_num() == cn)
						{
							gui::message("Error", "There is already an existing media with that call number.");
							return;
						}
					string t = gui::create_prompt("Library System - Title", "Enter the title");
					string g = gui::create_prompt("Library System - Genre", "Enter the genre");
					string ry = gui::create_prompt("Library System - Release Year", "Enter the release year");
					string a = gui::create_prompt("Library System - Artist", "Enter the album artist");
					vector<string> tracks;

					string name = gui::multiple_prompts("Library System - Tracks", "Enter a track on the album");

					while(name != "null")
					{
						tracks.push_back(name);	
						name = gui::multiple_prompts("Library System - Tracks", "Enter another track on the album");
					}
					shared_ptr<Media> mptr (new Music_Album(id, cn, t, g, ry, a, tracks));
					medias.push_back(mptr);
					break;
			}
	}

}

void Library::create_new_bundle()
{
	if(medias.size() == 0)
	{
		gui::message("Error","There are no existing media to make bundles of.");
		return;
	}

	string name = gui::create_prompt("Library System - Create Bundle", "Enter name of the new bundle");
   string bundle_id = gui::create_prompt("Library System - Create Bundle", "Enter ID of the new bundle");
	vector<Bundle>::iterator b_it = bundles.begin();
	for(;b_it != bundles.end();b_it++)
		if(b_it->get_id() == bundle_id)
		{
			gui::message("Error", "There is already an existing bundle with that ID.");
			return;
		}

	vector<shared_ptr<Media>> mlist;

	gui::list_media(medias);
	string media_id = gui::multiple_prompts("Library System - Create Bundle", "Enter the ID of a media to add to the bundle");
	vector<shared_ptr<Media>>::iterator it;
	while(media_id != "null")
	{
		it = medias.begin();
		while(it != medias.end())
		{
			if((*it)->get_id() == media_id)
			{
				if(!(*it)->is_available())
					gui::message("Error","This item is currently checked out and cannot be added to a bundle.");
				else
				{
					mlist.push_back((*it));
					medias.erase(it);
				}
				break;
			}
			else
				it++;
		}
		media_id = gui::multiple_prompts("Library System - Create Bundle", "Enter the ID of another media to add to the bundle");
	}
	if(mlist.size() == 0)
		{
			gui::message("", "No media has been added to create a bundle, exiting without creating bundle.");
			return;
		}
	bundles.emplace_back(name, bundle_id, mlist, false);
	gui::message("","Bundle was successfully made.");
}

void Library::create_new_librarian()
{
	string name = gui::create_prompt("Library System - Create Librarian", "Enter the librarian's name");
	string lib_id = gui::create_prompt("Library System - Create Librarian", "Enter the librarian's ID number");
	int id;
	stringstream ss;
	ss << lib_id;
	ss >> id;

	if(id < 1)
	{
		gui::message("ERROR", "The ID number should be greater than 0. Returning to menu. ");
		return;
	}

	for(Librarian l : librarians)
		if(l.get_id() == lib_id)
		{
			gui::message("ERROR", "There is already another librarian with this ID. Exiting to menu.");
			return;
		}
	Librarian new_lbrn = Librarian(name, lib_id);
	librarians.push_back(new_lbrn);
}

void Library::create_new_customer()
{

	string name = gui::create_prompt("Library System - Create Customer", "Enter the customer's name");
	string cust_id = gui::create_prompt("Library System - Create Customer", "Enter the customer's ID number");
	int id;

	stringstream ss;
	ss << cust_id;
	ss >> id;

	if(id < 1)
	{
		gui::message("ERROR", "The ID number should be greater than 0. Returning to menu.");
		return;
	}

	for(Customer c : customers)
		if(c.get_id() == cust_id)
		{
			gui::message("ERROR", "There is already another customer with this ID. Exiting to menu.");
			return;
		}


	string phone = gui::create_prompt("Library System - Create Customer", "Enter the customer's phone number");
	string email = gui::create_prompt("Library System - Create Customer", "Enter the customer's email address");
	
	Customer *new_cust = new Customer(name, cust_id, phone, email);
	gui::message("", "Customer was successfully made.");
	customers.push_back(*new_cust);
	delete new_cust;

}

void Library::create_new_transaction()
{
	string lib_id = gui::create_prompt("Library System - Create Transaction","Enter your ID number");
	bool found = false;

	Librarian lbrn = Librarian();
	vector<Librarian>::iterator lib_it;
	for(lib_it = librarians.begin(); lib_it!=librarians.end(); lib_it++)
	{
		if(lib_it->get_id() == lib_id)
		{
			found = true;
			lbrn = *lib_it;
			break;
		}
	}
	if(!found)
	{
		gui::message("Error", "Could not find a librarian with this ID number. Returning to menu.");
		return;
	}
	found = false;
	string cust_id = gui::create_prompt("Library System - Create Transaction", "Enter the customer's ID number");

	Customer cust = Customer();
	for(Customer c : customers)
		if(c.get_id() == cust_id)
		{
			found = true;
			cust = c;
			break;
		}

	if(!found)
	{
		gui::message("Error", "Could not find a customer with this ID number. Returning to menu.");
		return;
	}
	if(cust.get_balance() < 0)
	{
		gui::message("Error","The customer has a negative balance and cannot check out anything until it is paid for.");
		return;
	}
	string date = gui::create_prompt("Library System - Create Transaction", "Enter today's date in the format MM DD YYYY (years < 2018 are considered invalid)");

	stringstream ss;
	ss << date;
	int month,day,year;
	ss >> month >> day >> year;

	Date out_date = Date(year,month,day);
	if(out_date.get_year() == -1 || out_date.get_month() == -1 || out_date.get_day() == -1)
	{
		gui::message("Error", "Invalid date was entered. Returning to menu.");
		return;
	}
	vector<shared_ptr<Media>> mlist;
	vector<Bundle> blist;

	int choice = -1;
	string checkout_id;
	while(choice != 0)
	{
		choice = gui::check_out_options();
		if(choice == 0)
			break;
		
		checkout_id = gui::multiple_prompts("Library System - Create Transaction", "Enter the ID of media/bundle to check out"); 
		bool found = false;
		if(choice == 1)
		for(shared_ptr<Media> m : medias)
			if(m->get_id() == checkout_id)
			{
				found = true;
				if(!(m->is_available()))
					gui::message("Error", "This media is already checked out.");
				else
				{	
					m->checked_out = true;
					mlist.push_back(m);
					gui::message("", m->get_title()+" successfully added to transaction.");
					
				}
			}
		if(choice == 2)
		{
			vector<Bundle>::iterator it = bundles.begin();
			for(;it != bundles.end();it++)
				if(it->get_id() == checkout_id)
				{
					found = true;
					if(!it->is_available())
						gui::message("Error", "This bundle is already checked out.");
					else
					{
						it->checked_out = true;
						blist.push_back(*it);
						gui::message("", it->get_name()+" successfully added to transaction.");
					}
				}
			}

			if(!found)
				gui::message("Error", "Could not find the item corresponding to entered ID.");
		}

	if(mlist.size() == 0 && blist.size() == 0)
	{
		gui::message("", "Nothing was checked out. Returning to menu.");
		return;
	}
	
		//calculating due date
		int month_days = 0; //number of days in each month
		if(month == 2)
			month_days = 28;
		else if(month == 4 || month == 6 || month == 9 || month == 11)
			month_days = 30;
		else
			month_days = 31;

		if(month_days - day < 14)
			{
				month++;
				int original_day = day;
				day = 0;
				day+= (14 - (month_days - original_day));
			}
		else
			day+= 14;
		
		Date due_date = Date(year,month,day);
		Date in_date = Date(0,0,0); // 0's indicate not yet checked in

		int t_num = transactions.size()+1;
		string trans_num;
		stringstream ss1;
		ss1 << t_num;
		ss1 >> trans_num;

		Transaction trans = Transaction(trans_num, out_date, in_date, lbrn, cust, mlist, blist, due_date); //create transaction
		transactions.push_back(trans);
		string message;
		ss.str("");
		ss.clear();
		ss << "Transaction successfully created. Transaction number: " << setw(5) << setfill('0') << t_num;
		getline(ss, message);
		gui::message("", message); 
		
}

void Library::save(string file_name)
{
	ofstream ofs(file_name);
	for(shared_ptr<Media> m : medias)
		m->to_save_data(ofs);
	ofs << "|" << endl;
	for(Bundle b : bundles)
		b.to_save_data(ofs);
	ofs << "|" << endl;
	for(Librarian l : librarians)
		l.to_save_data(ofs);
	ofs << "|" << endl;
	for(Customer c : customers)
		c.to_save_data(ofs);
	ofs << "|" << endl;
	for(Transaction t : transactions)
		t.to_save_data(ofs);
	ofs << "|" << endl;
	ofs.close();
	gui::message("", "Succesfully saved data.");
}

void Library::default_save()
{
	save("save.txt");
}

void Library::load(string file_name)
{
	ifstream ifs(file_name);
	if(ifs.good())
	{
		string temp;
	   load_media(ifs, "|", medias);	//loading saved media
		while(getline(ifs, temp)) //loading saved bundles
		{
			if(temp == "|")
				break;

			string name = temp;
			string id;
			vector<shared_ptr<Media>> mlist;

			getline(ifs, temp);
			stringstream ss (temp);
			ss >> id;

			load_media(ifs, "END MEDIA", mlist);

			bool status;
			getline(ifs, temp);
			if(temp == "0")
				status = true;
			else
				status = false;
			bundles.emplace_back(name, id, mlist, status);
		}
		  while(getline(ifs, temp))
		  {
				if(temp == "|")
					break;
				
				string name = temp;
				string id;
				getline(ifs, temp);
				stringstream ss (temp);
				ss >> id;

				Librarian new_lbrn = Librarian(name, id);
				librarians.push_back(new_lbrn);
		  }

		 while(getline(ifs, temp))
		 {
			 if(temp == "|")
				 break;

			 string email, phone, name = temp;
			 string id;
			 double balance;

			 getline(ifs, temp);
			 stringstream ss (temp);
			 ss >> id;

			 getline(ifs, phone);

			 getline(ifs, email);

			 getline(ifs, temp);
			 ss.str(temp);
			 ss.clear();
			 ss >> balance;

			 Customer new_cust = Customer(name, id, phone, email);
			 new_cust.set_balance(balance);
			 customers.push_back(new_cust);
		}		
		while(getline(ifs, temp))
		{
			if(temp == "|")
				return;

			int day, year, month;
			string lbrn_id, cust_id, trans_num;
			string lbrn, cust, phone, email;
			double balance;
			vector<shared_ptr<Media>> tmedia;
			vector<Bundle> tbundles;

			stringstream ss (temp);
			ss >> trans_num;

			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> year >> month >> day;
			Date out_date = Date(year, month, day);

			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> year >> month >> day;
			Date in_date = Date(year, month, day);

			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> year >> month >> day;
			Date due_date = Date(year, month, day);

			getline(ifs, lbrn);

			getline(ifs, temp);

			ss.str(temp);
			ss.clear();
			ss >> lbrn_id;

			getline(ifs, cust);

			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> cust_id;

			getline(ifs, phone);

			getline(ifs, email);

			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> balance;

			string id;
			while(getline(ifs, temp))
			{
				if(temp == "Bundles")			
					break;

				ss.str(temp);
				ss.clear();
				ss >> id;
				for(shared_ptr<Media >m : medias)
					if(m->get_id() == id)
					{
						tmedia.push_back(shared_ptr<Media>(m));
						break;
					}
			}
			while(getline(ifs, temp))
			{
				if(temp == ";")
					break;

				ss.str(temp);
				ss.clear();
				ss >> id;
				for(Bundle b : bundles)
					if(b.get_id() == id)
					{
						tbundles.push_back(b);
						break;
					}
			}
			Customer new_cust = Customer(cust, cust_id, phone, email);
			new_cust.set_balance(balance);
			Librarian new_lbrn = Librarian(lbrn, lbrn_id);
			Transaction new_trans = Transaction(trans_num, out_date, in_date, new_lbrn, new_cust, tmedia, tbundles, due_date);
			transactions.push_back(new_trans);
		}
	}
	else
	{
		gui::message("ERROR", "Invalid load file.");
		return;
	}	
	gui::message("", "Successfully loaded data.");
	ifs.close();
}

void Library::default_load()
{
	load("save.txt");
}

void Library::print_catalog()
{
	if(medias.size() == 0 && bundles.size() == 0)
		{
			gui::message("", "There are no existing media and bundles to show.");
			return;
		}

	gui::show_catalog(medias, bundles);

}

void Library::load_media(ifstream& ifs, string delimiter, vector<shared_ptr<Media>>& list)
{
	string temp;
	while(getline(ifs, temp)) //while loop for media list
	{
		if(temp == delimiter)
		{
			return;
		}

		if(temp == "Book")
		{
			string id,copyright;
			string call_num, title, genre, author;

			getline(ifs, id);	
			getline(ifs, call_num);
			getline(ifs, title);
			getline(ifs, genre);
			getline(ifs, author);
			getline(ifs, copyright);
		
			Book *new_book = new Book(id, call_num, title, genre, author, copyright);
			getline(ifs, temp);
			if(temp == "0")
				new_book->checked_out = true;
			list.push_back(shared_ptr<Media>(new_book));

		}
		if(temp == "Movie")
		{
			string id,release;
			string call_num, title, genre, prod, dir;
			vector<string> actors;

			getline(ifs, temp);	
			stringstream ss (temp);
			ss >> id;

			getline(ifs, call_num);

			getline(ifs, title);
			getline(ifs, genre);
	
			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> release;

			getline(ifs, prod);
			getline(ifs, dir);
			
			while(getline(ifs, temp))
				if(temp != ";")
					actors.push_back(temp);
				else
					break;

			Movie *new_movie = new Movie(id, call_num, title, genre, release, prod, dir, actors);
			getline(ifs, temp);
			if(temp == "0")
				new_movie->checked_out = true;
			list.push_back(shared_ptr<Media>(new_movie));
		}
		if(temp == "Album")
		{
			string id,release;
			string call_num, title, genre, artist;
			vector<string> tracks;

			getline(ifs, temp);	
			stringstream ss (temp);
			ss >> id;

			getline(ifs, call_num);
			getline(ifs, title);
			getline(ifs, genre);

			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> release;

			getline(ifs, artist);

			while(getline(ifs, temp))
				if(temp != ";")
					tracks.push_back(temp);
				else
					break;

			Music_Album* new_album = new Music_Album(id, call_num, title, genre, release, artist, tracks);
			getline(ifs, temp);
			if(temp == "0")
				new_album->checked_out = true;
			list.push_back(shared_ptr<Media>(new_album));
		}
		if(temp == "TV")
		{
			string id,release,season;
			string call_num, title, genre, prod;
			vector<string> actors, directors;

			getline(ifs, temp);	
			stringstream ss (temp);
			ss >> id;

			getline(ifs, call_num);
			getline(ifs, title);
			getline(ifs, genre);

			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> release;

			getline(ifs, prod);
	
			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> season;

			while(getline(ifs, temp))
				if(temp != "Actors")
					directors.push_back(temp);
				else
					break;

			while(getline(ifs, temp))
				if(temp != ";")
					actors.push_back(temp);
				else
					break;

			TV_Show_Season *new_tv = new TV_Show_Season(id, call_num, title, genre, release, prod, directors, actors, season);
			getline(ifs, temp);
			if(temp == "0")
				new_tv->checked_out = true;
			list.push_back(shared_ptr<Media>(new_tv));
		}
		if(temp == "Game")
		{
			string id,release;
			string call_num, title, genre, studio;
			getline(ifs, temp);	
			stringstream ss (temp);
			ss >> id;
			getline(ifs, call_num);
			getline(ifs, title);
			getline(ifs, genre);
			getline(ifs, temp);
			ss.str(temp);
			ss.clear();
			ss >> release;
			getline(ifs, studio);
	
			Video_Game* new_game = new Video_Game(id, call_num, title, genre, release, studio);
			getline(ifs, temp);
			if(temp == "0")
				new_game->checked_out = true;
			list.push_back(shared_ptr<Media>(new_game));
		}
	}
}

