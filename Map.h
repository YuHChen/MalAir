#ifndef MAP_H
#define MAP_H


class Map
{
	private:
		vector<City> cities;

	public:
		Map();
		~Map();
		void justGetMeThere(City depart, City dest, Time departTime);//J
		void fewestHops(City depart, City dest, Time departTime);    //F
		void shortestTrip(City depart, City dest, Time departTime);  //C
		void cheapestTrip(City depart, City dest, Time departTime);  //S
		void displayAll();  					     //P

};
#endif
