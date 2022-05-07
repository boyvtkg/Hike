#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"
#include <iostream>
#include <string>
#include <set> 

int MEMBER_ID = 111;

class MemberList : public Member
{
    friend bool operator<(const Member& firstObj, const Member& secondObj);
public:
    MemberList(); //: new std::set<Member> {}

    void addMember(const std::string& firstName, const std::string& lastName);
    void addMember(const std::string& firstName, const std::string& lastName, int points);
    
    // int getLastID() const;
    // int getPoints(int id) const;
    
    void printMember(int id, const std::string lastName);

    // void clearList();

    // ~MemberList() {}

private:
    std::set<Member>* memberSet; 
};

#endif