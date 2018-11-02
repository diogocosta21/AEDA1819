/*
 * Company.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Company.h"

/**
 * The constructor.
 * @param rClients registered clients.
 * @param oClients occasional clients.
 * @param suppliers suppliers.
 * @param offers offers.
 * @param reserv reservations.
 */
Company::Company(vector<RegisteredClient *> rClients, vector<OccasionalClient *> oClients, vector<Supplier *> suppliers, vector<Offer *> offers, vector <Reservation> reserv): reservations ( Reservation() )
{
	this->rClients = rClients;
	this->oClients = oClients;
	this->suppliers = suppliers;
	this->offers = offers;
	date = Date("8-1-2018");

	reservations.makeEmpty();

	 //BST
	vector <Reservation> v;

	v = setClientsonReservations (reserv);

	for (unsigned int i = 0; i < v.size() ; i++)
	{
		reservations.insert(v[i]);
	}

	//Tabela de dispersão
	for (unsigned int i = 0; i < rClients.size(); i++)
	{
		Client * c = rClients[i];
		Date d = c->getLastReservation();
		unsigned int days = d.daysBetween(date);

		if (days >= 30)
			this->inactiveClients.insert(c);
	}

	for (unsigned int i = 0; i < oClients.size(); i++)
	{
		Client * c = oClients[i];
		Date d = c->getLastReservation();
		unsigned int days = d.daysBetween(date);

		if (days >= 30)
			this->inactiveClients.insert(c);
	}

	//Fila de prioridade

	offers[0]->resetId();

	for (unsigned int i = 0; i < offers.size(); i++)
	{
		Offer *o1 = offers[i];
		Offer o2 = Offer (o1->getPrice(), o1->getDistance(), o1->getCapacity(), o1->getBoatType(), o1->getDestination(), o1->getSupName(), o1->getPoints(), o1->getPercentage(), o1->getDate(), o1->getLastReservation());
		Date d = o2.getLastReservation();
		unsigned int days = d.daysBetween(date);

		if (days >= 30)
		{
			this->UnpopularOffers.push(o2);
		}
	}


	updateDiscounts();

	bank = 0;
}

/**
 * The destructor.
 */
Company::~Company()
{

}

/**
 * Exports registered clients to text file.
 * @param file that stores registered clients' information.
 */
void Company::exportRegisteredClients(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<rClients.size(); i++){
		out << *rClients.at(i) << endl;
	}

	out.close();
}

/**
 * Exports occasional clients to text file.
 * @param file that stores occasional clients' information.
 */
void Company::exportOccasionalClients(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<oClients.size(); i++){
		out << *oClients.at(i) << endl;
	}

	out.close();
}

/**
 * Exports suppliers to text file.
 * @param file that stores suppliers' information.
 */
void Company::exportSuppliers(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<suppliers.size(); i++){
		out << *suppliers.at(i) << endl;
	}

	out.close();
}

/**
 * Exports offers to text file.
 * @param file that stores offers' information.
 */
void Company::exportOffers(string file)
{
	ofstream out;
	out.open(file.c_str());

	for(unsigned int i=0; i<offers.size(); i++){
		out << *offers.at(i) << endl;
	}

	out.close();
}

/**
 * Exports reservations to text file.
 * @param file that stores reservations' information.
 */
void Company::exportReservations (string file)
{
	ofstream out;
	out.open(file.c_str());

	BSTItrIn <Reservation> it (reservations);
	vector <Reservation> v;

	while (!it.isAtEnd())
	{
		v.push_back (it.retrieve());
		it.advance();
	}

	int j;

	for (int gap = v.size()/2; gap > 0; gap /= 2)
	{
			for (unsigned int i = gap; i < v.size(); i++)
			{
				Reservation tmp = v[i];
				for (j = i; j >= gap && tmp.getId() < v[j-gap].getId(); j -= gap)
					v[j] = v[j-gap];
				v[j] = tmp;
			}
	}

	for(unsigned int i=0; i<v.size(); i++){
		out << v.at(i);
		out << endl;
	}

	out.close();
}

/**
 * Adds client to registered client's vector.
 * @param name new client's name.
 * @param NIF new client's NIF.
 * @param address new client's address.
 */
