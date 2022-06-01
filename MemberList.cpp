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

MemberList::MemberList()
{
    listOfMember = new set<Member>;
}

void MemberList::addMember(const string& firstName, 
    const string& lastName)
{
    Member newMember(firstName, lastName);
    int memberID = FIRST_MEMBER_ID_NUMBER;
    if (listOfMember->empty())
    {
        newMember.setID(memberID);
    }
    else
    {
        newMember.setID((listOfMember->rbegin())->getID() + 1);
    }
    listOfMember->insert(newMember);
}

 void MemberList::addMember(const string& firstName, 
     const string& lastName, int points)
 {
     Member newMember(firstName, lastName);
     newMember.addPoints(points);
     int memberID = FIRST_MEMBER_ID_NUMBER;
     if (listOfMember->empty())
     {
         newMember.setID(memberID);
     }
     else
     {
         newMember.setID((listOfMember->rbegin())->getID() + 1);
     }
     listOfMember->insert(newMember);
 }

 int MemberList::getLastID() const
 {
     return listOfMember->rbegin()->getID();
 }

 int MemberList::getPoints(int searchedID) const
 {
     auto iter = find_if(listOfMember->begin(), listOfMember->end(),
         [& searchedID](const auto& elem) 
         {return elem.getID() == searchedID;});
     return iter->getPoints();
 }

void MemberList::printMember(int searchedID, const string& seachedLastName)
{
    auto iter = find_if(listOfMember->begin(), listOfMember->end(),
        [& searchedID](const auto& elem) 
        {return elem.getID() == searchedID;});
    if (iter->getLastName() == seachedLastName)
    {
        iter->printMember();
        cout << "\tMembership # " << searchedID << endl;
        cout << endl;
    }
}

 void MemberList::clearList()
 {
     listOfMember->clear();
 }

 MemberList::~MemberList()
 {
     delete listOfMember;
     listOfMember = nullptr;
 }