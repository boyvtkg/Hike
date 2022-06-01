/*
	Demon

	Pham, Thanh

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Reservations.h"

#include <iostream>

using namespace std;

int Reservations::addReservation(int theMemberID, 
	const string& theHikeName)
{
	int reservationNumber = FIRST_RESERVATION_NUMBER;
	if (count == 0)
    {
		first = last = new Node(reservationNumber, 
			theMemberID, theHikeName, nullptr, nullptr);
    }
    else
    {
		reservationNumber = last->getReservationNumber() + 1;
		last->setNext(new Node(reservationNumber,
						theMemberID, theHikeName, last, nullptr));
        last = last->getNext();
    }
    ++count;
	return reservationNumber;
}

void Reservations::cancelReservation(int theReservationNumber)
{
	if (count == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else // more than 1 nodes
	{
		Node* pNode = findReservation(theReservationNumber);
		if (pNode == first)
		{
			first = first->getNext();
			first->setPrev(nullptr);
		}
		else if (pNode == last)
		{
			last = last->getPrev();
			last->setNext(nullptr);
		}
		else // the node is somewhere in middle
		{
			pNode->getPrev()->setNext(pNode->getNext());
			pNode->getNext()->setPrev(pNode->getPrev());
		}
		delete pNode;
		pNode = nullptr;
	}
	--count;
}

void Reservations::printReservation(int theReservationNumber, 
	const HikeList& theHikeList, const MemberList& theMemberList) const
{
	Node* pNode = findReservation(theReservationNumber);
	if (pNode == nullptr)
	{
		cerr << "This reservation does not exist.\n";
	}
	else
	{
		theHikeList.printByHikeName(pNode->getHikeName());
		int point = theMemberList.getPoints(pNode->getMemberID());
		if (point > 0)
		{
			cout << endl;
			double discountPrice = static_cast<double>(point / 100);
			cout << "\tDiscounted price using points: $"
				<< theHikeList.getPrice(pNode->getHikeName()) - discountPrice
				<< endl;
		}
	}
	cout << endl;
}

Node* Reservations::findReservation(int rsvnNumber) const
{
	Node* current = first;
	bool found = false;
	while (!found && current != nullptr)
	{
		if (current->getReservationNumber() == rsvnNumber)
		{
			found = true;
		}
		else
		{
			current = current->getNext();
		}
	}
	return current;
}

void Reservations::clearList()
{
	Node* temp = first;

	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}
	last = nullptr;
	count = 0;
}

Reservations::~Reservations()
{
	clearList();
}