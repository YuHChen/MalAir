#include "Map.h"

Map::Map()
{
	
}
Map::~Map()
{
}
void Map::addFlight(string dept, string dest, Time deptTime, Time dur, Time arrTime, float cost)
{
	Flight F;
	for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++)	
	{
		if((*it).getName() == dest)
		{
			F.destCity = &(*it);
		}
	}
	F.depart = deptTime;
	F.duration = dur;
	F.arrival = arrTime;
	F.price = cost;
	for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++)	
	{
		if((*it).getName() == dept)
		{
			(*it).addFlight(F);
		}
	}
}
void Map::addCity(string cName)
{
	bool found = false;
	for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++)	
	{
		if((*it).getName() == cName)
		{
			found = true;	
		}
	}
	if(!found)
	{
		City c(cName);
		cities.push_back(c);
	}
}
ostream &operator<<(ostream &out, const Map &m)
{
	int size  = m.cities.size();
//	for(vector<City>::iterator it = m.cities.begin(); it != m.cities.end(); it++)
	//for(int i = 0; i < m.cities.size(); i ++)
	cout << "there are " << size << " cities" << endl;
	for(int i = 0; i < size; i ++)
	{
	  out << m.cities[i];
	  if(i+1 < size) out << endl;
	}
	return out;
}

/*
Travel Iterniterary Option Methods with no implementation. Signatures are correct(?)
*/

void Map::justGetMeThere(City depart, City dest, Time departTime){
	cout<<"Not yet implemented!"<<endl;
}

void Map::fewestHops(City depart, City dest, Time departTime){
	cout<<"Not yet implemented!"<<endl;
}

void Map::shortestTrip(City depart,City dest, Time departTime){
	cout<<"Not yet implemented!"<<endl;
}

void Map::cheapestTrip(City depart, City dest, Time departTime){
	cout<<"Not yet implemented!"<<endl;
}

void Map::displayAll(){
	//Gonna implement
}
