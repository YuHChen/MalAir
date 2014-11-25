#ifndef MAP_H
#define MAP_H

#include "City.h"
#include <vector>
//#include <cstdlib>

using namespace std;

class Map
{
	private:
		vector<City> cities;

	public:
		Map();
		~Map();
		void addCity(string cName);
		void addFlight(string dept, string dest, Time deptTime, Time dur, Time arrTime, float cost);
		// menu options
		void justGetMeThere(City depart, City dest, Time departTime);//J
		void fewestHops(City depart, City dest, Time departTime);    //F
		void shortestTrip(City depart, City dest, Time departTime);  //C
		void cheapestTrip(City depart, City dest, Time departTime);  //S
		void displayAll();  					     //P
		friend ostream &operator<<(ostream &out, const Map &m);
		
};
#endif