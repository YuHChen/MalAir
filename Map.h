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
		// Adds a City to the cities vector
		void addCity(string cName);
		// Determines the departure city and then adds the flight to the Departure City's flights vector
		void addFlight(string dept, string dest, Time deptTime, Time dur, Time arrTime, float cost);
		//====	Menu Options ====
		// Takes any path from Departure City to the Destination City with arrival on same day as departure 
		void justGetMeThere(City depart, City dest, Time departTime);//J
		// Path from Departure City to the Destination City that takes the fewest number of flights 
		void fewestHops(City depart, City dest, Time departTime);    //F
		// Path from Departure City to the Destination City that takes the shortest amount of time from 
		// Departure city departure to Destination City arrival
		void shortestTrip(City depart, City dest, Time departTime);  //C
		// Path from Departure City to the Destination City that costs the least 
		void cheapestTrip(City depart, City dest, Time departTime);  //S
		// Prints the Citys and their respective flights
		void displayAll();  					     //P
		// Overloads the ostream << operator
		friend ostream &operator<<(ostream &out, const Map &m);

};
#endif
