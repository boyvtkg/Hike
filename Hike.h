/*
    Demon

    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

class Hike
{
    friend std::ostream& operator<<(std::ostream& out, const Hike& obj);
public:
    Hike() : duration(0), difficulty('e') {}
    Hike(const std::string& newLocation, const std::string& newHikeName, 
        int newDuration, char newDifficulty);

    std::string getHikeLocation() const;
    std::string getHikeName() const;
    int getHikeDuration() const;
    char getHikeDifficulty() const;

    bool operator<(const Hike& paramObj) const;

    ~Hike() {}
private:
    std::string location;
    std::string hikeName;
    int duration;
    char difficulty;
};

#endif