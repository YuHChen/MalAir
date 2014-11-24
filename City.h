#ifndef CITY_H
#define CITY_H


class City
{
	typedef struct 
	{	
		City *destCity;
		Time depart;
		Time durtation;
		float price;
	}Flight;		

	private:
		vector<Flight> flights;	

	public:
		City();
		~City();
		void addFlight(int destCity, Time depart, Time duration, float price);	
		void addFlight(Flight F);
		
};
#endif
