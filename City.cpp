#include "City.h"

City::City()
{
	cityPos = 0;
}
City::City(string cName)
{
	name = cName;
	cityPos = 0;
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
	City d;
	if(C.flights.size() > 0) cout << endl;
//	for(vector<Flight>::const_iterator it = C.flights.begin(); it != C.flights.end(); it++){
	for(int i = 0; i < (int)C.flights.size(); i++)
	{
		cout << "Hi" << endl;
		out << C.name << " ";
	//	d = *(it->destCity);
	//	out << d.getName();
	//	out << (it->destCity)->getName() << " ";
		d = *(C.flights[i].destCity);
		out << d.getName();
		out << C.flights[i].destCity->getName() << " ";
		cout << "Hello" << endl;
	//	out << it->depart << " ";
		out << C.flights[i].depart << " "; 
	//	out << it->arrival << " $";
		out << C.flights[i].arrival << " "; 
	//	out << it->price;
		out << C.flights[i].price;
	//	if(it+1 != C.flights.end()) out << endl;
	//	if(i+1 != C.flights.size()) out << endl;
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
