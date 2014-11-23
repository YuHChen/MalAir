#ifndef TIME_H
#define TIME_H

class Time
{
	private:
		int time;

	public:
		Time();


		friend Time operator >(const Time &t);
		friend Time operator <(const Time &t);
		friend Time operator >=(const Time &t);
		friend Time operator <=(const Time &t);
		friend Time operator ==(const Time &t);
		friend Time operator !=(const Time &t);
		friend istream&(istream &in, Time &t);
		friend ostream&(ostream &out, const Time &t);
};

#endif
