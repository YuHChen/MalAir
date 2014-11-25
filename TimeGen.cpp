#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  
  string am("am");
  string pm("pm");

  int hour = 12;
  int min = 0;

  string filename("times.txt");
  ofstream times(filename.c_str());
  
  if(times.fail()){
    cout << "Could not create times.txt" << endl;
    return 0;
  }

  // 12:00am to 12:59am
  while(min < 60){
    if(min/10 > 0)
      times << hour << ":" << min << am << endl;
    else
      times << hour << ":0" << min << am << endl;
    
    times << 1 << endl;
    
    if(min/10 > 0){
      times << hour << ":" << min << am << endl;
    }
    else
      times << hour << ":0" << min << am << endl;
    
    min++;
  }

  // 1:00am to 11:59am
  hour = 1;
  min = 0;
  while(hour < 12){
    if(hour/10 > 0)
      times << hour;
    else
      times << "0" << hour;
    if(min/10 > 0)
      times << ":" << min << am << endl;
    else
      times << ":0" << min << am << endl;
    
    times << 1 << endl;

    if(hour/10 > 0)
      times << hour;
    else
      times << "0" << hour;
    if(min/10 > 0)
      times << ":" << min << am << endl;
    else
      times << ":0" << min << am << endl;
    
    min++;
    if(min % 60 == 0){
      min %= 60;
      hour++;
    }
  }

  // 12:00pm to 12:59pm
  while(min < 60){
    if(min/10 > 0)
      times << hour << ":" << min << pm << endl;
    else
      times << hour << ":0" << min << pm << endl;

    times << 1 << endl;

    if(min/10 > 0)
      times << hour << ":" << min << pm << endl;
    else
      times << hour << ":0" << min << pm << endl;

    min++;
  }

  // 1:00pm to 11:59pm
  hour = 1;
  min = 0;
  while(hour < 12){
    if(hour/10 > 0)
      times << hour;
    else
      times << "0" << hour;
    if(min/10 > 0)
      times << ":" << min << pm << endl;
    else
      times << ":0" << min << pm << endl;

    times << 1 << endl;
    
    if(hour/10 > 0)
      times << hour;
    else
      times << "0" << hour;
    if(min/10 > 0)
      times << ":" << min << pm << endl;
    else
      times << ":0" << min << pm << endl;
    
    min++;
    if(min % 60 == 0){
      min %= 60;
      hour++;
    }
  }
  
}
