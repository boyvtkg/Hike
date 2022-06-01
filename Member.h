/*
    Demon

    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
    Member() : memberID(0), points(0) {}
    Member(const std::string& newFirstName, const std::string& newLastName);

    void addPoints(int addedPoints);
    void setID(int newID);

    int getID() const;
    std::string getLastName() const;
    int getPoints() const;
    
    bool operator<(const Member& paramObj) const;

    void printMember() const;

    ~Member() {}
private:
    int memberID;
    std::string firstName;
    std::string lastName;
    int points;
};

#endif