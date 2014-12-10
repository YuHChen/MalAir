#include <iostream>

#include "Date.h"

int main(){

  Date d(2,12,2014);

  cout << d << endl;

  Date input;
  cout << "Enter date (DD/MM/YYYY): ";
  cin >> input;
  cout << "You entered: " << input << endl;

  return 0;

}
