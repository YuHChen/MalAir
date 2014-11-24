#ifndef MAP_H
#define MAP_H

#include "City.h"

class Map
{
	private:
		vector<City> cities;

	public:
		Map();
		~Map();
		void addCity(string name);
		void addFlight(string dept, Flight f);
		
		// menu options
		void justGetMeThere(City depart, City dest, Time departTime);//J
		void fewestHops(City depart, City dest, Time departTime);    //F
		void shortestTrip(City depart, City dest, Time departTime);  //C
		void cheapestTrip(City depart, City dest, Time departTime);  //S
		void displayAll();  					     //P
		
};
#endif
