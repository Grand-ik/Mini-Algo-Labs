#include "AEROFLOT.h"
#include <iostream>
#include <string>
#include <vector>


void printAF(const AEROFLOT& data) {
	cout << data.getFlight() << ": " << data.getType() << '\n';
}


int main() {
	vector <AEROFLOT> All_Flight;
	All_Flight.push_back(AEROFLOT{});
	All_Flight.push_back(AEROFLOT{ 2004 });
	All_Flight.push_back(AEROFLOT{ "Nicky" });

	for (int i = 0; i < All_Flight.size(); ++i) {
		printAF(All_Flight[i]);
	}



	return 0;
}