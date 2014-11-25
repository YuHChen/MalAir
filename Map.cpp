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
	for(int i = 0; i < size; i ++)
	{
		out << m.cities[i] << endl;
	}
	return out;
}
