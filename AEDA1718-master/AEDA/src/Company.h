/*
 * Company.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_COMPANY_H_
#define SRC_COMPANY_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>

using namespace std;

#include "BST.h"
#include "Client.h"
#include "Supplier.h"
#include "Offer.h"
#include "Reservation.h"


struct InactiveClients
{
	int operator() (const Client* c1) const
	{
		string s1 = c1->getName();

		int v = 0;
		for ( unsigned int i=0; i< s1.size(); i++ )
		 v = 37*v + s1[i];
		return v;

	}

	bool operator() (const Client *c1, const Client *c2) const
	{
		return c1 == c2;
	}
};

typedef unordered_set<Client*,InactiveClients , InactiveClients> tabHInactive;

class Company {
private:
	/**
	 * @brief Vector all registered clients.
	 */
	vector <RegisteredClient *> rClients;
	/**
	 * @brief Vector with all occasional clients.
	 */
	vector <OccasionalClient *> oClients;
	/**
	 * @brief Vector with all suppliers.
	 */
	vector <Supplier *> suppliers;
	/**
	 * @brief Vector with all offers.
	 */
	vector <Offer *> offers;
	/**
	 * @brief Current date.
	 */
	Date date;
	/**
	 * @brief binary search tree with all reservations
	 */
	BST <Reservation> reservations;
	/**
	 * @brief unpopular offers which haven't been booked in more than a month
	 */
	priority_queue <Offer >  UnpopularOffers;
	/**
	 * @brief inactive clients who haven't booked any reservation in more than a month.
	 */
	tabHInactive inactiveClients;
	/**
	 * @brief Money gained by 'Porto Rivers' with the reservations.
	 */
	double bank;
public:
	Company(vector<RegisteredClient *> rClients, vector<OccasionalClient *> oClients, vector<Supplier *> suppliers, vector<Offer *> offers, vector <Reservation> reserv);
	virtual ~Company();
	void exportRegisteredClients(string file);
	void exportOccasionalClients(string file);
	void exportSuppliers (string file);
	void exportOffers (string file);
	void exportReservations (string file);
	unsigned int RegisterClient(string name, int NIF, string address);
	void AddSupplier(string n, int NIF, string address);
	void addOccasionalClient (string name, int NIF, string address);
	void addOffer(unsigned int price, unsigned int dist, unsigned int cap, unsigned int points, double perc, string bT, string dest, string supName, Date d);
	void removeOccasionalClient(int id);
	vector <RegisteredClient *> getRegisteredClients () const;
	vector <OccasionalClient *> getOccasionalClients () const;
	vector <Supplier *> getSuppliers () const;
	vector <Offer *> getOffers () const;
	BST <Reservation> getReservations() const;
	Date getDate() const;
	void addReservation(const Reservation &r, unsigned int nTick);
	vector <Reservation> setClientsonReservations (vector <Reservation> r);
	int removeReservation (const Reservation &r, unsigned int nTick);
	void removeInactiveClient (string name);
	bool searchInactiveClient (string name);
	void updateAddressClient (string name, string newAddress);
	void removeUnpopularOffer (unsigned int offerId);
	void updateDiscounts();
	double getBank() const;
	void setBank (double b);
	void setOfferSuppliers();
	void printRegisteredClients() const;
	void printRegisteredClientByPoints() const;
	void printOccasionalClients() const;
	void printClientsByOffer (unsigned int idOffer) const;
	void printSuppliers() const;
	void printOffers() const;
	vector<int> printOfferbyDate (Date d1, Date d2) const;
	void printOffersBySuppliers(string name) const;
	bool printOffersByClient (string cName) const;
	void printReservations () const;
	void printInactiveClients () const;
	void printUnpopularOffers () const;
};

#endif /* SRC_COMPANY_H_ */
