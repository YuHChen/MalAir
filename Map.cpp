#include "Map.h"

Map::Map()
{
	pos = 0;	
}
Map::~Map()
{
}
void Map::addFlight(string dept, string dest, Time deptTime, Time dur, Time arrTime, float cost)
{
	Flight F;
	for(int i = 0; i < (int)cities.size(); i++)
	{
		if(cities[i].getName() == dest)
		{
		  F.destCityPos = cities[i].cityPos;
		}
	}
	
	F.destCityName = dest;
	F.depart = deptTime;
	F.duration = dur;
	F.arrival = arrTime;
	F.price = cost;

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
	for(int i = 0; i < (int)cities.size(); i++){
	  if(cities[i].getName() == cName){
	    found = true;
	  }
	}
	if(!found)
	{
	  //cout << cName << "added" << endl;
	  City c = City(cName);
	  c.cityPos = pos;
	  pos++;
	  //cout << c.getName() << endl;
	  cities.push_back(c);
	  //cout << cities.back().getName() << endl;
	}
}
ostream &operator<<(ostream &out, const Map &m)
{
	int size  = m.cities.size();
	cout << "there are " << size << " cities" << endl;
	for(int i = 0; i < size; i++)
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

void Map::fewestHops(string depart, string dest, Time departTime, Date departDate)
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
      Time prevArr;
      Date d = departDate;
      bool newDate = true;
      f = path.top();
      if(f.depart < departTime)
	d = d + 1;
      do
	{
	  if(newDate){
	    cout << "\t" << d << endl;
	    newDate = false;
	  }
	  	  
	  // print out flight details
	  cout << "\t   " << names.top() << " ";
	  names.pop();
	  cout << f.destCityName << " " << f.depart << " " << f.arrival << " $" << f.price << endl;
	  path.pop();
	  // check if next flight is next day
	  prevArr = f.arrival;
	  if(!path.empty())
	    f = path.top();
	  else
	    break;
	  if(f.depart < prevArr){
	    // flight needs to be taken next day
	    d = d + 1;
	    newDate = true;
	  }
	} while(!path.empty());
    }
}
void Map::shortestTrip(string depart,string dest, Time departTime, Date departDate){
//	cout<<"Not yet implemented!"<<endl;
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
	// for Dijkstra
	vector<int> duration(n, numeric_limits<int>::max()); // weight
	vector<City> cityQueue = cities; // might need deep copy???
	// for tracing path
	vector<Flight> bestFlightTo; 
	bestFlightTo.resize(n);
	vector<int> prevCity(n, -1);

	// initialize for Dijkstra
	duration[departC.cityPos] = 0;
	
	// Dijkstra
	while(!cityQueue.empty()){
	  // find City u with min duration
	  int min = numeric_limits<int>::max();
	  vector<City>::iterator minIter = cityQueue.begin();
	  int minPos = minIter->cityPos;
	  //cout << "finding min..." << endl;
	  for(vector<City>::iterator it = cityQueue.begin(); it != cityQueue.end(); it++){
	    //cout << "min: " << min << " duration: " << duration[it->cityPos] << endl;
	    if(duration[it->cityPos] < min){
	      // new minimum duration
	      minPos = it->cityPos;
	      min = duration[minPos];
	      minIter = it;
	    }
	  }
	  // u is first City in cityQueue with min duration
	  City u = cities[minPos];
	  //cout << "u: " << u.getName() << endl;
	  // remove u from cityQueue
	  cityQueue.erase(minIter);

	  // for each outbound flight f of u
	  for(vector<Flight>::iterator it = u.flights.begin(); it != u.flights.end(); it++){
	    Time prevArrTime;
	    if(duration[u.cityPos] == 0){
	      // currently at the departure city
	      // outbound flights limited to flights with depart time 
	      // after user's specified departTime
	      //cout << "currently at departure city: " << u.getName();
	      prevArrTime = departTime;
	      //cout << "\t prevArrTime: " << prevArrTime << endl;
	    }
	    else{
	      // currently at other cities
	      // outbound flights limited to flights with depart time
	      // after previous best flight's arrival
	      //cout << "currently at other cities: " << u.getName() << endl;
	      prevArrTime = bestFlightTo[u.cityPos].arrival;
	      //cout << "prevArrTime: " << prevArrTime << endl;
	    }
	    // check for valid flight  
	    // !!! Note: adding in check for valid flight gives shortest trip within one day !!! 
	    //if(it->depart > prevArrTime){
	    //cout << "valid flight from " << u.getName() << " to " << it->destCityName << endl;
	      // *it is a flight that departs later than the arrival time to this city u
	      // alt := dist[u] + length(u,v)
	      // alternate duration = duration of entire flight + duration of route to get to city u
	      // duration of entire flight = layover + duration of airtime
	      // layover = (it->depart)-prevArrTime
	      int alt = ((it->depart)-prevArrTime).asInt() + (it->duration).asInt() + duration[u.cityPos];
	      //cout << "from " << u.getName() << " to " << it->destCityName << endl;
	      //cout << "alt: " << alt << " duration: " << duration[it->destCityPos] << endl;
	      //cout << "layover: " << ((it->depart)-prevArrTime).asInt(); 
	      //cout << " airtime of flight: " << (it->duration).asInt();
	      //cout << " prev route duration: " << duration[u.cityPos] << endl;
	      if(alt < duration[it->destCityPos]){
		// found a better route, so update
		duration[it->destCityPos] = alt;
		prevCity[it->destCityPos] = u.cityPos;
		bestFlightTo[it->destCityPos] = *it;
		//for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++){
		//  cout << "duration to " << it->getName() << ": " << duration[it->cityPos] << endl;
		//}
	      }
	      //}
	  //else
	      //cout << "invalid flight from " << u.getName() << " to " << it->destCityName << endl;
	  } // end for each outbound flight f of u	  
	} // end while(!cityQueue.empty())
	
	// all flights relaxed
	if(duration[destC.cityPos] == numeric_limits<int>::max()){
	  //cout << "max int: " << numeric_limits<int>::max() << endl;
	  //cout << "duration of flight to " << cities[destC.cityPos].getName() << ": " << duration[destC.cityPos] << endl;
	  
	  cout << "Destination not reachable from " << depart << endl;
	}
	else{
	  stack<Flight> path;
	  stack<string> names;
	  City cur = destC;
	  // chase predecessors until no predecessor
	  while(prevCity[cur.cityPos] >= 0){
	    // get city we need to reach before current city
	    City prev = cities[prevCity[cur.cityPos]];
	    names.push(prev.getName());
	    // add bestFlightTo current city
	    path.push(bestFlightTo[cur.cityPos]);
	    cur = prev;
	  }

	  // path established, print out
	  Flight f;
	  Time prevArr;
	  Date d = departDate;
	  bool newDate = true;
	  f = path.top();
	  if(f.depart < departTime)
	    d = d + 1;
	  do{
	    if(newDate){
	      cout << "\t" << d << endl;
	      newDate = false;
	    }
	    
	    // print out flight details
	    cout << "\t   " << names.top() << " ";
	    names.pop();
	    cout << f.destCityName << " " << f.depart << " " << f.arrival << " $" << f.price << endl;
	    path.pop();
	    // check if next flight is next day
	    prevArr = f.arrival;
	    if(!path.empty())
	      f = path.top();
	    else
	      break;
	    if(f.depart < prevArr){
	      // flight needs to be taken next day
	      d = d + 1;
	      newDate = true;
	    }
	  } while(!path.empty());
	}
	
}

