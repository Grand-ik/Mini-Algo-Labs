#include "AEROFLOT.h"


void AEROFLOT::init_and_enter_points() {
	
}



void AEROFLOT::setNumflight(int num_flight) {
	m_num_flight = num_flight;
}


void AEROFLOT::setDestination(const string& destination) {
	m_destination = destination;
}


void AEROFLOT::setPlanetype(const string& plane_type) {
	m_plane_type = plane_type;
}


/*void AEROFLOT::setLenght(int lenght) {
	m_lenght = lenght;
}*/


void AEROFLOT::setIntermediatePoints(int lenght, char type_enter) {
	m_lenght = lenght;
	m_intermediate_points = new string[lenght];

	for (int i = 0; i < m_lenght, ++i) {
		switch (type_enter) {
		case 0:
			
		}
	}
}


int AEROFLOT::getNumflight() const {
	return m_num_flight;
}


string& AEROFLOT::getDestination() {
	return m_destination;
}


string& AEROFLOT::getPlanetype() {
	return m_plane_type;
}


/*int AEROFLOT::getLenght() const {
	return m_lenght;
}*/

// Пункты назначения



void AEROFLOT::operator=(const AEROFLOT& aeroflot)
{
	cout << "'cool";
}


void AEROFLOT::get_planetype_with_more_transfers(int lenght) const {
	if (m_lenght < lenght) { cout << m_plane_type << '\n'; }
}


void AEROFLOT::get_planetype_and_numflight_by_destination(const string& destination) const {
	if (m_destination == destination) {
		cout << m_num_flight << ": " << m_plane_type << '\n';
	}
}
