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