unsigned int Company::RegisterClient(string name, int NIF, string address)
{
	RegisteredClient * rc = new RegisteredClient(name,NIF,0, Date ("1-1-1111"), address);
	rClients.push_back(rc);

	return rc->getId();
}

/**
 * Adds supplier to supplier's vector.
 * @param n new supplier's name.
 * @param NIF new supplier's NIF.
 * @param address new supplier's address.
 */
void Company::AddSupplier(string n, int NIF, string address)
{
	Supplier * sup = new Supplier(n, NIF, address);
	suppliers.push_back(sup);

}

/**
 * Adds offer to offer's vector.
 * @param price new offer's price.
 * @param dist new offer's distance.
 * @param cap new offer's capacity.
 * @param points new offer's points.
 * @param perc new offer's percentage.
 * @param bT new offer's boat type.
 * @param dest new offer's destination.
 * @param supName new offer's supplier's name.
 * @param d new offer's date.
 */
void Company::addOffer(unsigned int price, unsigned int dist, unsigned int cap, unsigned int points, double perc, string bT, string dest, string supName, Date d)
{
	Offer * o = new Offer(price, dist, cap, bT, dest, supName, points, perc, d, Date ("1-1-1111") );

	offers.push_back(o);

	for(unsigned int i = 0; i < this->suppliers.size(); i++)
	{
		if (suppliers[i]->getName() == supName)
			o->setSupplier( suppliers [i]);
		break;
	}
}

/**
 * Adds occasional client to occasional clients' vector.
 * @param name new occasional client's name.
 * @param NIF new occasional client's NIF.
 * @param address new occasional client's address.
 */
void Company::addOccasionalClient (string name, int NIF, string address)
{
	OccasionalClient *oc = new OccasionalClient(name,NIF,Date ("1-1-1111"), address);
	oClients.push_back(oc);
}

/**
 * Removes occasional client from the respective vector.
 * @param id id of the occasional client to be removed.
 */
void Company::removeOccasionalClient(int id)
{
	vector <OccasionalClient *>::iterator it = oClients.begin();

	for(unsigned int i = 0; i < oClients.size();i++, it++)
	{
		if( (*it)->getId() == id)
		{
			(*it)->adjustId();
			oClients.erase(it);
		}
	}

	for(unsigned int i = id-1; i < oClients.size(); i++ )
	{
		int new_id = oClients[i]->getId() - 1;
		oClients[i]->setId(new_id);
	}


}

/**
 * @return registered clients' vector.
 */
vector <RegisteredClient *> Company::getRegisteredClients () const
{
	return rClients;
}

/**
 * @return date.
 */
Date Company::getDate() const
{
	return date;
}

/**
 * @return occasional clients' vector.
 */
vector <OccasionalClient *> Company::getOccasionalClients() const
{
	return oClients;
}

/**
 * @return suppliers' vector.
 */
vector <Supplier *> Company::getSuppliers () const
{
	return suppliers;
}

/**
 * @return offers' vector.
 */
vector <Offer *> Company::getOffers () const
{
	return offers;
}

/**
 * @return binary search tree "reservations".
 */
BST <Reservation> Company::getReservations() const
{
	return this->reservations;
}

/**
 * @return bank.
 */
double Company::getBank() const
{
	return bank;
}

/**
 * Adds reservation r to the binary tree, or if already present, add nTick to the number of tickets.
 * @param r reservation to be added.
 * @param nTick number of tickets to be added.
 */
void Company::addReservation(const Reservation &r, unsigned int nTick)
{
	BSTItrIn <Reservation> it (reservations);

	while (!it.isAtEnd())
	{
		if (it.retrieve() == r)
		{
			Reservation tmp = it.retrieve();
			removeReservation (tmp, tmp.getTickets());

			tmp.setTickets(tmp.getTickets() + nTick);
			reservations.insert(tmp);
			return;
		}
		it.advance();

	}
	reservations.insert(r);
}

/**
 * Fills reservations's client parameter according to the parameter clientName.
 * @param r vector with all the reservations read from text file.
 * @return paramater r.
 */
