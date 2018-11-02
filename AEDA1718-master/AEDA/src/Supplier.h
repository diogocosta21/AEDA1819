/*
 * Supplier.h
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#ifndef SRC_SUPPLIER_H_
#define SRC_SUPPLIER_H_


#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Supplier {
private:
	/**
	 *@brief supplier's name.
	 */
	string name;
	/**
	 * @brief supplier's NIF.
	 */
	unsigned int NIF;
	/**
	 * @brief supplier's address.
	 */
	string address;
	/**
	 * @brief supplier's id.
	 */
	unsigned int id;
public:
	Supplier(string n, unsigned int NIF, string address);
	virtual ~Supplier();
	string getName() const;
	unsigned int getNIF() const;
	string getAddress() const;
	unsigned int getId() const;
	string getInformation() const;
	friend ostream &operator<< (ostream &os, Supplier &s1);
};

#endif /* SRC_SUPPLIER_H_ */
