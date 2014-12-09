#ifndef CITY_H
#define CITY_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Time.h"

class City;

typedef struct 
{	
	City *destCity;
	Time depart;
	Time duration;
	Time arrival;
	float price;
}Flight;		


class City
{
	private:
		string name;
	public:
		// Should be private?
		int cityPos;		
		vector<Flight> flights;	
		City();
		City(string name);
		~City();
	//	void addFlight(int destCity, Time depart, Time duration, float price);	
		void addFlight(Flight F);
		string getName();
		friend ostream & operator<<(ostream &out, const City &C);
		City &operator=(const City& rightCity);

		
};
#endif
