#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <cctype>

using namespace std;

class Time
{
 private:
  int time;
  
 public:
  Time();
  Time(int t);

  int asInt();
  Time& operator=(const Time &t);
  Time operator+(const Time &t);
  Time operator-(const Time &t);
  bool operator<(const Time &right) const;
  bool operator>(const Time &right) const;
  bool operator>=(const Time &right) const;
  bool operator<=(const Time &right) const;
  bool operator==(const Time &right) const;
  bool operator!=(const Time &right) const;
  friend istream& operator>>(istream &in, Time &t);
  friend ostream& operator<<(ostream &out, const Time &t);

  ~Time();
};

#endif
