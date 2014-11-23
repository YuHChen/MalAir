#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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
      
      // read flight schedule into graph
      // flightSchedule >> flightGraph ???
    
    }
  }

  return 0;
}
