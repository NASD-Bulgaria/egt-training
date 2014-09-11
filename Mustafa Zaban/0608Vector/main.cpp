#include <iostream>
#include <vector>
using namespace std;

void resetSeats (int a[][2]) // vkarvame masiv viv funkciq
{
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<2; j++)
		{
			a[i][j] = 0;
		}
	}
}

void takeSeat (int a[][2])
{
	char side = ' ';
	int sideNumber = 0;
	cout << "Enter the prefered side on the  plane (left or right), L or R - ";
	cin >> side;
	switch (side)
	{
	case 'L': sideNumber = 0;break;
	case 'R': sideNumber = 1;break;
	default: cout << "Enter only L or R!" << endl;
	}
	int seatNumber;
	cout << "Enter the prefered seat (1-5): ";
	cin >> seatNumber;
	if (a[seatNumber][sideNumber] == 0)
	{
		cout << "The seat is yours! :)" << endl;
		a[seatNumber][sideNumber] = 1;
	}
	else
	{
		cout << "The seat was taken! :(" << endl;
	}
}


int main (){
	int planeSeats[5][2] = {0};
	takeSeat(planeSeats);
	takeSeat(planeSeats);
	resetSeats(planeSeats);
	takeSeat(planeSeats);
	takeSeat(planeSeats);

	vector<int> numberVector;
	for (int i=0; i<11; i++)
	{
		numberVector.push_back(i);
	}

	int sizeVector = 0;
	sizeVector = numberVector.size();

	cout << "The size of vector is - " << sizeVector << endl;

	for (int i=0;i<sizeVector; i++)
	{
		cout << numberVector.at(i);
	}




	return 0;
}