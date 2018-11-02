/*
 * Date.cpp
 *
 *  Created on: 14/11/2017
 *      Author: ricar
 */

#include "Date.h"


/**
 * Constructor from integers.
 * @param d day.
 * @param m month.
 * @param y year.
 */
Date::Date(unsigned int d, unsigned int m, unsigned int y) : day(d), month(m), year(y)
{}

/**
 * Constructor from string.
 * @param date string in DD-MM-YYYY format.
 *
 */
Date::Date(string date)
{
	string d = date.substr(0, date.find('-'));
	date = date.substr(date.find('-') + 1);
	string m = date.substr(0, date.find('-'));
	date = date.substr(date.find('-') + 1);

	day = (unsigned int) stoi(d.c_str());
	month = (unsigned int) stoi(m.c_str());;
	year = (unsigned int) stoi(date.c_str());;

}
/**
 * The destructor.
 */
Date::~Date()
{}

/**
 * @return day.
 */
unsigned int Date::getDay() const
{
	return this->day;
}

/**
 * @return month.
 */
unsigned int Date::getMonth() const
{
	return this->month;
}

/**
 * @return year.
 */
unsigned int Date::getYear() const
{
	return this->year;
}

/**
 * Converts a date to number of days.
 */
unsigned int Date::convertToDays ()
{
	int convertToDays = 0;
	int daysInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	convertToDays += day;
	for (int i = month-1; i > 0; i--)
	{
	    convertToDays += daysInMonth[i];
	}
	for (int i = year-1; i > 1582; i--)
	{
	    if(year % 100 == 0)
	    {
	        if(year % 400 == 0)
	            convertToDays += 366;
	        else
	            convertToDays += 365;
	    }
	    else
	    {
	        if(year % 4 == 0)
	            convertToDays += 366;
	         else
	            convertToDays += 365;
	    }
	}

	return convertToDays;
}
/**
 * @return number of days between two dates.
 * @param d1 date to be compared.
 *
 */
unsigned int Date::daysBetween (Date d1)
{
	if (this->convertToDays() > d1.convertToDays())
	        return this->convertToDays() - d1.convertToDays();
	    else
	        return d1.convertToDays() - this->convertToDays();
}

/**
 * Checks if date is before or equal to right one.
 * @param right date to compare.
 */
bool Date::operator<= (const Date& right) const
{
	vector<int> l,r;

	l.push_back(this->year);
	l.push_back(this->month);
	l.push_back(this->day);
	r.push_back(right.year);
	r.push_back(right.month);
	r.push_back(right.day);

	if (l == r)
		return true;

	for(unsigned int i = 0; i < l.size(); i++)
	{
		if(l[i] < r[i])
			return true;
		else if(l[i] > r[i])
			return false;
	}

	return false;
}

/**
 * Checks if two dates are the equal.
 * @param right date to compare.
 */
bool Date::operator==(const Date& right) const

{
	if(this->day == right.day && this->month== right.month && this->year == right.year)
		return true;

	return false;
}

/**
 * Checks if date is valid.
 */
bool Date::validateDate()
{
	if(month < 0 || month > 12)
		return false;
	if(day < 0 || day > 31)
		return false;
	if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if(month == 2 && year%4 == 0 && day > 29)
		return false;

	if(month == 2 && year%4 != 0 && day > 28)
		return false;

	return true;
}
