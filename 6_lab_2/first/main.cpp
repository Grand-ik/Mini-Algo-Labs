#include "AEROFLOT.h"
#include <vector>
// #include <string>
// #include <iostream>
#include <fstream>

// using namespace std;


void read_data(vector <AEROFLOT>& l_All_flight) {
    cout << "Choose add-mode.\n";
    cout << "\t1. Console.\n";
    cout << "\t2. txt-file\n";

    char add_mode{ '1' };
    cin >> add_mode;
    string file_name{ "AEROFLOT.txt" };
    if (add_mode == '1') {
        l_All_flight.push_back( AEROFLOT{} );
    }
    else {
        cout << "\nEnter file name: ";
        cin >> file_name;
        l_All_flight.push_back( AEROFLOT{ file_name } );
    }
}


int main() {
    vector <AEROFLOT> All_flight;
    int user_request{ 12 };
    while (user_request != 11) {
        cout << "Hello! It's Aeroflot-line's app.\nOn this page you can manage the flight database.\n\n\n";
        cout << "1. Add data.\n";
        cout << "2. Add flight.\n";
        cout << "11. Exit.\n";
        cout << "\nEnter numerate command: ";
        cin >> user_request;
        cout << "\n\n\n";

        switch (user_request) {
        case ( 1 ): {
            read_data( All_flight );
        }
        case ( 2 ): {
            read_data( All_flight );
        }
        case ( 11 ): {
            return 0;
        }
        default: {
            break;
        }
        }
    }


    return 0;
}