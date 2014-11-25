#include "Map.h"

Map::Map()
{
	
}
Map::~Map()
{
}
void Map::addFlight(string dept, Flight F)
{
	
}
void Map::addCity(string cName)
{
	bool found = false;
	for(vector<City>::iterator it= cities.begin(); it != cities.end(); it++)	{
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
