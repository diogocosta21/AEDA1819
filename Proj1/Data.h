/*
 * Data.h
 *
 *  Created on: 06/11/2018
 *      Author: joao_
 */

#ifndef DATA_H_
#define DATA_H_


#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


class Date {
private:
	unsigned int day;
	unsigned int month;
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


#endif /* DATA_H_ */
