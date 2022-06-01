/*
    Demon

    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"

#include <string>
#include <set> 

const int FIRST_MEMBER_ID_NUMBER = 111;

class MemberList
{
public:
    MemberList();

    void addMember(const std::string& firstName, 
        const std::string& lastName);
    void addMember(const std::string& firstName, 
        const std::string& lastName, int points);

    int getLastID() const;
    int getPoints(int searchedID) const;

    void printMember(int searchedID, const std::string& seachedLastName);

    void clearList();
    ~MemberList();
private:
    std::set<Member> *listOfMember;
};

#endif