#pragma once
#include <iostream>
#include <string>

using namespace std;


class AEROFLOT {
private:
	int m_num_flight;	// Номер рейса
	string m_destination;    // Пункт назначения
	string m_plane_type;    // Тип самолёта
	int m_lenght;	// Количество пересадок
	string* m_intermediate_points;    // Пункты пересадок

public:
	AEROFLOT () {}

	void init_and_enter_points() {};


	void setNumflight(int num_flight) {};

	void setDestination(const string& destination) {};

	void setPlanetype(const string& plane_type) {};

	// void setLenght(int num_flight) {};

	void setIntermediatePoints(int lenght) {};


	int getNumflight() const {};

	string& getDestination();

	string& getPlanetype();

	// int getLenght() const {};

	// string& getIntermediatePoints() {};


	void operator=(const AEROFLOT& aeroflot);

	void get_planetype_with_more_transfers(int lenght) const;

	void get_planetype_and_numflight_by_destination(const string& destination) const;


	~AEROFLOT() {
		delete[] m_intermediate_points;
	}
};