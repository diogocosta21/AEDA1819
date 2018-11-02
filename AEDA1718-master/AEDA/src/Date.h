/*
 * Date.h
 *
 *  Created on: 14/11/2017
 *      Author: ricar
 */

#ifndef AEDA_SRC_DATE_H_
#define AEDA_SRC_DATE_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


class Date {
private:
	/**
	 * @brief  date's day
	 */
	unsigned int day;
	/**
	 * @brief date's month
	 */
	unsigned int month;
	/**
	 * @brief date's year
	 */
	unsigned int year;
public:
	Date(){};
	Date (unsigned int d, unsigned int m, unsigned int y);
	Date (string date);
	virtual ~Date();
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
	unsigned int convertToDays();
	unsigned int daysBetween (Date d1);
	bool operator<= (const Date& right) const;
	bool operator==(const Date& right) const;
	bool validateDate();
};


#endif /* AEDA_SRC_DATE_H_ */
