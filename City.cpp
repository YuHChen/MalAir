#include "City.h"

City::City()
{
  name = "";
  cityPos = 0;
}
City::City(string cName)
{
	name = cName;
	cityPos = 0;
}
City::City(const City &c){
  //cout << "Called City::City(const City&) [copy constructor]" << endl;
  //cout << c.name << endl;
  name = c.name;
  cityPos = c.cityPos;
  for(vector<Flight>::const_iterator it = c.flights.begin(); it != c.flights.end(); it++)
    {
      flights.push_back(*it);
    }  
}
City::~City()
{
}
void City::addFlight(Flight f)
{
	flights.push_back(f);
}
string City::getName()
{
	return name;
}
/*
void City::setName(string cName){
  name = cName;
}
*/
ostream &operator<<(ostream &out, const City &C)
{
	cout << "there are " << C.flights.size() << " flights from " << C.name;
	City d;
	if(C.flights.size() > 0) cout << endl;
	for(vector<Flight>::const_iterator it = C.flights.begin(); it != C.flights.end(); it++){
	  out << "\t" << C.name << " ";
	  out << it->destCityName << " ";
	  out << it->depart << " ";
	  out << it->arrival << " $";
	  out << it->price;
	  if(it+1 != C.flights.end()) out << endl;
	}
	return out;
}
City &City::operator=(const City& rightCity)
{
  name = rightCity.name;
	cityPos = rightCity.cityPos;
	for(vector<Flight>::const_iterator it = rightCity.flights.begin(); it != rightCity.flights.end(); it++)
	{
	  flights.push_back(*it);
	}

	return *this;
}
