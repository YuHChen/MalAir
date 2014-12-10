#ifndef CITY_H
#define CITY_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Time.h"

class City;

typedef struct 
{	
  //City *destCity;
        int destCityPos;
        string destCityName;
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
		City(const City &c);
		~City();
	//	void addFlight(int destCity, Time depart, Time duration, float price);	
		void addFlight(Flight F);
		string getName();
		//void setName(string cName);
		friend ostream & operator<<(ostream &out, const City &C);
		City &operator=(const City& rightCity);

		
};
#endif
