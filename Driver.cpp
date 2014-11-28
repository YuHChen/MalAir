#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Time.h"
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

		// need to find city in Map
		// if depart City doesn't exist, create City, add to Map
		// if depart City does exist, find City, add Flight to that City
		// make sure dest City exists, if not create add
	}
	cout << m << endl;

	//Asking the User what method they want to perform. 
	cout<<"Trip Constraints Menu:[J,F,C,S,P]"<<endl;
	cout<<"Select option for more information"<<endl;
	char option;
	//Should I check input?
	while(!std::isdigit(option)){
		cin>>option;

		//Is this too much?
		switch(option){
			case'J':
				cout<<"An itenerinary from a departure city "<<
				"to a destination city. (No contraints)"<<endl;
			break;

			case'F':
				cout<<"An itinerary that can get from a departure city "<<
				"to a destination city with the "<<'\n'<<
				"fewest direct flight components"<<endl;
			break;

			case'S':
				cout<<"Minimizes the time between leaving from the departure "<<
				" and arriving at the destination city."<<'\n'<<
				"Also minimizes the time between return from the destination "<<
				"city and arriving back at the" <<'\n'<<
				"departure city"<<endl;
			break;

			case'C':
				cout<<"Find the cheapest(potentially multi hop) that meets "
				<<" the specified constraints."<<endl;
			break;

			case'P':
				cout<<"Displays entire flight schedule."<<endl;
			break;

			default:
			 cout<<"Option not recognized"<<endl;
			break;
		}
	}
    }
  }

  return 0;
}
