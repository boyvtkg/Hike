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
    return (firstObj.getID() < secondObj.getID());
}

MemberList::MemberList()
{
    listOfMember = new set<Member>;
}

void MemberList::addMember(const string& firstName, const string& lastName)
{
    Member newMember(firstName, lastName);
    if (listOfMember->empty())
    {
        newMember.setID(FIRST_MEMBER_ID_NUMBER);
    }
    else
    {
        newMember.setID((listOfMember->rbegin())->getID() + 1);
    }
    listOfMember->insert(newMember);
}

 void MemberList::addMember(const string& firstName, const string& lastName, int points)
 {
     Member newMember(firstName, lastName);
     newMember.addPoints(points);

     if (listOfMember->empty())
     {
         newMember.setID(FIRST_MEMBER_ID_NUMBER);
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
     auto iter = find_if(listOfMember->begin(), listOfMember->end(), [& searchedID](const auto& elem)
                        {return elem.getID() == searchedID;});
     return iter->getPoints();
 }

void MemberList::printMember(int searchedID, const string& seachedLastName)
{
    auto iter = find_if(listOfMember->begin(), listOfMember->end(), [& searchedID](const auto& elem)
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
     clearList();
     delete listOfMember;
     listOfMember = nullptr;
 }