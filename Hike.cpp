/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& myObj)
{
    string difficulty;
    if (myObj.getHikeDifficulty() == 'e')
        difficulty = "easy";
    else if (myObj.getHikeDifficulty() == 'm')
        difficulty = "moderate";
    else if (myObj.getHikeDifficulty() == 's')
        difficulty = "strenuous";
    out << '\t' << myObj.hikeName << " (" << myObj.location << ")\n"
        << "\t  Difficulty: " << difficulty << '\n'
        << "\t  Duration: " << myObj.duration << " day(s)\n";
    return out;
}

Hike::Hike()
{
    duration = 0;
    difficulty = 'e';
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