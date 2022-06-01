/*
    Demon

    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include "Member.h"

#include <iostream>

using namespace std;

Member::Member(const string& newFirstName, const string& newLastName)
{
    firstName = newFirstName;
    lastName = newLastName;
    memberID = 0;
    points = 0;
}

void Member::addPoints(int addedPoints)
{
    points += addedPoints;
}

void Member::setID(int newID)
{
    memberID = newID;
}

int Member::getID() const
{
    return memberID;
}

string Member::getLastName() const
{
    return lastName;
}

int Member::getPoints() const
{
    return points;
}

bool Member::operator<(const Member& paramObj) const
{
    return (memberID < paramObj.memberID);
}

void Member::printMember() const
{
    cout << '\t' << lastName << ", " << firstName << "\n"
         << "\tPoints available: " << points << "\n";
}