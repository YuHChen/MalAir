#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Time.h"
#include "Date.h"
#include "City.h"
#include "Map.h"

using namespace std;

int main(int argc, char **argv){
  string progName(argv[0]);
  string fileName;
  if(argc < 2){
    // user did not specify flight schedule
    cout << "usage: " << progName << " [ddfs.txt]" << endl;
    return 0;
  }
  else{
    // user specified flight schedule
    istringstream buf (argv[1]);
    buf >> fileName;
    ifstream flightSchedule(fileName.c_str());
    if(flightSchedule.fail()){
      cout << "Could not open " << fileName << endl;
      return 0;
    }
    else{
      // successfully opened flight schedule file
     	Map m;
	string dest,dept;
	float cost;
	Time arrTime, deptTime;
	Flight f;
	char c;
	while(!flightSchedule.fail()){
	  // read in
	  flightSchedule >> dept;
	  if(flightSchedule.fail()) break;
	  flightSchedule >> dest;
	  flightSchedule >> deptTime;
	  flightSchedule >> arrTime;
	  flightSchedule >> c; //Get rid of the $ sign
	  flightSchedule >> cost;
	  m.addCity(dept);
	  m.addCity(dest);

	  // cities guranteed to exist
	  m.addFlight(dept, dest, deptTime,(arrTime - deptTime), arrTime, cost);
	}
	cout<<m<<endl;

	string deptCity, destCity;
	Time departTime, earliestRetTime;
	Date departDate, retDate;
	cout<<"Enter departure city, destination city, and departure time in that order"<<endl;
	cout<<"Also enter the ";
	cout<<"Time entered in 12 hour format with colons and am/pm. e.g 8:00am  "<<endl;
	cin>> deptCity>>destCity>>departTime;
	cout << "Enter departure date (DD/MM/YYYY): ";
	cin >> departDate;
	cout << "Enter return date (DD/MM/YYYY): ";
	cin >> retDate;
	
	// check that user doesn't want to time travel
	if(retDate < departDate){
	  cout << "Sorry, we do not offer services for time travel...yet." << endl;
	  return 0;
	}

	cout<<"Enter a earliest acceptable return time for the trip back"<<endl;
	cin>>earliestRetTime;

	//Asking the User what method they want to perform.
	cout<<"Trip Constraints Menu:[J,F,C,S,P]"<<endl;
	cout<<"Select option for more information"<<endl;
	//J
	cout<<"J: Just Get Me There"<<'\n'<<'\t';
	cout<<"An itinerary from a departure city to a desination city. (No constraints)"<<'\n'<<'\n';
	//F
	cout<<"F: Fewest Hops"<<'\n'<<'\t';
	cout<<"An itinerary that can get from a deparature city to a destination with the "<<'\n'<<'\t'<<
	"fewst direct flight components"<<'\n'<<'\n';
	//S
	cout<<"S: Shortest Trip"<<'\n'<<'\t';
	cout<<"Minimizes the time between leaving from the departure and arriving at the "<<'\n'<<'\t'<<
	"destination city. Also minimizes the time between return from the destination "<<'\n'<<'\t'<<
	" city and arriving back at the departure city "<<'\n'<<'\n';
	//C
	cout<<"C: Cheapest Trip"<<'\n'<<'\t';
	cout<<"Find the cheapest(potentially multi hop) that meets the specified constraints."<<'\n'<<'\n';
	//P
	cout<<"P: Print Flight Schedule "<<'\n'<<'\t';
	cout<<"Displays entire flight schedule "<<'\n'<<'\n';


	while(true){
	  char option;
	  cin>>option;
	  //Is this too much?
	  switch(option){
	  case'J':
	    m.justGetMeThere(deptCity, destCity, departTime);
	    break;
	  case'F':
	    cout << "Here is your itinerary with the fewest hops: " << endl;        
	    m.fewestHops(deptCity, destCity, departTime, departDate);
	    cout << endl << "Here is your itinerary with the fewest hops for the return trip: " << endl;
	    m.fewestHops(destCity, deptCity, earliestRetTime, retDate);
	    break;
	  case'S':
	    cout << "Here is your itinerary for the shortest trip: " << endl;
	    m.shortestTrip(deptCity, destCity, departTime, departDate);
	    cout << endl << "Here is your itinerary for the shortest return trip: " << endl;
	    m.shortestTrip(destCity, deptCity, earliestRetTime, retDate);
	    break;
	  case'C':
	    cout << "Here is your itinerary for cheapest trip: " << endl;
	    m.cheapestTrip(deptCity, destCity, departTime, departDate);
	    break;
	  case'P':
	    m.displayAll();
	    break;
	  default:
	    cout<<"Option not recognized"<<endl;
	    break;
	  }
	  //break;
	}
    }
  }
  return 0;
}

