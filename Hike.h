/*
    Fried Rice
    Bui, Kevin // member 1
    Lastname, Firstname // member 2 
    Lastname, Firstname // member 3
    Lastname, Firstname // member 4
    
    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US    
*/

#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

/**
 * Interface of the class Hike.
 */
class Hike
{
    // Overloaded insertion operator
    friend std::ostream& operator<<(std::ostream &out, const Hike&);

    public:
        // Default constructor
        Hike() : hikeDurationDays(0), hikeDifficulty(0) {}
        
        // Overloaded Constructor
        Hike(const std::string myLocation, const std::string myHikeName,
                int myHikeDurationDays, char myHikeDifficulty);

        // Accessor Functions
        std::string getHikeLocation() const;
        std::string getHikeName() const;
        int getHikeDuration() const;
        std::string getHikeDifficulty() const;

        // Empty Destructor
        ~Hike() {}

    private:
        std::string hikeLocation;
        std::string hikeName;
        int hikeDurationDays;
        char hikeDifficulty; // 'e' easy, 'm' moderate, 's' strenous
};

#endif