vector <Reservation> Company::setClientsonReservations (vector <Reservation> r)
{

	for (unsigned int i = 0; i < r.size(); i++)
	{
		bool Found = false;

		vector <RegisteredClient *>::iterator it = rClients.begin();

		for (unsigned int j = 0; j < this->rClients.size(); j++,it++)
		{
			if ( (*it)->getName() == r[i].getClientName())
			{
				r[i].setClient( (*it) );
				Found = true;
				break;
			}
		}

		if (!Found)
		{
			vector <OccasionalClient *>::iterator it = oClients.begin();

			for (unsigned int j = 0; j < this->oClients.size(); j++,it++)
			{
				if ( (*it)->getName() == r[i].getClientName())
				{
					r[i].setClient( (*it) );
					break;
				}
			}
		}

	}

	return r;
}

/**
 *	Removes tickets from reservation or removes the entire reservation from binary tree "reservations".
 *	@param r reservation to be removed/to remove tickets.
 *	@param nTick number of tickets to be removed.
 *  @return 0 if reservations isn't on the binary tree, 1 if reservation is removed entirely or 2 if just some tickets are removed.
 */
int Company::removeReservation(const Reservation &r, unsigned int nTick)
{
	BSTItrIn <Reservation> it (reservations);
	vector <Reservation> v;
	int Found = 0;

	while (!it.isAtEnd())
	{
		if (r == it.retrieve())
		{
			Reservation re = it.retrieve();

			if (nTick == it.retrieve().getTickets())
			{
				Found = 1;
			}
			else if (nTick > it.retrieve().getTickets() )
			{
				v.push_back(it.retrieve());
				Found = 2;
			}
			else
			{
				Reservation nova = it.retrieve();
				nova.setTickets( it.retrieve().getTickets() - nTick);
				v.push_back(nova);
				Found = 1;
			}
		}
		else
		{
			v.push_back(it.retrieve());
		}
		it.advance();
	}

	reservations.makeEmpty();

	for (unsigned int i = 0; i < v.size(); i++)
	{
		reservations.insert(v[i]);
	}

	return Found;
}


/**
 * Removes client from hash table inactiveClients.
 * @param name of the client to be removed.
 */
void Company::removeInactiveClient(string name)
{
	tabHInactive::iterator it = this->inactiveClients.begin();

	while (it != inactiveClients.end())
	{
		Client * c = (*it);
		if ( c->getName() == name )
		{
			inactiveClients.erase(c);
			break;
		}
		it++;
	}
}

/**
 * Checks if the client is on the hash table inactiveClients.
 * @param name of the client to be searched.
 * @return true if the client is on the hash table and false otherwise.
 */

bool Company::searchInactiveClient(string name)
{
	tabHInactive::iterator it = this->inactiveClients.begin();

	while (it != inactiveClients.end())
	{
		Client * c = (*it);
		if ( c->getName() == name )
		{
			return true;
		}
		it++;
	}

	return false;
}


/**
 * Updates address from a client in the has table inactiveClients.
 * @param name of the client to be updated.
 * @param newAddress of the client.
 */
void Company::updateAddressClient(string name, string newAddress)
{
	tabHInactive::iterator it = this->inactiveClients.begin();

		while (it != inactiveClients.end())
		{
			Client * c = (*it);
			if ( c->getName() == name )
			{
				inactiveClients.erase(c);
				c->setAddress(newAddress);
				inactiveClients.insert(c);
				break;
			}
			it++;
		}
}


/**
 * Removes offer from priority queue UnpopularOffers.
 * @ offerId id of the offer to be removed.
 */
void Company::removeUnpopularOffer(unsigned int offerId)
{
	if (this->UnpopularOffers.empty())
		return;

	priority_queue <Offer> pq ;

	while (!UnpopularOffers.empty())
	{
		if ( !(offerId == UnpopularOffers.top().getId() ) )
		{
			pq.push( UnpopularOffers.top());
		}
		UnpopularOffers.pop();
	}

	while ( !pq.empty() )
	{
		Offer o = pq.top();
		UnpopularOffers.push(o);
		pq.pop();
	}

	updateDiscounts();
}


/**
 * Updates the discounts of the offers on the priority queue UnpopularOffers.
 */
