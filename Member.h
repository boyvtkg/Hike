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

/**
 * Interface of the class Member.
 */
class Member
{
public:
    // Default constructor
    Member();

    // Overloaded Constructor
    Member(const std::string& newFirstName, const std::string& newLastName);

    // Mutator functions
    void addPoints(int addedPoints);
    void setID(int newID);

    // Accessor Functions
    int getID() const;
    std::string getLastName() const;
    int getPoints() const;

    // Print member function
    void printMember() const;

private:
    int memberID;
    std::string firstName;
    std::string lastName;
    int points;
};

#endif