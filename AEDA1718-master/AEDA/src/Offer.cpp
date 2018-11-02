/*
 * Offer.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Offer.h"

static unsigned int offerID = 1;

/**
 * The normal constructor.
 * @param pri price.
 * @param dist distance.
 * @param capacity capacity.
 * @param bT boat type.
 * @param dest destination.
 * @param sName supName.
 * @param points points.
 * @param percentage which is gonna be divided by 100, converting it to a decimal number.
 * @param d date.
 * @param lR date in which the client made his last reservation.
 */
Offer::Offer(int pri, int dist, int capacity, string bT, string dest, string sName, unsigned int points, double percentage, Date d, Date lR):
		price(pri), distance(dist), boatType (bT), destination(dest), supName(sName), date(d), lastReservation (lR)
{
	this->points=points;
	this->capacity = capacity;
	this->percentage = percentage/100;
	vacancies = capacity;
	this->discount = 0;
	id = offerID;
	offerID++;
}

/**
 * The destructor.
 */
Offer::~Offer() {

}


/**
 * @return price.
 */
unsigned int Offer::getPrice() const
{
	return price;
}

/**
 * @return id.
 */
unsigned int Offer::getId() const
{
	return id;
}

/**
 * Resets global variable offerID to 1.
 */
void Offer::resetId()
{
	offerID = 1;
}

/**
 * @return distance.
 */
unsigned int Offer::getDistance() const
{
	return distance;
}

/**
 * @return capacity.
 */
unsigned int Offer::getCapacity() const
{
	return capacity;
}

/**
 * @return vacancies.
 */
unsigned int Offer::getVacancies() const
{
	return vacancies;
}

/**
 * @return lastReservation.
 */
Date Offer::getLastReservation() const
{
	return lastReservation;
}

/**
 * Updates vacancies.
 * @param newValue updated value of vacancies.
 */
void Offer::setVacancies(unsigned int newValue)
{
	vacancies = newValue;
}

/**
 * @return points.
 */
unsigned int Offer::getPoints() const
{
	return points;
}

/**
 * @return date.
 */
Date Offer::getDate() const
{
	return date;
}

/**
 * Changes lastReservation to the current date and discount to 0.
 */
void Offer::setLastReservation(const Date &newDate)
{
	this->lastReservation = newDate;

	discount = 0;
}

/**
 * @return percentage.
 */
double Offer::getPercentage() const
{
	return percentage;
}

/**
 * @return offer's discount.
 */
double Offer::getDiscount() const
{
	return discount;
}

/**
 * Updates the discount value.
 * @param newValue discount new value.
 */
void Offer::setDiscount(double newValue)
{
	discount = newValue;
}

/**
 * @return boat type.
 */
string Offer::getBoatType() const
{
	return boatType;
}

/**
 * @return destination.
 */
string Offer::getDestination() const
{
	return destination;
}

/**
 * @return string with the offer's information.
 */
string Offer::getInformation() const
{
	stringstream ss;
	Date d1 = getDate();

	ss << getId() << " " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << ", " <<  getSupName() << ", " << getDestination() << ", " << getDistance() << "km, " <<  getBoatType() << ", " << ( getPrice() - getPrice() * getDiscount() ) << "€ "
			<< "//  seats available: " << getVacancies() << endl << "Points / ticket : " << getPoints() << " (only available for registered clients)" << endl;

	return ss.str();
}

/**
 * @return supName.
 */
string Offer::getSupName() const
{
	return supName;
}

/**
 * @return sup.
 */
Supplier * Offer::getSupplier() const
{
	return sup;
}

/**
 * Sets supplier equal to s.
 *  @param s new supplier.
 */
void Offer::setSupplier(Supplier * s)
{
	sup=s;
}

/** Writes to ofstream the offer's information in the format used in text files.

 * @param os ofstream where is stored the information.
 * @param o1 offer which information is going to be read.
 */
ostream &operator<< (ostream &os, Offer &o1)
{
	double perc = o1.getPercentage() * 100;
	Date d1 = o1.getDate();

	os << o1.getId()  << ", " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() <<  ", " <<  o1.getSupName() << ", " << o1.getPrice() << ", " << o1.getDistance() << ", " << o1.getVacancies() << ", " <<
			o1.getBoatType() << ", " << o1.getDestination() << ", " << o1.getPoints() << ", " << perc << ", "
			<< o1.getLastReservation().getDay() << "/" << o1.getLastReservation().getMonth() << "/" << o1.getLastReservation().getYear() << ";";

	return os;
}

/**
 * Overload of operator<.
 * @param o2 offer to compare.
 * @return true if o2's last reservation is closer to current date or otherwise returns false.
 */
bool Offer::operator< (const Offer &o2) const
{
	return o2.getLastReservation() <= this->lastReservation;
}

/**
 * Overload of operator ==
 * @param o2 offer to compare.
 * @return true if the offers have the same id or false if they dont.
 */
bool Offer::operator== (const Offer &o2) const
{
	return id == o2.getId();
}