void Map::cheapestTrip(string depart, string dest, Time departTime, Date departDate){
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
  // for Dijkstra
  vector<float> cost(n, numeric_limits<float>::max()); // weight
  vector<City> cityQueue = cities; // might need deep copy???
  // for tracing path
  vector<Flight> bestFlightTo; 
  bestFlightTo.resize(n);
  vector<int> prevCity(n, -1);
  
  // initialize for Dijkstra
  cost[departC.cityPos] = 0;

  // Dijkstra
  while(!cityQueue.empty()){
    // find City u with min cost
    float min = numeric_limits<float>::max();
    vector<City>::iterator minIter = cityQueue.begin();
    int minPos = minIter->cityPos;
    //cout << "finding min..." << endl;
    for(vector<City>::iterator it = cityQueue.begin(); it != cityQueue.end(); it++){
      //cout << "min: " << min << " cost: " << cost[it->cityPos] << endl;
      if(cost[it->cityPos] < min){
	// new minimum cost
	minPos = it->cityPos;
	min = cost[minPos];
	minIter = it;
      }
    }
    // u is first City in cityQueue with min cost
    City u = cities[minPos];
    //cout << "u: " << u.getName() << endl;
    // remove u from cityQueue
    cityQueue.erase(minIter);
    
    // for each outbound flight f of u
    for(vector<Flight>::iterator it = u.flights.begin(); it != u.flights.end(); it++){
      // check for valid flight
      //if(it->depart > prevArrTime){
      //cout << "valid flight from " << u.getName() << " to " << it->destCityName << endl;
      // *it is a flight that departs later than the arrival time to this city u
      // alt := dist[u] + length(u,v)
      // alternate cost = cost of flight + cost of route to get to city u
      int alt = it->price + cost[u.cityPos];
      if(alt < cost[it->destCityPos]){
	// found a better route, so update
	cost[it->destCityPos] = alt;
	prevCity[it->destCityPos] = u.cityPos;
	bestFlightTo[it->destCityPos] = *it;
	//for(vector<City>::iterator it = cities.begin(); it != cities.end(); it++){
	//  cout << "cost to " << it->getName() << ": " << cost[it->cityPos] << endl;
	//}
      }
      //}
      //else
      //cout << "invalid flight from " << u.getName() << " to " << it->destCityName << endl;
    } // end for each outbound flight f of u	  
  } // end while(!cityQueue.empty())

  // all flights relaxed
  if(cost[destC.cityPos] == numeric_limits<float>::max()){
    //cout << "max int: " << numeric_limits<int>::max() << endl;
    //cout << "cost of flight to " << cities[destC.cityPos].getName() << ": " << cost[destC.cityPos] << endl;
    
    cout << "Destination not reachable from " << depart << endl;
  }
  else{
    stack<Flight> path;
    stack<string> names;
    City cur = destC;
    // chase predecessors until no predecessor
    while(prevCity[cur.cityPos] >= 0){
      // get city we need to reach before current city
      City prev = cities[prevCity[cur.cityPos]];
      names.push(prev.getName());
      // add bestFlightTo current city
      path.push(bestFlightTo[cur.cityPos]);
      cur = prev;
    }
    
    // path established, print out
    Flight f;
    Time prevArr;
    Date d = departDate;
    bool newDate = true;
    f = path.top();
    if(f.depart < departTime)
      d = d + 1;
    do{
      if(newDate){
	cout << "\t" << d << endl;
	newDate = false;
      }
      
      // print out flight details
      cout << "\t   " << names.top() << " ";
      names.pop();
      cout << f.destCityName << " " << f.depart << " " << f.arrival << " $" << f.price << endl;
      path.pop();
      // check if next flight is next day
      prevArr = f.arrival;
      if(!path.empty())
	f = path.top();
      else
	break;
      if(f.depart < prevArr){
	// flight needs to be taken next day
	d = d + 1;
	newDate = true;
      }
    } while(!path.empty());
  }
  
}

void Map::displayAll(){
	//Uses the implemented outputstream to send the current map data to the screen.
  cout<<*(this)<< endl;
}
