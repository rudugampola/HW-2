#include "time_class.h"
#include <iostream>
#include <iomanip>
#include "cmath"

int Time::hour_in_day = 24;
int Time::minute_in_hour = 60;
int Time::checkbit = 0;

// Time constructor initliaze time 
Time::Time()
{
	time = 0.00;
}

// Time constructor initliaze time
Time::Time(int minutes)
{
	time = static_cast<double>(minutes) / minute_in_hour;
}

// Time constructor initliaze time
Time::Time(double hours)
{
	time = hours - (floor(hours / hour_in_day) * hour_in_day);
}

// Time constructor initliaze time
Time::Time(double hours, double minutes)
{
	time = (fmod(hours, hour_in_day)) + (minutes / minute_in_hour);
	checkbit = static_cast<int>(time);
}

// Deconstructor
Time::~Time()
= default;

// Return time in minutes
int Time::minutes()
{
	return static_cast<int>(time * minute_in_hour);
}

// Set minutes in time to int i
void Time::set_minutes(int i)
{
	double hours;
	double frac = modf(time, &hours);
	time = time - frac;

	if (frac >= 0.9999999)
	{
		hours += 1;
		frac = 0;
	}

	time = hours + round((i % minute_in_hour)) / minute_in_hour;
}

// Set minutes in time to double i
void Time::set_minutes(double i)
{
	double hours;
	double frac = modf(time, &hours);
	time = time + (fmod(i, minute_in_hour) / minute_in_hour) - frac;
}

// Set hours in time to int i
void Time::set_hours(int i)
{
	double hours;
	double frac = modf(time, &hours);
	time = time + static_cast<double>(i % hour_in_day) - hours;
}

// Set hours in time to double i
void Time::set_hours(double i)
{
	double hours;
	double frac = modf(time, &hours);
	time = time - hours + floor(i);
}

// Set hour_in_day to int i
void Time::set_hr_in_day(int i)
{
	hour_in_day = i;
}

// Set minute_in_hour to int i
void Time::set_min_in_hr(int i)
{
	minute_in_hour = i;
}

// Operator<< overloading
std::ostream& operator<<(std::ostream& out, const Time& time)
{
	double altTime = time.time;

	if (Time::checkbit == 23)
	{
		altTime = (altTime * 60)/time.minute_in_hour;  
	}

	double hours;
	double frac = modf(altTime, &hours);

	if (frac >= 0.9999999)
	{
		hours += 1;
		frac = 0;
	}

	double min = round(frac * time.minute_in_hour);
	out << hours << ":" << std::setfill('0') << std::setw(2) << min;
	return out;
}

// Operator+ overloading
Time operator+(int add_time, const Time& rhs)
{
	double result = rhs.time + (static_cast<double>(add_time) / rhs.minute_in_hour
	);
	return Time(result);
}

// Operator+ overloading
Time operator+(double add_time, const Time& rhs)
{
	double result = rhs.time + add_time;
	return Time(result);
}

// Operator+ overloading
Time operator+(const Time& lhs, const Time& rhs)
{
	return Time(rhs.time + lhs.time);
}

// Operator+= overloading
Time& Time::operator+=(const int& i)
{
	this->time = this->time + (static_cast<double>(i) / minute_in_hour);
	return *this;
}

// Operator+= overloading
Time& Time::operator+=(const double& i)
{
	this->time = this->time + i;
	return *this;
}

// Operator< overloading
bool operator<(const Time& lhs, const Time& rhs)
{
	return lhs.time < rhs.time;
}

// Operator== overloading
bool operator==(const Time& lhs, const Time& rhs)
{
	return lhs.time == rhs.time;
}

// Operator>= overloading
bool operator>=(const Time& lhs, const Time& rhs)
{
	return lhs.time >= rhs.time;
}

// Operator!= overloading
bool operator!=(const Time& lhs, const Time& rhs)
{
	return lhs.time != rhs.time;
}