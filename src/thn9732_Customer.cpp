#include "thn9732_Customer.h"
#include <sstream>
#include <fstream>

string Customer::get_name()
{
	return name;
}

string Customer::get_id()
{
	return id;
}

void Customer::set_balance(double b)
{
	balance = b;
}

double Customer::get_balance()
{
	return balance;
}

string Customer::to_string() const
{
	stringstream ss;
	ss << this->balance;
	string b;
	ss >> b;
	return id+" - "+this->name+" - "+this->phone+" - "+this->email+" - "+b;
}

ostream& operator<< (ostream& ost, const Customer& c)
{
	ost << c.to_string();
	return ost;
}

Customer& Customer::operator= (const Customer &rhs)
{
	if(this != &rhs)
	{
		name = rhs.name;
		id = rhs.id;
		phone = rhs.phone;
		email = rhs.email;
		balance = rhs.balance;
	}
	return *this;
}

void Customer::to_save_data(ofstream& ofs)
{
	ofs << name << endl;
	ofs << id << endl;
	ofs << phone << endl;
	ofs << email << endl;
	ofs << balance << endl;
}
