#include "Time.h"

Time::Time(){
  //cout << "Called Time::Time() [default constructor]" << endl;
  time = 0;
}

Time::Time(int t){
  //cout << "Called Time::Time(int) [value constructor]" << endl;
  time = t;
}

int Time::asInt(){
  //cout << "Called Time::asInt()" << endl;
  return time;
}

Time& Time::operator=(const Time &t){
  //cout << "Called Time::operator= [assignment operator]" << endl;
  time = t.time;
  return *this;
}

Time Time::operator+(const Time &t){
  //cout << "Called Time::operator+" << endl;
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
  //cout << "Called Time::operator-" << endl;
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
  //cout << "Called Time::operator<" << endl;
  return this->time < right.time;
}

bool Time::operator>(const Time &right) const{
  //cout << "Called Time::operator>" << endl;
  return this->time > right.time;
}

bool Time::operator>=(const Time &right) const{
  //cout << "Called Time::operator>=" << endl;
  return !operator<(right);
}

bool Time::operator<=(const Time &right) const{
  //cout << "Called Time::operator<=" << endl;
  return !operator>(right);
}

bool Time::operator==(const Time &right) const{
  //cout << "Called Time::operator==" << endl;
  return this->time == right.time;
}

bool Time::operator!=(const Time &right) const{
  //cout << "Called Time::operator!=" << endl;
  return !operator==(right);
}

istream& operator>>(istream &in, Time &t){
  //cout << "Called friend istream& operator>> [Time]" << endl;
  int hour = 0;
  int min = 0;
  bool colon = false;
  char c;

  // get hour
  in >> std::skipws >> c;
  if(!in.good()) return in; // exit if end of file
  if(isdigit(c)) 
    hour += (c-'0')*10;
  else 
    cout << "Error: not valid time, received: " << c << endl; //maybe to cerr
  in >> std::skipws >> c; // should be second digit of hour or :
  if(isdigit(c))
    hour += (c-'0');
  else if(c == ':'){ // only one digit for hour
    hour /= 10;
    colon = true;
  }
  else
    cout << "Error: not valid time, received: " << c << endl; //maybe to cerr
  
  // get : if still in stream
  if(!colon)
    in >> std::skipws >> c;
  
  // get minute
  in >> std::skipws >> c;
  if(isdigit(c))
    min += (c-'0')*10;
  else
    cout << "Error: not valid time, received: " << c << endl; //maybe to cerr
  in >> std::skipws >> c;
  if(isdigit(c))
    min += (c-'0');
  else
    cout << "Error: not valid time, received: " << c << endl; //maybe to cerr

  // get am/pm
  in >> std::skipws >> c;
  if(isalpha(c)){
    if( (c == 'p') && (hour < 12) ) 
      hour += 12;	
    else if( (c == 'a') && (hour == 12) )
      hour += 12;
  }
  in >> std::skipws >> c;

  // adjust for hour overflow
  if(hour >= 24)
    hour %= 24;
  
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
  if( (hr >= 12) && (hr < 24) ){
    am = false;
  }

  // output hour HH
  if(am){
    if(hr == 0) // 00:00 to 00:59
      out << 12;
    else // 01:00 +
      out << hr;
    
  }
  else{ // pm
    if(hr == 12) // 12:00 to 12:59
      out << hr; 
    else // 13:00 +
      out << hr%12; 
  }

  // output the :
  out << ":";

  // output minute MM
  // make sure output has 2 digits (helps with >>)
  if(min/10 > 0)
    out << min;
  else
    out << "0" << min;

  // output am/pm
  if(am)
    out << "am";
  else
    out << "pm";

  return out;
}

Time::~Time(){
  //cout << "Called Time::~Time() [destructor]" << endl;
}
