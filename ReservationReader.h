/*
	Demon
	Pham, Thanh

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Reservations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservationList(ifstream& infile, Reservations& reservationsList)
{
	int memberID;
	string hikeName;

	while (!infile.eof())
	{
		infile >> memberID >> hikeName;
		reservationsList.addReservation(memberID, hikeName);
	}
}

void getReservationData(Reservations& reservationsList)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservationList(infile, reservationsList);

	infile.close();
}
