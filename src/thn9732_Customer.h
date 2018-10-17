#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer
{
public:
	Customer(string n, string i, string p, string e): name{n}, id{i}, phone{p}, email{e}, balance{0.0} {};
	Customer(): Customer("name", "999", "0123456789", "email") {};
	string get_id();
	void to_save_data(ofstream& ofs);
	string get_name();
	double get_balance();
	void set_balance(double b);
	string to_string() const;
	friend ostream& operator<< (ostream& ost, const Customer& c);
	Customer& operator= (const Customer &rhs);

private:
	string name;
	string id;
	string phone;
	string email;
	double balance;
};

#endif
