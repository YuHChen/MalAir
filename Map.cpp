#include "Map.h"

Map::Map()
{
	pos = 0;	
}
Map::~Map()
{
  /*
  for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++){
    delete &(*it);
  }
  */
}
void Map::addFlight(string dept, string dest, Time deptTime, Time dur, Time arrTime, float cost)
{
	Flight F;
	/*
//	for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++)	
	{
		if((*it).getName() == dest)
		{
			F.destCity = &(*it);
		}
	}
	*/
	
	for(int i = 0; i < (int)cities.size(); i++)
	{
		if(cities[i].getName() == dest)
		{
		  //F.destCity = &cities[i];
		  F.destCityPos = cities[i].cityPos;
		}
	}
	
	F.destCityName = dest;
	F.depart = deptTime;
	F.duration = dur;
	F.arrival = arrTime;
	F.price = cost;
	/*
	for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++)	
	{
		if((*it).getName() == dept)
		{
			(*it).addFlight(F);
		}
	}
	*/
	for(int i = 0; i < (int)cities.size(); i++)
	{
		if(cities[i].getName() == dept)
		{
			cities[i].addFlight(F);
		}
	}
}
void Map::addCity(string cName)
{
	bool found = false;
	/*
	for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++)	
	{
		if((*it).getName() == cName)
		{
			found = true;	
		}
	}
	*/
	for(int i = 0; i < (int)cities.size(); i++){
	  if(cities[i].getName() == cName){
	    found = true;
	  }
	}
	if(!found)
	{
	  //cout << cName << "added" << endl;
		City c = City(cName);
		//if(c != NULL){
		  c.cityPos = pos;
		  pos++;
		  //cout << c.getName() << endl;
		  cities.push_back(c);
		  //cout << cities.back().getName() << endl;
		  //}
		  //else 
		  //cout << "Error allocating memory for new City" << endl;
	}
}
ostream &operator<<(ostream &out, const Map &m)
{
	int size  = m.cities.size();
//	for(vector<City>::iterator it = m.cities.begin(); it != m.cities.end(); it++)
	cout << "there are " << size << " cities" << endl;
	for(int i = 0; i < size; i++)
//	for(int i = 0; i < (int)m.cities.size(); i++)
	{
		out << m.cities[i];
		if(i+1 < size) out << endl;
	}
	return out;
}

/*
Travel Iterniterary Option Methods with no implementation. Signatures are correct(?)
*/

void Map::justGetMeThere(string depart, string dest, Time departTime){
	cout<<"Not yet implemented!"<<endl;
}

void Map::fewestHops(string depart, string dest, Time departTime)
{
  City departC, destC;
  //cout << "entering loop to get cities" << endl;
  for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++)
    {	  
      if(it->getName() == depart)
	departC = *it;
      if(it->getName() == dest)
	destC = *it;
    }
  //cout << "departC: " << departC.getName() << " cityPos: " << departC.cityPos << endl;
  //cout << "destC: " << destC.getName() << " cityPos: " << destC.cityPos << endl;
  
  int n = cities.size();
  vector<int> distLabel(n, -1);
  distLabel[departC.cityPos] = 0;
  vector<int> prevCity(n, -1);
  int distance = 0;
  City c;
  queue<City> cityQueue;
  cityQueue.push(departC);
  while (distLabel[destC.cityPos] < 0 && !cityQueue.empty())
    {
      c = cityQueue.front();
      cityQueue.pop();
      //cout << "first element in cityQueue: " << c.getName() << endl;
      //cout << "dist: " << distLabel[c.cityPos] << endl;
      if (distLabel[c.cityPos] > distance)
	{
	  //cout << "updating distance" << endl;
			distance++;
	}
      
      int i = 0; 
      while (i < (int)c.flights.size() && distLabel[destC.cityPos] < 0)
	{	  
	  //City *flightDest = (c.flights[i].destCity);
	  Flight next = c.flights[i];
	  //cout << "flightDest: ";
	  //cout << next.destCityName << endl;
	  //cout << flightDest->getName() << endl;
	  //cout << "dist: " << endl;
	  //cout << distLabel[next.destCityPos] << endl;
	  //cout << "error!" << endl;
	  if (distLabel[next.destCityPos] < 0)
	    {
	      //cout << "city not visited, put in queue" << endl;
	      //cout << flightDest->getName() << endl;
	      //City tmp = *flightDest;
	      cityQueue.push(cities[next.destCityPos]);
	      distLabel[next.destCityPos] = distance + 1;
	      prevCity[next.destCityPos] = c.cityPos;
	      //cout << cities[next.destCityPos].getName() << " new dist: " << distLabel[next.destCityPos] << " prevCity: " << cities[prevCity[next.destCityPos]].getName() << endl;
	    }
	  i++;
	}
    }
  //cout << "found shortest path" << endl;
  
  if (distLabel[destC.cityPos] < 0)
    {
      cout << "Destination not reachable from this City" << endl;
    }
  else 
    {
      stack<Flight> path;
      stack<string> names;
      City cur = destC;
      // loop through (shortest) distance (from depart to dest) number of times
      // distance number of times = number of hops = number of flights
      //cout << "cur: " << cur.getName() << endl;
      //cout << "distance of dest: " << distLabel[destC.cityPos] << endl;
      for(int i = 0; i < distLabel[destC.cityPos]; i++)
	{
	  // get city we need to reach before current city
	  City prev = cities[prevCity[cur.cityPos]]; 
	  names.push(prev.getName());
	  //cout << "prev: " << prev.getName() << endl;
	  // loop through previous city's flights to find a flight to get us to current city
	  for(vector<Flight>::iterator it = prev.flights.begin(); it != prev.flights.end(); it++)
	    {
	      if(it->destCityName == cur.getName())
		{
		  // found flight, add to stack
		  path.push(*it);
		  break;
		}	
	    }
			// move cur back one city on the path
	  cur = prev;
	}
      //cout << "path established" << endl;
      
      // path established, print out
      Flight f;
      while(!path.empty())
	{
	  f = path.top(); 
	  
	  // print out flight
	  cout << names.top() << " ";
	  names.pop();
	  cout << f.destCityName << " " << f.depart << " " << f.arrival << " $" << f.price << endl;
	  path.pop(); 
	}
    }
}
void Map::shortestTrip(string depart,string dest, Time departTime){
	cout<<"Not yet implemented!"<<endl;
}

void Map::cheapestTrip(string depart, string dest, Time departTime){
	cout<<"Not yet implemented!"<<endl;
}

void Map::displayAll(){
	//Uses the implemented outputstream to send the current map data to the screen.
  cout<<*(this)<< endl;
}
