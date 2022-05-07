/*
    Demon
    Pham, Thanh
    
    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US    
*/
#include "Member.h"
#include <iostream>
#include <string>

using namespace std;

Member::Member()
{
    ID = 0;
    points = 0;
}
Member::Member(const string& newFirstName, const string& newLastName)
{
    firstName = newFirstName;
    lastName = newLastName;
    ID = 0;
    points = 0;
}

void Member::addPoints(int addedPoints)
{
    points += addedPoints;
}

void Member::setID(int newID)
{
    ID = newID;
}

int Member::getId() const
{
    return ID;
}
int Member::getPoints() const
{
    return points;
}
string Member::getLastName() const
{
    return lastName;
}

void Member::printMember() const
{
    cout << lastName << "," << firstName << "\n"
         << "Points available: " << points << "\n"; 

}