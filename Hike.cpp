/*
    Demon

    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& obj)
{
    string difficulty;
    if (obj.getHikeDifficulty() == 'e')
        difficulty = "easy";
    else if (obj.getHikeDifficulty() == 'm')
        difficulty = "moderate";
    else if (obj.getHikeDifficulty() == 's')
        difficulty = "strenuous";
    out << '\t' << obj.hikeName << " (" << obj.location << ")\n"
        << "\t  Difficulty: " << difficulty << '\n'
        << "\t  Duration: " << obj.duration << " day(s)\n";
    return out;
}

Hike::Hike(const string& newLocation, const string& newHikeName, 
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

char Hike::getHikeDifficulty() const
{
    return difficulty;
}

bool Hike::operator<(const Hike& paramObj) const
{
    return (location < paramObj.location);
}