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

/**
 * Interface of the class MemberList.
 */
class MemberList
{
    // Overloaded less operator using for comparing 2 IDs of 2 objects
    friend bool operator<(const Member& firstObj, const Member& secondObj);
public:
    // Default constructor
    MemberList();

    // Adding member functions
    void addMember(const std::string& newfirstName, const std::string& newlastName);
    void addMember(const std::string& newfirstName, const std::string& newlastName, int points);

    // Accessor Functions
    int getLastID() const;
    int getPoints(int searchedID) const;

    // Print function
    void printMember(int searchedID, const std::string lastName);

    // The function to empty the set
    void clearList();

    // Empty Destructor
    ~MemberList() {}

private:
    std::set<Member> * listOfMember;
};

#endif