void Company::updateDiscounts()
{
	int counter = 1;
	double discount = 0;

	if (this->UnpopularOffers.empty())
		return;

	priority_queue <Offer> pq ;

	while (!UnpopularOffers.empty())
	{
		Date d = UnpopularOffers.top().getLastReservation();
		unsigned int days = d.daysBetween(date);

		if (days >= 30)
		{
			switch (counter)
			{
				case 1:
				{
					discount = 0.3;
					Offer o = UnpopularOffers.top();
					o.setDiscount (discount);
					pq.push(o);

					offers[o.getId()-1]->setDiscount(discount);
					counter = 2;
					break;
				}

				case 2:
				{
					discount = 0.2;
					Offer o = UnpopularOffers.top();
					o.setDiscount (discount);
					pq.push(o);

					offers[o.getId()-1]->setDiscount(discount);
					counter = 3;
					break;
				}
				case 3:
				{
					discount = 0.15;
					Offer o = UnpopularOffers.top();
					o.setDiscount(discount);
					pq.push(o);

					offers[o.getId()-1]->setDiscount(discount);
					counter = 4;
					break;
				}
				case 4:
				{
					discount = 0.10;
					Offer o = UnpopularOffers.top();
					o.setDiscount(discount);
					pq.push(o);

					offers[o.getId()-1]->setDiscount(discount);
					break;
				}
			}
		}

		UnpopularOffers.pop();
	}

	while ( !pq.empty() )
	{
		Offer o = pq.top();
		UnpopularOffers.push(o);
		pq.pop();
	}
}

/**
 * Add b to bank.
 * @param b value to be added.
 */
void Company::setBank(double b)
{
	bank += b;
}

/**
 * Sets offer's corresponding supplier according to offer's supName.
 */
void Company::setOfferSuppliers()
{
	for( unsigned int i = 0; i < offers.size(); i++)
	{
		for (unsigned int j = 0; j < suppliers.size(); j++)
		{
			if(offers[i]->getSupName() == suppliers[j]->getName() )
			{
				offers[i]->setSupplier(suppliers[j]);
				break;
			}
		}
	}

}

/**
 * Prints registered clients' information.
 */
void Company::printRegisteredClients() const
{
	for (unsigned int i = 0; i < rClients.size(); i++)
	{
		cout<< rClients[i]->getInformation() << endl;
	}

}

/**
 * Prints registered clients sorted by their points.
 */
void Company::printRegisteredClientByPoints() const
{
	vector <RegisteredClient* > v_tmp = rClients;

	int j;
	for (int gap = v_tmp.size()/2; gap > 0; gap /= 2)
	{
		for (unsigned int i = gap; i < v_tmp.size(); i++)
		{
			RegisteredClient* tmp = v_tmp[i];
			for (j = i; j >= gap && tmp->getPoints() > v_tmp[j-gap]->getPoints(); j -= gap)
				v_tmp[j] = v_tmp[j-gap];
			v_tmp[j] = tmp;
		}
	}

	for(unsigned int i = 0; i < v_tmp.size(); i++)
	{
		cout<< v_tmp[i]->getInformation() << endl;
	}

}

/**
 * Prints occasional clients' information.
 */
void Company::printOccasionalClients() const
{
	for (unsigned int i = 0; i < oClients.size(); i++)
	{
		cout<< oClients[i]->getInformation() << endl;
	}
}

/**
 * Prints clients that made a reservation in a certain offer.
 * @param idOffer offer's id.
 */
void Company::printClientsByOffer(unsigned int idOffer) const	//// TODO
{

	BSTItrIn <Reservation> it (reservations);

	cout << endl;

	while (!it.isAtEnd())
	{
		if (it.retrieve().getOffer() == idOffer)
		{
			cout << it.retrieve().getClient()->getName() << ", Tickets: " << it.retrieve().getTickets() << endl;
		}
		it.advance();
	}

}

/**
 * Prints suppliers' information.
 */
void Company::printSuppliers() const
{
	for (unsigned int i = 0; i < suppliers.size(); i++)
	{
		cout<< suppliers[i]->getInformation() << endl;
	}
}

