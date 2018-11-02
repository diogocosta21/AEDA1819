/*
 * Reservation.h
 *
 *  Created on: 21/12/2017
 *      Author: ricar
 */

#ifndef _RESERVATION_H_
#define _RESERVATION_H_

using namespace std;

#include "Offer.h"
#include "Client.h"

class Reservation {
private:
	/**
	 * @brief client who made the resevation.
	 */
	Client *client;
	/**
	 * @brief date of the offer.
	 */
	Date date;
	/**
	 * @brief id of the reservation.
	 */
	unsigned int id;
	/**
	 * @brief name of the client.
	 */
	string clientName;
	/**
	 * @brief id of the offer that was booked.
	 */
	unsigned int offer;
	/**
	 * @brief number of tickets purchased.
	 */
	unsigned int nTick;
public:
	/**
	 * The constructor used to initialize the binary search tree.
	 */
	Reservation(){};
	Reservation(Offer *o1, RegisteredClient* c1, Date d1);
	Reservation(Offer *o1, OccasionalClient* c1, Date d1);
	Reservation(string cName, unsigned int OfferID, Date d1, unsigned int nT);
	virtual ~Reservation();
	void setClient (Client *c);
	void setTickets (unsigned int newValue);
	Client * getClient () const;
	string getClientName () const;
	unsigned int getOffer() const;
	Date getDate () const;
	unsigned int getId() const;
	unsigned int getTickets() const;

	friend ostream &operator<< (ostream &os, Reservation &r1);
	bool operator< (const Reservation & r2) const;
	bool operator== (const Reservation & r2) const;
};


#endif /* AEDA_SRC_RESERVATION_H_ */
