#ifndef TIME_CLASS_H
#define TIME_CLASS_H
#include <ostream>

class Time
{
private:

	// double time keep time in units of hours
	double time;

	// hour_in_day is the number of hours in the day 
	static int hour_in_day;

	// minute_in_hour is the number of minutes in the hour
	static int minute_in_hour;

	// checkbit is assigned to static_cast<int>(time) 
	// which is used to control the display of time for the 
	// ultimate_driver
	static int checkbit;

public:

	/** 
		Time constructor set time = 0.0
		@param none
		@return none 
	*/
	Time();

	/** 
		Time constructor set time in terms of hours  
		@param int minutes
		@return none 
	*/
	Time(int minutes);

	/** 
		Time constructor set time in terms of hours  
		@param double hours
		@return none 
	*/
	Time(double hours);

	/** 
		Time constructor set time in terms of double hours
			and double minutes 
		@param double hours 
		@param double minutes 
		@return none 
	*/
	Time(double hours, double minutes);

	/** 
		~Time deconstructor 
		@param none
		@return none 
	*/
	~Time();

	/** 
		minutes() return times in minutes  
		@param none
		@return static_cast<int>(time * 60)  
	*/
	int minutes();

	/** 
		set_minutes() set minute value to int i
		@param int i
		@return none 
	*/
	void set_minutes(int i);

	/** 
		set_minutes() set minute value to double i
		@param double i
		@return none 
	*/
	void set_minutes(double i);
	
	/** 
		set_hours() set hour value to int i
		@param int i
		@return none 
	*/
	void set_hours(int i);

	/** 
		set_minutes() set hour value to double i
		@param int i
		@return none 
	*/
	void set_hours(double i);

	/** 
		set_hr_in_day() set the number of hours in the day
		@param int i
		@return none 
	*/
	static void set_hr_in_day(int i);

	/** 
		set_min_in_hr() set the number of minutes in the hour
		@param int i
		@return none 
	*/
	static void set_min_in_hr(int i);

	/** 
		operator<< overloading 
		@param ostream& out 
		@param Time& time
		@return Time& time
	*/
	friend std::ostream& operator<<(std::ostream& out, const Time& time);

	/** 
		operator+ overloading 
		@param Time& lhs 
		@param Time& rhs
		@return Time(result)
	*/
	friend Time operator+(const Time& lhs, const Time& rhs);

	/** 
		operator+ overloading 
		@param int add_time 
		@param Time& rhs
		@return Time(result)
	*/
	friend Time operator+(int add_time, const Time& rhs);

	/** 
		operator+ overloading 
		@param double add_time 
		@param Time& rhs
		@return Time(result)
	*/
	friend Time operator+(double add_time, const Time& rhs);

	/** 
		operator+= overloading 
		@param int& i
		@return *this
	*/
	Time& operator+=(const int& i);

	/** 
		operator+ overloading 
		@param double& i
		@return *this
	*/
	Time& operator+=(const double& i);


	/** 
		operator< overloading 
		@param Time& lhs 
		@param Time& rhs
		@return bool (lhs.time < rhs.time)
	*/
	friend bool operator<(const Time& lhs, const Time& rhs);

	/** 
		operator== overloading 
		@param Time& lhs 
		@param Time& rhs
		@return bool (lhs.time == rhs.time)
	*/
	friend bool operator==(const Time& lhs, const Time& rhs);

	/** 
		operator>= overloading 
		@param Time& lhs 
		@param Time& rhs
		@return bool (lhs.time >= rhs.time)
	*/
	friend bool operator>=(const Time& lhs, const Time& rhs);
	
	/** 
		operator!= overloading 
		@param Time& lhs 
		@param Time& rhs
		@return bool (lhs.time != rhs.time)
	*/
	friend bool operator!=(const Time& lhs, const Time& rhs);
};
#endif // TIME_CLASS_H