/**
 * Prints offers' information.
 */
void Company::printOffers() const
{
	cout << endl;
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		cout<< offers[i]->getInformation() << endl;
	}
}

/**
 * Prints offers which date is inserted in the range provided.
 * @param d1 inital date.
 * @param d2 final date.
 * @return vector with indexes of offers inside the range provided.
 */
vector<int> Company::printOfferbyDate(Date d1, Date d2) const
{
	unsigned int counter = 0;
	vector <int> v;

	for (unsigned int i = 0; i < offers.size(); i++)
	{
		if(d1 <= offers[i]->getDate())
			if (offers[i]->getDate() <= d2)
				{
					cout<< offers[i]->getInformation() << endl;
					counter++;
					v.push_back (i+1);
				}
	}

	cout << "We found " << counter << " offers" << endl;
	return v;
}

/**
 * Prints a certain supplier's offers.
 * @param name supplier's name.
 */
void Company::printOffersBySuppliers(string name) const
{
	for (unsigned int i = 0; i < offers.size(); i++)
	{
		if (offers[i]->getSupName() == name)
			cout<< offers[i]->getInformation() << endl;
	}
}

/**
 * Prints the offers to which a certain client made a reservation.
 * @param cName name of the client.
 * @return true if the client made at least one reservation, otherwise it return false.
 */
bool Company::printOffersByClient(string cName) const
{
	BSTItrIn <Reservation> it (reservations);
	bool Found = false;

	while (!it.isAtEnd())
	{
		Client *c = it.retrieve().getClient();

		if (c->getName() == cName)
		{
			if (!Found)
				cout << endl << "You have reservations for the following offer: " << endl << endl;

			cout << offers[it.retrieve().getOffer() - 1]->getInformation()
					<< "Tickets bought: " << it.retrieve().getTickets() << endl << endl;
			Found = true;
		}
		else
		{
			if (Found)
				break;
		}
		it.advance();
	}

	if (!Found)
	{
		cout << "You dont have any reservation" << endl;
	}

	return Found;
}

/**
 * Prints all reservations on the binary search tree.
 */
void Company::printReservations() const
{
	if (reservations.isEmpty())
		return;

	BSTItrIn <Reservation> it (reservations);
	Client *c = it.retrieve().getClient();

	cout << c->getName() << ":" << endl << endl;
	while (!it.isAtEnd())
	{
		Reservation r = it.retrieve();
		if ( !(r.getClient() == c) )
		{
			c = r.getClient();
			cout << endl << c->getName() << ":" << endl << endl;
		}
		cout << "Offer id: #" << r.getOffer() << ", Date: " << r.getDate().getDay() << "/" << r.getDate().getMonth() << "/" << r.getDate().getYear() << ", Tickets: " << r.getTickets() << endl;

		it.advance();
	}
}


/**
 * Prints all clients on the hash table.
 */
void Company::printInactiveClients() const
{
	tabHInactive::const_iterator it = this->inactiveClients.begin();
	cout << endl;

	while (it != inactiveClients.end() )
	{
		Client * c = (*it);
		cout << c->getName() << ", " << c->getNIF() << ", Address: "<< c->getAddress() << endl;
		it++;
	}
}


/**
 * Prints all offers on the priority queue.
 */
void Company::printUnpopularOffers() const
{
	priority_queue <Offer> pq = this->UnpopularOffers;

	cout << endl;

	if (pq.empty())
	{
		cout << "There are no unpopular offers at the moment." << endl;
		return;
	}

	while (!pq.empty() )
	{

		cout << pq.top().getId() << " " << pq.top().getDate().getDay() << "/" << pq.top().getDate().getMonth() << "/" << pq.top().getDate().getYear() << " " << pq.top().getSupName() << " " << pq.top().getDestination() << ", Original price: " << pq.top().getPrice() << "€";
		cout << endl << "Last time this offer was reservated: " << pq.top().getLastReservation().getDay() << "/" << pq.top().getLastReservation().getMonth() << "/" << pq.top().getLastReservation().getYear() << endl ;
		cout << "Discount : " << pq.top().getDiscount() * 100 << "%" << endl << endl;;
		pq.pop();
	}
}
