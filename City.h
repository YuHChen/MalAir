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
	Time durtation;
	float price;
}Flight;		


class City
{
	private:
		vector<Flight> flights;	
		string name;
		
	public:
		City();
		City(string name);
		~City();
	//	void addFlight(int destCity, Time depart, Time duration, float price);	
		void addFlight(Flight F);
		string getName();
		
};
#endif
