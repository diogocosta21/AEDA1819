/*
 * Offer.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_OFFER_H_
#define SRC_OFFER_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

#include "Supplier.h"
#include "Client.h"
#include "Date.h"

class Offer {
private:
	/**
	 * @brief offer's id.
	 */
	unsigned int id;
	/**
	 * @brief offer's price.
	 */
	unsigned int price;
	/**
	 * @brief offer's distance.
	 */
	unsigned int distance;
	/**
	 * @brief offer's boat's capacity.
	 */
	unsigned int capacity;
	/**
	 * @brief offer's vacancies.
	 */
	unsigned int vacancies;
	/**
	 * @brief offer's points per ticket bought.
	 */
	unsigned int points;
	/**
	 * @brief percentage of each reservation that goes to 'Porto Rivers'.
	 */
	double percentage;
	/**
	 * @brief offer's boat type.
	 */
	string boatType;
	/**
	 * @brief offer's destination.
	 */
	string destination;
	/**
	 * @brief offer's supplier's name.
	 */
	string supName;
	/**
	 * @brief offer's supplier.
	 */
	Supplier * sup;
	/**
	 * @brief offer's date.
	 */
	Date date;
	/**
	 * @brief Current discount for this offer.
	 */
	double discount;
	/**
	 * @brief Date in which the offer was booked for the last time.
	 */
	Date lastReservation;
public:
	/**
	 * The constructor used to initialize the binary search tree.
	 */
	Offer(){};
	Offer (int pri, int dist,int capacity, string bT, string dest, string sName, unsigned int points, double percentage, Date d, Date lR);
	virtual ~Offer();
	unsigned int getId() const;
	void resetId ();
	unsigned int getPrice() const;
	unsigned int getDistance() const;
	unsigned int getCapacity() const;
	unsigned int getVacancies() const;
	Date getLastReservation () const;
	void setVacancies (unsigned int newValue);
	unsigned int getPoints() const;
	Date getDate() const;
	void setLastReservation (const Date &newDate);
	double getPercentage() const;
	double getDiscount() const;
	void setDiscount (double newValue);
	string getBoatType () const;
	string getDestination() const;
	string getInformation() const;
	string getSupName() const;
	Supplier * getSupplier() const;
	void setSupplier(Supplier *  s);
	friend ostream &operator<< (ostream &os, Offer &o1);
	bool operator< (const Offer &o2) const;
	bool operator == (const Offer &o1) const;

};

#endif
