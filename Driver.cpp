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
	while(!flightSchedule.fail()){
		flightSchedule >> dept;
		flightSchedule >> dest;
		flightSchedule >> deptTime;
		flightSchedule >> arrTime;
		flightSchdule.get(); //Get rid of the $ sign
		flightSchedule >> cost;
		
		// need to find city in Map
		// if depart City doesn't exist, create City, add to Map
		// if depart City does exist, find City, add Flight to that City
		// make sure dest City exists, if not create add
	}
    }
  }

  return 0;
}
