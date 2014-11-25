#include "Time.h"

int main(){
  
  Time test1, test3;
  int duration;
  
  while(cin.good()){
    cout << "Enter a time: ";
    cin >> test1;
    if(!cin.good()) break;
    cout << "You entered: " << test1 << endl;
    
    cout << "Enter a duration: ";
    cin >> duration;
    //cout << "You entered: " << duration << endl;
    Time test2(duration);
    cout << "You entered: " << test2.asInt() << endl;
    cout << "In time: " << test2 << endl; 
    
    cout << "sum: " << test1 + test2 << endl;
    cout << "diff: " << test1 - test2 << endl;
    
    cout << "Enter a second time: ";
    cin >> test3;
    cout << test1 << " is before " << test3 << ": ";
    if(test1 < test3)
      cout << "true" << endl;
    else
      cout << "false" << endl;
    
  }  
  return 0;
}
