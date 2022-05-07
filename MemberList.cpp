/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#include "MemberList.h" 
#include <iostream>
#include <algorithm>

using namespace std;

const int FIRST_MEMBER_ID_NUMBER = 111;

bool operator<(const Member& firstObj, const Member& secondObj)
{
    return firstObj.getID() < secondObj.getID();
}

MemberList::MemberList()
{
    listOfMember = new set<Member>;
}

void MemberList::addMember(const string& newfirstName, const string& newlastName)
{
    Member newObj(newfirstName, newlastName);
    if (listOfMember->empty())
    {
        newObj.setID(FIRST_MEMBER_ID_NUMBER);
        listOfMember->insert(newObj);
    }
    else
    {
        newObj.setID(((listOfMember->begin())->getID()) + 1);
        listOfMember->insert(newObj);
    }
}

 void MemberList::addMember(const string& newfirstName, const string& newlastName, int points)
 {
     Member newObj(newfirstName, newlastName);
     newObj.addPoints(points);
     if (listOfMember->empty())
     {
         newObj.setID(FIRST_MEMBER_ID_NUMBER);
         listOfMember->insert(newObj);
     }
     else
     {
         newObj.setID(((listOfMember->begin())->getID()) + 1);
         listOfMember->insert(newObj);
     }
 }

 int MemberList::getLastID() const
 {
     return listOfMember->rbegin()->getID();
 }

 int MemberList::getPoints(int searchedID) const
 {
     auto iter = find_if(listOfMember->begin(), listOfMember->end(),
         [&](const auto& elem) {return elem.getID() == searchedID;});
     return iter->getPoints();
 }

void MemberList::printMember(int searchedID, const string seachedLastName)
{
    auto iter = find_if(listOfMember->begin(), listOfMember->end(),
        [&](const auto& elem) {return elem.getID() == searchedID;});

    if (iter->getLastName() == seachedLastName)
    {
        iter->printMember();
        cout << "\tMembership # " << searchedID << endl;
    }
}

 void MemberList::clearList()
 {
     listOfMember->clear();
 }