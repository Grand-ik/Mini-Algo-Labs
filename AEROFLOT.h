#pragma once
#include <string>

using namespace std;


class AEROFLOT
{
private:
	int m_flight{ 0 };	// Number flight
	string m_type;	// Plane's type
	string m_destination;
	size_t m_count_transfers;
	string* m_Transfers;	// List of transfers
public:
	// Initialisetion
	AEROFLOT() = default;
	AEROFLOT(const string& type);
	AEROFLOT(int flight, const string& type = "");

	void init(int flight, const string& type);

	// Getters
	int getFlight() const;
	string getType() const;
	string getDestination() const;
	size_t getCoutnTransfers() const;
	string& getTransfers() const;

	// Setters
	void setFlight(int flight);
	void setType(const string& type);
	void setDestination(const string& destination);
	void setTransfers(size_t count_transfers);
};

