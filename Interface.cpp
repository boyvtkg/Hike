/*
	Demon

	Pham, Thanh

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Interface.h"

#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu()
{
	cout << string(51, '*') << endl
		 << "\t\tHIKING IN THE US\n"
		 << string(51, '*') << endl
		 << endl
		 << "\t1. Browse by location\n"
		 << "\t2. Browse by duration\n"
		 << "\t3. Browse by difficulty\n"
		 << "\t4. Browse by price\n"
		 << "\t5. Make a reservation\n"
		 << "\t6. View reservation\n"
		 << "\t7. Cancel reservation\n"
		 << "\t8. Exit\n"
		 << endl;
}

void processReservation(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservationList)
{
	int n = 0;
	while (n != 8)
	{
		cout << "Please make a selection: ";
		cin >> n;
		cout << endl;
		if (n != 8)
		{
			if (n == 1) 
				chooseByLocation(hikeList, memberList, reservationList);
			else if (n == 2) 
				chooseByDuration(hikeList, memberList, reservationList);
			else if (n == 3) 
				chooseByDifficulty(hikeList, memberList, reservationList);
			else if (n == 4) 
				chooseByPrice(hikeList, memberList, reservationList);
			else if (n == 5) 
				makeReservation(hikeList, memberList, reservationList);
			else if (n == 6) 
				viewReservation(hikeList, memberList, reservationList);
			else if (n == 7) 
				cancelReservation(hikeList, memberList, reservationList);
			system("Pause");
			cout << endl;
			displayMenu();
		}
	}
	cout << "Thank you for visiting!" << endl
		<< endl;
}

void chooseByLocation(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservationList)
{
	hikeList.printAllLocations();
	cout << endl;
	cout << "Choose a location: ";
	string location;
	cin >> location;
	cout << endl;
	hikeList.printByLocation(location);
	askToReserve(hikeList, memberList, reservationList);
}

void chooseByDuration(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservationList)
{
	cout << "\t(days)" << endl;
	hikeList.printByDuration();
	cout << endl;
	cout << "How many days are you considering? ";
	int duration = 0;
	cin >> duration;
	cout << endl;
	hikeList.printByDuration(duration);
	askToReserve(hikeList, memberList, reservationList);
}

void chooseByDifficulty(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservationList)
{
	cout << "Choose difficulty level: \n"
		 << endl
		 << "\te. easy\n"
		 << "\tm. moderate\n"
		 << "\ts. strenuous\n"
		 << endl
		 << "Your choice: ";
	char difficulty = 'e';
	cin >> difficulty;
	cout << endl
		 << "\t(difficulty level)" << endl;
	hikeList.printByDifficulty(difficulty);
	cout << endl;
	askToReserve(hikeList, memberList, reservationList);
}

void chooseByPrice(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservationList)
{
	hikeList.printByPrice();
	cout << endl;
	askToReserve(hikeList, memberList, reservationList);
}

int askIfMember(MemberList& memberList)
{
	cout << "Are you a member? (y/n) ";
	char answer = 'y';
	cin >> answer;
	int memberID = 0;
	cout << endl;
	if (answer == 'y')
	{
		cout << "What is your member ID number? ";
		cin >> memberID;
		cout << endl;
		cout << "What is your last name? ";
		string lastName;
		cin >> lastName;
		cout << endl;
		memberList.printMember(memberID, lastName);
	}
	else
	{
		memberID = addNewMember(memberList);
	}
	return memberID;
}

int addNewMember(MemberList& memberList)
{
	cout << "\tLet's add you to the member list!\n";
	cout << "\t\tWhat is your first name? ";
	string firstName;
	cin >> firstName;
	cout << "\t\tWhat is your last name? ";
	string lastName;
	cin >> lastName;
	cout << endl;
	memberList.addMember(firstName, lastName);
	cout << "\tWelcome to the club!\n"
		 << "\t\tYour member ID number is: " << memberList.getLastID()
		 << endl
		 << endl;
	return memberList.getLastID();
}

void makeReservation(HikeList& hikeList,
	MemberList& memberList, Reservations& reservationList)
{
	int memberID = askIfMember(memberList);
	cout << "Which hike would you like to reserve (hike name)? ";
	string hikeName;
	cin >> hikeName;
	cout << endl;
	hikeList.printByHikeName(hikeName);
	cout << endl;
	int points = memberList.getPoints(memberID);
	if (points > 0)
	{
		double price = hikeList.getPrice(hikeName);
		cout << fixed << showpoint << setprecision(2);
		cout << "\tDiscounted price using points: $"
			<< price - static_cast<double>(points / 100) << endl
			<< endl;
	}
	cout << "\tBefore proceeding, "
		 << "please make a note of your reservation number.\n" 
		 << "\t  Reservation #: " 
		 << reservationList.addReservation(memberID, hikeName) << endl
		 << endl
		 << "( *** Will continue to scheduling and payment. *** )\n"
		 << endl;
}

void viewReservation(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservationList)
{
	cout << "Enter reservation #: ";
	int reservationNumber = 0;
	cin >> reservationNumber;
	cout << endl;
	reservationList.printReservation(reservationNumber, hikeList, memberList);
}

void cancelReservation(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservationList)
{
	cout << "Enter reservation #: ";
	int reservationNumber = 0;
	cin >> reservationNumber;
	cout << endl;
	reservationList.printReservation(reservationNumber, hikeList, 
		memberList);
	cout << "Are you sure you want to cancel this reservation? (y/n) ";
	char answer = 'y';
	cin >> answer;
	cout << endl;
	if (answer == 'y')
	{
		reservationList.cancelReservation(reservationNumber);
		cout << "Reservation #" << reservationNumber
			<< " has been canceled.\n"
			<< endl;
	}
}

void askToReserve(HikeList& hikeList, 
	MemberList& memberList, Reservations& reservationList)
{
	cout << "Would you like to make a reservation? (y/n) ";
	char answer;
	cin >> answer;
	cout << endl;
	if (answer == 'y')
	{
		makeReservation(hikeList, memberList, reservationList);
	}
}