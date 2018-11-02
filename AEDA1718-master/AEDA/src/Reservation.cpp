/*
 * Reservation.cpp
 *
 *  Created on: 21/12/2017
 *      Author: ricar
 */

#include "Reservation.h"

using namespace std;

static unsigned int reservation_ID = 1;

/**
 * The constructor for registered clients.
 * @param o1 offer that has been booked.
 * @param c1 client that made the reservation.
 * @param d1 date of the offer.
 */
Reservation::Reservation(Offer* o1, RegisteredClient *c1, Date d1)
{
	this->offer = o1->getId();
	this->client= c1;
	this->date = d1;
	id = reservation_ID;
	reservation_ID++;
}

/**
 * The constructor for occasional clients.
 * @param o1 offer that has been booked.
 * @param c1 client that made the reservation.
 * @param d1 date of the offer.
 */
Reservation::Reservation(Offer* o1, OccasionalClient *c1, Date d1)
{
	this->offer = o1->getId();
	this->client = c1;
	this->date = d1;
	id = reservation_ID;
	reservation_ID++;
}

/**
 * The constructor used while reading the reservations' text file.
 * @param cName name of the client that made the reservation.
 * @param offerId id of the offer that has been booked.
 * @param d1 date of the offer.
 * @param nT number of tickets purchased.
 */
Reservation::Reservation(string cName, unsigned int offerId, Date d1, unsigned int nT)
{
	this->offer = offerId;
	this->clientName = cName;
	this->date = d1;
	this->nTick = nT;
	id = reservation_ID;
	reservation_ID++;
}

/**
 * The destructor.
 */
Reservation::~Reservation()
{

}

/**
 * Updates client.
 */
void Reservation::setClient(Client * c)
{
	client=c;
}

/**
 * Updated the number of tickets purchased.
 */
void Reservation::setTickets(unsigned int newValue)
{
	this->nTick = newValue;
}

/**
 * Overload of the operator <.
 * @param r2 reservation to be compared.
 * @return true or false according to the clients' name alphabetical order. If they have the same name, then returns true or false according to the date of both reservations.
 */
bool Reservation::operator<(const Reservation & r2) const {
	if (getClient()->getName() == r2.getClient()->getName())
		return this->getDate() <= r2.getDate();

	return this->getClient()->getName() < r2.getClient()->getName();
}

/**
 * Overload of the operator ==.
 * @param r2 reservation to be compared.
 * @return true if both reservations have the same client, offer and date, or false otherwise.
 */
bool Reservation::operator ==(const Reservation &r2) const
{
	if (this->client == r2.getClient())
		if (this->date == r2.getDate())
			if (this->getOffer() == r2.getOffer())
				return true;
	return false;

}

/**
 * @return client.
 */
Client * Reservation::getClient() const
{
	return this->client;
}

/**
 * @return client's name.
 */
string Reservation::getClientName() const
{
	return this->clientName;
}

/**
 * @return offer.
 */
unsigned int Reservation::getOffer() const
{
	return this->offer;
}

/**
 * @return date.
 */
Date Reservation::getDate() const
{
	return this->date;
}

/**
 * @return reservation's id.
 */
unsigned int Reservation::getId() const
{
	return this->id;
}

/**
 * @return number of tickets purchased.
 */
unsigned int Reservation::getTickets() const
{
	return this->nTick;
}

/**
 * Overload of operator <<.
 * @param os ostream where is stored the information.
 * @param r1 reservation which information is going to be stored.
 */
ostream &operator<< (ostream &os, Reservation &r1)
{
	os << r1.getId() << ", " << r1.getDate().getDay() << "/" << r1.getDate().getMonth() << "/" << r1.getDate().getYear() << ", " << r1.getClient()->getName()
			<< ", " << r1.getOffer() << ", " << r1.getTickets() << ";" ;
}

