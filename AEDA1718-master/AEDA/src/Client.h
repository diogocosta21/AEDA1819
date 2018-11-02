/*
 * Client.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include <string>
#include <sstream>
#include "Date.h"

using namespace std;

class Client {
private:
	/**
	 * @brief Client's name.
	 */
	string name;
	/**
	 * @brief Client's NIF.
	 */
	unsigned int NIF;
	/**
	 * @brief Client's address.
	 */
	string address;
	/**
	 * @brief Date in which the client made his last reservation.
	 */
	Date lastReservation;
public:
	/**
	 * The constructor used to initialize the binary search tree.
	 */
	Client(){};
	Client(string n, unsigned int NIF, Date lR, string a);
	virtual ~Client();
	string getName() const;
	unsigned int getNIF() const;
	string getAddress () const;
	void setAddress (string newAddress);
	Date getLastReservation () const;
	void setLastReservation (const Date &d) ;
	virtual string getInformation() const ;
	bool operator== (const Client& c2) const;
};

class RegisteredClient: public Client
{
private:
	/**
	 * number of points won by the client.
	 */
	unsigned int points;
	/**
	 * id in the list of registered clients.
	 */
	unsigned int reg_id;
public:
	RegisteredClient(string n, unsigned int NIF, unsigned int points, Date lR, string address);
	~RegisteredClient();
	unsigned int getId() const;
	unsigned int getPoints() const;
	void setPoints(unsigned int p);
	string getInformation() const;
	friend ostream &operator<< (ostream &os, RegisteredClient &rc1);
};

class OccasionalClient: public Client
{
private:
	unsigned int oc_id;
public:
	OccasionalClient(string n, unsigned int NIF, Date lR, string a);
	~OccasionalClient();
	unsigned int getId() const;
	void setId(unsigned int id);
	void adjustId();
	string getInformation() const;
	friend ostream &operator<< (ostream &os, OccasionalClient &oc1);
};
#endif /* SRC_CLIENT_H_ */
