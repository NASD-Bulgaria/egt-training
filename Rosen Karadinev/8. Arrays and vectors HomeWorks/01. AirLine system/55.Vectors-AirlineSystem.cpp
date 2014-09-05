//1. A small airline has just purchased a computer for its
//new automated reservations system. You have been
//asked to program the new system. You are to write a
//program to assign seats on each flight of the airline's
//only plane (capacity: 10 seats). Make appropriate
//menu and messages.

#include <iostream>
#include <iomanip>
using namespace std;

static int flightsSeats[3][10];

void showWellcome(void);
void showMenu(void);
bool checkSeat(int, int);
void reserveSeat(int, int);

int main()
{

	int seatCheck;
	int flight;

	int choice;     //menu choice

	//constants for menu choices
	const int CHECK_CHOICE = 1, RESERVE_CHOICE = 2, EXIT_CHOICE = 3;

	showWellcome();

	do {

		showMenu();
		cin >> choice;

		while (choice < CHECK_CHOICE || choice > EXIT_CHOICE)
		{
			cout << "Please enter a valid menu choice: ";
			cin >> choice;
		}

		if (choice != EXIT_CHOICE)
		{
			switch (choice)
			{

				case CHECK_CHOICE:
					cout << "Choose a flight (1,2 or 3): ";
					cin >> flight;

					cout << "Choose seat for check: ";
					cin >> seatCheck;

					if(checkSeat(flight, seatCheck) == true)
					{
						cout << "\nThe seat № " << seatCheck << " is free." << endl;
					}
					else
					{
						cout << "\nThe seat № " << seatCheck << " is occupied. Sorry." << endl;
					}

					break;

				case RESERVE_CHOICE:
					cout << "Choose a flight (1,2 or 3): ";
					cin >> flight;

					cout << "Choose seat for reserve: ";
					cin >> seatCheck;

					reserveSeat(flight, seatCheck);
					break;

			}
		}
	} while (choice != EXIT_CHOICE);

}

void showWellcome()
{
	cout << "---------------------------" << endl;
	cout << "Welcome to RosCorp AirLines" << endl;
	cout << "---------------------------" << endl << endl;
}

void showMenu()
{
	cout << "\nPlease choose an action." << endl  << "1. Check free seats."
			<< endl << "2. Reserve a seat." << endl << "3. Exit" << endl;
}

bool checkSeat(int flight, int seat)
{
	if (flightsSeats[flight][seat] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void reserveSeat(int flight, int seat)
{
	if (flightsSeats[flight][seat] == 0)
	{
		flightsSeats[flight][seat] = 1;
		cout << "\nYou reserved seat № " << seat << " at flight № " << flight << endl;
	} else {
		cout << "\nThe seat is reserved !!!" << endl;
	}
}



