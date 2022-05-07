/*
    Demon
    Pham, Thanh
    
    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US    
*/
#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

class Member
{
public:
    Member();
    Member(const std::string& newFirstName, const std::string& newLastName);

    void addPoints(int addedPoints);

    void setID(int newID);

    int getId() const;
    int getPoints() const;
    std::string getLastName() const;

    void printMember() const;

private:
    int ID;
    std::string firstName;
    std::string lastName;
    int points;
};

#endif