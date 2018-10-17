#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{
public:
	Date(int y, int m, int d)
	{
	if(y < 2018)
	{	
		year = -1;
	}
	else
		year = y;

	if(m < 1 || m > 12)
	{	
		month = -1;
	}
	else
		month = m;

	if(d < 1 && d > 30)
		d = -1;
	else
		day = d;
	};
	int get_day();
	int get_month();
	int get_year();
	Date& operator= (const Date &rhs);

private:
	int year;
	int month;
	int day;
};

#endif
