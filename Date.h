#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
	private:
		int day;
		int month;
		int year;

	public:
		Date();
		Date(int d, int m, int y);
		
		int asInt();

		Date& operator=(const Date &d);
		Date operator+(const Date &d);
		Date operator-(const Date &d);
		bool operator<(const Date &right) const;
		bool operator>(const Date &right) const;
		bool operator>=(const Date &right) const;
		bool operator<=(const Date &right) const;
		bool operator==(const Date &right) const;
		bool operator!=(const Date &right) const;
		friend istream& operator>>(istream &in, Date &d);
		friend ostream& operator<<(ostream &out, const Date &d);

		~Date();

