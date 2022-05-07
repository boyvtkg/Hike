#include "MemberList.h" 

#include <iostream>
#include <string>
#include <set>

using namespace std;

bool operator<(const Member& firstObj, const Member& secondObj)
{
    return firstObj.getId() < secondObj.getId();
}

MemberList::MemberList()
{
    memberSet = new set<Member>;
}

void MemberList::addMember(const std::string& firstName, const std::string& lastName)
{
    Member myObj(firstName, lastName);
    if (memberSet->empty())
    {
        myObj.setID(MEMBER_ID);
        memberSet->insert(myObj);
    }
    else
    {
        myObj.setID(((memberSet->begin())->getId()) + 1);
        memberSet->insert(myObj);
    }
}

// void MemberList::addMember(const std::string& firstName, const std::string& lastName, int points)
// {
//     Member myObj(firstName, lastName, points);
//     if (memberSet->empty())
//     {
//         myObj.setID(MEMBER_ID);
//         memberSet->insert(myObj);
//     }
//     else
//     {
//         myObj.setID(((memberSet->begin())->getId()) + 1);
//         memberSet->insert(myObj);
//     }
// }

// int MemberList::getLastID() const
// {
//     auto iter = memberSet.end();
//     return *iter;
// }

// int MemberList::getPoints(int id) const
// {
//     auto iter = find_if(hikeMap.begin(), hikeMap.end(), 
//                 [&](const auto& hikePair) {return (hikeName == (hikrPair.first.getHike()));})
//     return *iter;
// }

void MemberList::printMember(int id, const std::string lastName)
{
    auto iter = find_if(memberSet.begin(), memberSet.end(), 
                [&](const auto& hikePair) {return (id == (hikePair.first.getID()));})
    if (lastName == iter->getLastName())
    {
        iter->printMember();
        cout << "Membership # " << id << endl;
    }
}

// void MemberList::clearList()
// {
//     memberSet.clear();
// }