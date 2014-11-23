#include "Time.h"

int main(){
  Time test1;
  cout << "Enter a time: ";
  cin >> test1;
  cout << "You entered: " << test1 << endl;

  int duration;
  cout << "Enter a duration: ";
  cin >> duration;
  //cout << "You entered: " << duration << endl;
  Time test2(duration);
  cout << "You entered: " << test2.asInt() << endl;
  cout << "In time: " << test2 << endl; 

  cout << "sum: " << test1 + test2 << endl;
  cout << "diff: " << test1 - test2 << endl;
}
