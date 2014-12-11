#ifndef MAP_H
#define MAP_H

#include "Date.h"
#include "City.h"
#include <vector>
#include <limits>
#include <queue>
#include <stack>
//#include <cstdlib>

using namespace std;

class Map
{
	private:
		vector<City> cities;
		int pos;

	public:
		Map();
		~Map();
		// Adds a City to the cities vector
		void addCity(string cName);
		// Determines the departure city and then adds the flight to the Departure City's flights vector
		void addFlight(string dept, string dest, Time deptTime, Time dur, Time arrTime, float cost);
		//====	Menu Options ====
		// Takes any path from Departure City to the Destination City with arrival on same day as departure 
		void justGetMeThere(string depart, string dest, Time departTime);//J
		// Path from Departure City to the Destination City that takes the fewest number of flights 
		void fewestHops(string depart, string dest, Time departTime, Date departDate);    //F
		// Path from Departure City to the Destination City that takes the shortest amount of time from 
		// Departure city departure to Destination City arrival
		void shortestTrip(string depart, string dest, Time departTime, Date departDate);  //C
		// Path from Departure City to the Destination City that costs the least 
		void cheapestTrip(string depart, string dest, Time departTime, Date departDate);  //S
		// Prints the Citys and their respective flights
		void displayAll();  					     //P
		// Overloads the ostream << operator
		friend ostream &operator<<(ostream &out, const Map &m);

};
#endif
