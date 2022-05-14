/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "HikeList.h"
#include "MemberList.h"
#include <iostream>

const int FIRST_RESERVATION_NUMBER = 50001;

class Node
{
public:
    Node() : reservationNumber(0), memberID(0), prev(nullptr), next(nullptr) {}
    Node(int theReservationNumber, int theMemberID,
         const std::string& theHikeName, Node* prevLink, Node* nextLink)
        : reservationNumber(theReservationNumber),
        memberID(theMemberID), hikeName(theHikeName), prev(prevLink), next(nextLink) {}
    int getReservationNumber() const { return reservationNumber; }
    int getMemberID() const { return memberID; }
    std::string getHikeName() const { return hikeName; }
    Node* getPrev() const { return prev; }
    Node* getNext() const { return next; }
    void setReservationNumber(int theReservationNumber) { reservationNumber = theReservationNumber; }
    void setMemberID(int theMemberID) { memberID = theMemberID; }
    void setHikeName(int theHikeName) { hikeName = theHikeName; }
    void setPrev(Node* prevLink) { prev = prevLink; }
    void setNext(Node* nextLink) { next = nextLink; }
    ~Node(){}
private:
    int reservationNumber;
    int memberID;
    std::string hikeName;
    Node* prev;
    Node* next;
};

class Reservations
{
public:
    Reservations() : first(nullptr), last(nullptr), count(0) {}

    int addReservation(int theMemberID, const std::string& newHikeName);
    void cancelReservation(int theReservationNumber);
    void printReservation(int theReservationNumber, const HikeList& theHikeList, 
        const MemberList& theMemberList) const;
    void clearList();
    ~Reservations();

private:
    Node* findReservation(int theReservationNumber) const;
    Node *first;
    Node *last;
    int count;
};

#endif
