#include "thn9732_Date.h"

int Date::get_day()
{
	return day;
}

int Date::get_month()
{
	return month;
}

int Date::get_year()
{
	return year;
}
Date& Date::operator= (const Date &rhs)
{
	if(this != &rhs)
	{
		day = rhs.day;
		month = rhs.month;
		year = rhs.year;
	}
	return *this;
}

