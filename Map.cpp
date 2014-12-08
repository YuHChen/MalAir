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
	//cout<<"Not yet implemented!"<<endl;
	numCities = (int)cities.size();
	int dist[numCities];
	for(int i = 0; i < numCities; i++)
	{
		dist[i] = numeric_limits<int>::max();
	}
//	Text book version
	int n = cities.size();
	vector<int> distLabel(n, -1), predLabel(n);
	distLabel[depart] = 0;
	int distance = 0;
	City c;
	queue<City> cityQueue;
	cityQueue.push(start);
	while (distLabel[dest] < 0 && !cityQueue.empty())
	{
		c = cityQueue.front();
		cityQueue.pop();
		if (distLabel[c] > distance)
		{
			distance++;
		}
		for (vector<Flight>::iterator it = cities[c].flights.begin();
				it != cities[c].flights.end(); it++)
		{
			if (distLabel[*it] < 0)
			{
				distLabel[*it] = distance + 1;
				predLabel[*it] = c;
				cityQueue.push(*it);
			}
		}
		distance++;
	}
	vector<Flight> path(distance + 1);
	if (distLabel[dest] < 0)
	{
		cout << "Destination not reachable from this City" << endl;
	}
	else 
	{
		path[distance] = destination;
		for (int k = distance - 1; k >= 0; k--)
		{
			path[k] = predLabel[path[k+1]];
		}
	}
//	return path;
	for(int i = 0; i < path.size(); i++)
	{
		cout << path[i];
	}
	cout << endl;
}

void Map::shortestTrip(City depart,City dest, Time departTime){
	cout<<"Not yet implemented!"<<endl;
}

void Map::cheapestTrip(City depart, City dest, Time departTime){
	cout<<"Not yet implemented!"<<endl;
}

void Map::displayAll(){
	//Uses the implemented outputstream to send the current map data to the screen.
  cout<<*(this)<< endl;
}
