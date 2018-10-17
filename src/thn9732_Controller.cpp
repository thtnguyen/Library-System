#include "thn9732_Controller.h"
#include <iterator>
#include <iostream>
#include <memory>
#include <iomanip>

void Controller::execute_cust(int cmd)
{
	switch(cmd)
	{
		case 0: break;
		case 1: library.print_catalog(); break;
		case 2:
		{
			int id;
			string cust_id = gui::create_prompt("Library System - Pay Balance","Enter your ID");
			bool found = false;

			stringstream ss;
			ss << cust_id;
			ss >> id;

			vector<Customer>::iterator it = (library.customers).begin();
			for(;it != (library.customers).end(); it++)
				if(it->get_id() == cust_id)
				{
					if(it->get_balance() < 0)
					{
						ss.str("");
						ss.clear();
						ss << "Your previous balance of $" << fixed << setprecision(2) << it->get_balance() << " has been paid for.\nYour new balance is now: ";
						it->set_balance(0.0);
						ss << it->get_balance() << endl;
						string message;
						getline(ss, message);
						gui::message("", message);
					}
					else
						gui::message("", "You don't have a negative balance that needs to be paid for.");

					found = true;
					break;
				}
			if(!found)
				gui::message("Error", "Unable to find a customer with that ID.");
			break;
		}
		default: gui::message("Error", "Invalid option entered. Returning to menu."); break;

	}
}

void Controller::execute_pm(int cmd)
{
	switch(cmd)
	{
		case 0: break;
		case 1: library.create_new_librarian(); break;
		case 2:
		{
			string name = gui::create_prompt("Library System - Load Data", "Enter name of file to load from with the .txt extension (example: savefile.txt)");
		 	library.load(name);
			break;
		}
		case 3:
		{
			string name = gui::create_prompt("Library System - Save Data", "Enter name of file to save to with the .txt extension (example: savefile.txt)");
		 	library.save(name);
		 	break;
		}
		case 4: library.create_new_media(); break;
		case 5: library.create_new_bundle(); break;
      case 6: gui::list_checked_out(library.transactions); break;
		case 7: library.default_save(); break;
		case 8: library.default_load(); break;
		default: gui::message("Error", "Invalid option entered. Returning to menu."); break;
	}

}

void Controller::execute_lbrn(int cmd)
{
	switch(cmd)
	{
		case 0: break;
		case 1: library.create_new_transaction(); break;
		case 2:
		{
		int choice = gui::check_in_options();
		if(choice == 0)
			return;
		else if(choice != 1 && choice != 2)
		{
			gui::message("Error", "Invalid option entered. Exiting to menu.");
			return;
		}

		string item_id = gui::create_prompt("Library System - Check In", "Enter the ID of item to check in");
		string cust_id = gui::create_prompt("Library System - Check In", "Enter the customer's ID");

		int year, day, month;
		string date = gui::create_prompt("Library System - Check In", "Enter the current date in the format MM DD YYYY (years <2018 are considered invalid)");
		stringstream ss;
		ss << date;
		ss >> month >> day >> year;
		Date in_date = Date(year,month,day);
		if(in_date.get_year() == -1 || in_date.get_month() == -1 || in_date.get_day() == -1)
		{
			gui::message("Error", "Invalid date was entered. Returning to menu.");
			return;
		}

		bool found = false;
		for(Transaction& t : library.transactions)
		{
			if(choice == 1)
			{
				vector<shared_ptr<Media>>::iterator m = (t.media).begin();
				while(m != (t.media).end())
				{
					if((*m)->get_id() == item_id && (t.customer).get_id() == cust_id)
					{
						(*m)->checked_out = false;
						found = true;
						ss.str("");
						ss.clear();
						ss << "Transaction was found. " << (*m)->get_title() <<" has successfully been checked in.";
						string message;
						getline(ss, message);
						gui::message("", message);


						t.check_in_date = in_date;
						vector<Customer>::iterator it = (library.customers).begin();
						if(t.calculate_fee() < 0)
							for(;it != (library.customers).end();it++)
								if(it->get_id() == cust_id)
								{
									ss.str("");
									ss.clear();
									ss << "Item late fee is: $" << fixed << setprecision(2) << fabs(t.calculate_fee()) << "\n";
									it->set_balance(t.calculate_fee());
									ss << it->get_id() << " " << it->get_name() << " new balance is: " << fixed << setprecision(2) << it->get_balance();
									string message;
									getline(ss, message);
									gui::message("", message);
								}
						(t.media).erase(m);
						break;
					}
					else
						m++;
				}
			}
			else
			{
				vector<Bundle>::iterator b = (t.bundles).begin();
				while(b != (t.bundles).end())
				{
					if(b->get_id() == item_id && (t.customer).get_id() == cust_id)
               {
							ss.str("");
							ss.clear();
							ss << "Transaction was found. " << b->get_name() <<" has successfully been checked in.";
							string message;
							getline(ss, message);
							gui::message("", message);
							b->checked_out = false;

							t.check_in_date = in_date;
                            cout << "Check in date is: " <<	(t.check_in_date).get_month() << " " << (t.check_in_date).get_day() << " " << (t.check_in_date).get_year() << endl;
                            cout << "Due date is: " <<	(t.due_date).get_month() << " " << (t.due_date).get_day() << " " << (t.due_date).get_year() << endl;

							vector<Customer>::iterator customer_it = (library.customers).begin();
							if(t.calculate_fee() < 0)
								for(;customer_it != (library.customers).end();customer_it++)
									if(customer_it->get_id() == cust_id)
									{
										ss.str("");
										ss.clear();
										ss << "Item late fee is: $" << fixed << setprecision(2) << fabs(t.calculate_fee()) << "\n";
										customer_it->set_balance(t.calculate_fee());
										ss << customer_it->get_id() << " - " << customer_it->get_name() << "'s new balance is: "<< fixed << setprecision(2) << customer_it->get_balance();
										string message;
										getline(ss, message);
										gui::message("", message);
									}
						(t.bundles).erase(b);
						found = true;
						break;
					}
					else
						b++;
				}
			if(found)
				break;
			}
		}

	if(!found)
        gui::message("Error", "No records of a transaction with that item and customer ID were found.");
	break;
	}
		case 3: library.create_new_customer(); break;
		default: gui::message("Error", "Invalid option entered. Returning to menu."); break;
    }
}

