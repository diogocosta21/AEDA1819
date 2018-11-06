/*
 * Data.cpp
 *
 *  Created on: 06/11/2018
 *      Author: joao_
 */

#include "Data.h"


Date::Date(unsigned int d, unsigned int m, unsigned int y) : day(d), month(m), year(y)
{}


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


Date::~Date()
{}


unsigned int Date::getDay() const
{
	return this->day;
}


unsigned int Date::getMonth() const
{
	return this->month;
}


unsigned int Date::getYear() const
{
	return this->year;
}


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
	    if(year % 4 == 0)
	    	convertToDays += 366;
	    else
	    	convertToDays += 365;
	}

	return convertToDays;
}



unsigned int Date::daysBetween (Date d1)
{
	if (this->convertToDays() > d1.convertToDays())
	        return this->convertToDays() - d1.convertToDays();
	    else
	        return d1.convertToDays() - this->convertToDays();
}


bool Date::operator <= (const Date& right) const
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


bool Date::operator ==(const Date& right) const

{
	if(this->day == right.day && this->month== right.month && this->year == right.year)
		return true;

	return false;
}


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


