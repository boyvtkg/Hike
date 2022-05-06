/*
    Fried Rice
    
    Bui, Kevin // member 1
    Pham, Thanh // member 2 
    Le, Allyson // member 3
    Le, Amanda // member 4  
    
    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US    
*/

// Implementation of class Hike.
#include "Hike.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * @brief Outputs a hike in the format:
 * hikeName (hikeLocation)
 * Difficulty: hikeDifficulty
 * Duration: myHikeDurationDays day(s)
 */
ostream& operator<<(std::ostream &out, const Hike& myHike)
{
    out << myHike.hikeName << " (" << myHike.hikeLocation << ")" << endl;
    out << "    Difficulty: " << myHike.hikeDifficulty << endl;
    out << "    Duration: " << myHike.hikeDurationDays << " day(s)";
	
    return out;
}

Hike::Hike(string myLocation, string myHikeName,
    int myHikeDurationDays, char myHikeDifficulty)
{
    hikeLocation = myLocation;
    hikeName = myHikeName;
    hikeDurationDays = myHikeDurationDays;
    hikeDifficulty = myHikeDifficulty;
}

// Accessor Functions
string Hike::getHikeLocation() const
{
    return hikeLocation;
}

string Hike::getHikeName() const
{
    return hikeName;
}

int Hike::getHikeDuration() const
{
    return hikeDurationDays;
}

string Hike::getHikeDifficulty() const
{
    switch (hikeDifficulty)
    {
        case 'e':
            return "easy";
        case 'm':
            return "moderate";
        case 's':
            return "strenuous";
    }
}

