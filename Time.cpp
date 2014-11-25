#include "Time.h"

Time::Time(){
  cout << "Called Time::Time() [default constructor]" << endl;
  time = 0;
}

Time::Time(int t){
  cout << "Called Time::Time(int) [value constructor]" << endl;
  time = t;
}

int Time::asInt(){
  cout << "Called Time::asInt()" << endl;
  return time;
}

Time& Time::operator=(const Time &t){
  cout << "Called Time::operator= [assignment operator]" << endl;
  time = t.time;
  return *this;
}

Time Time::operator+(const Time &t){
  cout << "Called Time::operator+" << endl;
  Time result;
  int resultMin = (this->time%100) + (t.time%100);
  int resultHr = (this->time/100) + (t.time/100);
  
  // correct for minute overflow
  if(resultMin >= 60){
    resultHr += resultMin / 60;
    resultMin %= 60; 
  }
  // correct for hour overflow
  if(resultHr >= 24){
    resultHr %= 24;
  }
  // set new time
  result.time = (resultHr*100) + resultMin;
  
  return result;
}

Time Time::operator-(const Time &t){
  cout << "Called Time::operator-" << endl;
  Time result;
  int resultMin = (this->time%100) - (t.time%100);
  int resultHr = (this->time/100) - (t.time/100);
  
  // correct for minute underflow
  if(resultMin < 0){
    resultHr--;
    resultMin += 60; 
  }
  // correct for hour underflow
  if(resultHr < 0){
    resultHr += 24;
  }
  // set new time
  result.time = (resultHr*100) + resultMin;
  
  return result;
}

bool Time::operator<(const Time &right) const{
  cout << "Called Time::operator<" << endl;
  return this->time < right.time;
}

bool Time::operator>(const Time &right) const{
  cout << "Called Time::operator>" << endl;
  return this->time > right.time;
}

bool Time::operator>=(const Time &right) const{
  cout << "Called Time::operator>=" << endl;
  return !operator<(right);
}

bool Time::operator<=(const Time &right) const{
  cout << "Called Time::operator<=" << endl;
  return !operator>(right);
}

bool Time::operator==(const Time &right) const{
  cout << "Called Time::operator==" << endl;
  return this->time == right.time;
}

bool Time::operator!=(const Time &right) const{
  cout << "Called Time::operator!=" << endl;
  return !operator==(right);
}

istream& operator>>(istream &in, Time &t){
  //cout << "Called friend istream& operator>> [Time]" << endl;
  int hour = 0;
  int min = 0;
  char c;
  // get hour
  in.get(c);
  if(isdigit(c))
    hour += (c-'0')*10;
  else
    cout << "Error: not valid time" << endl; //maybe to cerr
  in.get(c);
  if(isdigit(c))
    hour += (c-'0');
  else
    cout << "Error: not valid time" << endl; //maybe to cerr
  // get :
  in.get(c);
  // get minute
  in.get(c);
  if(isdigit(c))
    min += (c-'0')*10;
  else
    cout << "Error: not valid time" << endl; //maybe to cerr
  in.get(c);
  if(isdigit(c))
    min += (c-'0');
  else
    cout << "Error: not valid time" << endl; //maybe to cerr
  // get am/pm
  in.get(c);
  if(isalpha(c))
    if( (c == 'p') || (c == 'P') )
      hour += 12;
  // clear in
  in.ignore(256, '\n');
  in.clear();
  
  // set time
  t.time = (hour*100) + min;

  return in;
}

ostream& operator<<(ostream &out, const Time &t){
  //cout << "Called friend ostream& operator<< [Time]" << endl;
  // output format HH:MMam or HH:MMpm
  int min = t.time % 100;
  int hr = t.time / 100;
  bool am = true;
  // check if am or pm, set flag accordingly
  if(hr > 12){
    am = false;
  }
  // output hour
  if(am){
    // make sure output has 2 digits (helps with >>)
    if(hr >= 10)
      out << hr;
    else
      out << "0" << hr;
  }
  else{
    // make sure output has 2 digits (helps with >>)
    if(hr-12 >= 10)
      out << hr-12;
    else
      out << "0" << hr-12;
  }
  // output :
  out << ":";
  // output minute
  // make sure output has 2 digits (helps with >>)
  if(min >= 10)
    out << min;
  else
    out << "0" << min;
  // output am/pm
  if(am)
    out << "am";
  else
    cout << "pm";
  out << endl;

  return out;
}

Time::~Time(){
  cout << "Called Time::~Time() [destructor]" << endl;
}
