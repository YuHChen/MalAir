#include "Date.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 1;
}
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year =y;
}

Date &Date::operator=(const Date &d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}
/*
Date Date::operator+(const Date &d)
{
	day = day + d.day;
	month = month + d.month;
	year = year + d.year;
}
*/
Date Date::operator+(int i)
{
	day = day + i;
	// adjust for day overflow
	if(day > 30)
	{
	  month++;
	  day %= 30;
	}
	// adjust for month overflow
	if(month > 12)
	{
	  year++;
	  month %= 12;
	}
}

bool Date::operator<(const Date &right) const
{
	bool retVal = false;
	if(this->year <= right.year)
	{
		if(this->year < right.year)
		{
			retVal =  true;
		}
		else if(this->month <= right.month)
		{
			if(this->month < right.month)
			{
				retVal =  true;
			}
			else if(this->day < right.day)
			{
				retVal = true;
			}
		}
	}
	else
	{
		return retVal;
	}
}

bool Date::operator>(const Date &right) const
{
	bool retVal = false;
	if(this->year >= right.year)
	{
		if(this->year > right.year)
		{
			retVal =  true;
		}
		else if(this->month >= right.month)
		{
			if(this->month > right.month)
			{
				retVal =  true;
			}
			else if(this->day > right.day)
			{
				retVal = true;
			}
		}
	}
	else
	{
		return retVal;
	}
}

bool Date::operator<=(const Date &right) const
{
	bool retVal = true;
	if(this->year > right.year)
	{
		retVal = false;
	}
	else if(this->month > right.month)
	{
		retVal = false;
	}
	else if(this->day > right.day)
	{
		retVal = false;
	}
	return retVal;
}

bool Date::operator>=(const Date &right) const
{
	bool retVal = true;
	if(this->year < right.year)
	{
		retVal = false;
	}
	else if(this->month < right.month)
	{
		retVal = false;
	}
	else if(this->day < right.day)
	{
		retVal = false;
	}
	return retVal;
}

bool Date::operator==(const Date &right) const
{
	bool retVal = false;
	if(this->year == right.year && this->month == right.month && this->day == right.day)
	{
		retVal = true;
	}
	return retVal;
}

bool Date::operator!=(const Date &right) const
{
	bool retVal = true;
	if(this->year == right.year && this->month == right.month && this->day == right.day)
	{
		retVal = false;
	}
	return retVal;
}

ostream& operator<<(ostream &out, const Date &d)
{
	out << d.month << '/' << d.dat << '/' << d.year;
	return out;
}
 
istream& operator>>(istream &in, const Date &d)
{
		
}

