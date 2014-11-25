#include "City.h"

City::City()
{
}
City::City(string cName)
{
	name = cName;
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
ostream &operator<<(ostream &out, const City &C)
{
  cout << "there are " << C.flights.size() << " flights from " << C.name;
  if(C.flights.size() > 0) cout << endl;
  for(vector<Flight>::const_iterator it = C.flights.begin(); it != C.flights.end(); it++){
    out << C.name << " ";
    out << (it->destCity)->getName() << " ";
    out << it->depart << " ";
    out << it->arrival << " $";
    out << it->price;
    if(it+1 != C.flights.end()) out << endl;
  }
  return out;
}
