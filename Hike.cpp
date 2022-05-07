/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#include "Hike.h"

using namespace std;

ostream& operator<<(std::ostream& out, const Hike& myObj)
{
    out << '\t' << myObj.hikeName << " (" << myObj.location << ")\n"
        << "\t  Difficulty: " << myObj.getHikeDifficulty() << '\n'
        << "\t  Duration: " << myObj.duration << " day(s)\n";
    return out;
}

Hike::Hike()
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

string Hike::getHikeLocation() const
{
    return location;
}

string Hike::getHikeName() const
{
    return hikeName;
}

int Hike::getHikeDuration() const
{
    return duration;
}

string Hike::getHikeDifficulty() const
{
    if (difficulty == 'e')
        return "easy";
    else if (difficulty == 'm')
        return "moderate";
    else if (difficulty == 's')
        return "strenuous";
    else
        return "";
}