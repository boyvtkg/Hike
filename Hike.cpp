/*
    Demon
    Pham, Thanh
    
    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US    
*/
#include "Hike.h"
#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(std::ostream& out, const Hike& myObj)
{
     out << '\t' << myObj.hikeName << " (" << myObj.location << ")\n"
         << "\t  Difficulty: " << myObj.getDifficulty() << '\n'
         << "\t  Duration: " << myObj.duration << " day(s)\n";
     return out;
}

Hike::Hike( )
{
    duration = 0;
    difficulty = 'e';
}

Hike::Hike(const std::string newLocation, const std::string newHikeName,
            int newDuration, char newDifficulty)
{
    location = newLocation;
    hikeName = newHikeName;
    duration = newDuration;
    difficulty = newDifficulty;
}

string Hike::getDifficulty() const
{
    string result;
    switch (difficulty)
    {
        case 'e':
            result = "easy";
            break;
        case 'm':
            result = "moderate";
            break;
        case 's':
            result = "strenuous";
            break;
    }
    return result;
}
