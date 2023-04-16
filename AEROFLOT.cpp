#include "AEROFLOT.h"

// Initialisetion
void AEROFLOT::init(int flight, const string& type) {
	m_flight = flight;
	m_type = type;
}

AEROFLOT::AEROFLOT(const string& type) {
	init(0, type);
}

AEROFLOT::AEROFLOT(int flight, const string& type) {
	init(flight, type);
}

// Getters
int AEROFLOT::getFlight() const {
	return m_flight;
}

string AEROFLOT::getType() const {
	return m_type;
}

string AEROFLOT::getDestination() const {
	return m_destination;
}

size_t AEROFLOT::getCoutnTransfers() const {
	return m_count_transfers;
}

string& AEROFLOT::getTransfers() const {
	string* Transfers = new string[m_count_transfers];
	Transfers = m_Transfers;
	return *Transfers;
}