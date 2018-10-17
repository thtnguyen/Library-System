#include "thn9732_Transaction.h"
#include <iostream>

double Transaction::calculate_fee()
{

	int days_late = 0;
	
	if(check_in_date.get_year() != due_date.get_year())
	{
		if(check_in_date.get_month() >= due_date.get_month())
			days_late += (check_in_date.get_year() - due_date.get_year()) * 365;
		else if(check_in_date.get_month() == due_date.get_month() && check_in_date.get_day() <= due_date.get_day())
		{
			days_late += check_in_date.get_day() - due_date.get_day();
			days_late += (check_in_date.get_year() - due_date.get_year()) * 365;
			return days_late * -0.5;
		}
		else
			days_late += (check_in_date.get_year() - due_date.get_year() - 1) * 365;
	}
	else

	if(check_in_date.get_month() > due_date.get_month())
	{
		days_late += calculate_month_days(due_date.get_month(), check_in_date.get_month(), due_date.get_day(), check_in_date.get_day());
		if(check_in_date.get_day() < due_date.get_day())
			{
				days_late += check_in_date.get_day() - 1;
				return days_late * -0.5;
			}
	}

	if(check_in_date.get_month() < due_date.get_month() && check_in_date.get_year() != due_date.get_year())
	{
		days_late += calculate_month_days(due_date.get_month(), 13, due_date.get_day(), check_in_date.get_day());
		days_late += calculate_month_days(1, check_in_date.get_month(), 1, check_in_date.get_day());
		if(check_in_date.get_day() < due_date.get_day())
			{
				days_late += check_in_date.get_day() - 1;
				return days_late * -0.5;
			}
	}
	else if(check_in_date.get_month() < due_date.get_month() && check_in_date.get_year() == due_date.get_year())
		return 0;

	days_late += check_in_date.get_day() - due_date.get_day();
	if(days_late > 0)
		return days_late * -0.5;
	else
		return 0;
}

void Transaction::to_save_data(ofstream& ofs)
{
	ofs << transaction_number << endl;
	ofs << check_out_date.get_year() << " " << check_out_date.get_month() << " " << check_out_date.get_day() << endl;
	ofs << check_in_date.get_year() << " " << check_in_date.get_month() << " " << check_in_date.get_day() << endl;
	ofs << due_date.get_year() << " " << due_date.get_month() << " " << due_date.get_day() << endl;
	librarian.to_save_data(ofs);
	customer.to_save_data(ofs);
	for(shared_ptr<Media> m : media)
		ofs << m->get_id() << endl;
	ofs << "Bundles" << endl;
	for(Bundle b : bundles)
		ofs << b.get_id() << endl;
	ofs << ";" << endl;
}

int Transaction::calculate_month_days(int start_m, int end_m, int start_d, int end_d)
{
	int days_late = 0;

		if(end_d >= start_d)
		{
			for(int i = start_m; i < end_m; i++)
			{
				switch(i)
				{
					case 1: days_late += 31; break;
					case 2: days_late += 28; break;
					case 3: days_late += 31; break;
					case 4: days_late += 30; break;
					case 5: days_late += 31; break;
					case 6: days_late += 30; break;
					case 7: days_late += 31; break;
					case 8: days_late += 31; break;
					case 9: days_late += 30; break;
					case 10: days_late += 31; break;
					case 11: days_late += 30; break;
					case 12: days_late += 31; break;

				}
			}
		}
		else
		{
			int last_month_days;
			for(int i = start_m; i < end_m; i++)
			{
				switch(i)
				{
					case 1: if(i != end_m-1) days_late += 31; else last_month_days = 31; break;
					case 2: if(i != end_m-1) days_late += 28; else last_month_days = 28; break;
					case 3: if(i != end_m-1) days_late += 31; else last_month_days = 31; break;
					case 4: if(i != end_m-1) days_late += 30; else last_month_days = 30; break;
					case 5: if(i != end_m-1) days_late += 31; else last_month_days = 31; break;
					case 6: if(i != end_m-1) days_late += 30; else last_month_days = 30; break;
					case 7: if(i != end_m-1) days_late += 31; else last_month_days = 31; break;
					case 8: if(i != end_m-1) days_late += 31; else last_month_days = 31; break;
					case 9: if(i != end_m-1) days_late += 30; else last_month_days = 30; break;
					case 10: if(i != end_m-1) days_late += 31; else last_month_days = 31; break;
					case 11: if(i != end_m-1) days_late += 30; else last_month_days = 30; break;
					case 12: if(i != end_m-1) days_late += 31; else last_month_days = 31; break;

				}
			}
			days_late += last_month_days - start_d + 1;
		}
	return days_late;
}
