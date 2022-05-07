/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#ifndef HIKE_H
#define HIKE_H

#include <string>
#include <iostream>

/**
 * Interface of the class Hike.
 */
class Hike
{

    friend std::ostream& operator<<(std::ostream& out, const Hike& myObj);

public:
    // Default constructor
    Hike();

    Hike(const std::string newLocation, const std::string newHikeName,
            int newDuration, char newDifficulty);

    // Accessor Function
    std::string getHikeLocation() const;
    std::string getHikeName() const;
    int getHikeDuration() const;
    std::string getHikeDifficulty() const;

private:
    std::string location;
    std::string hikeName;
    int duration;
    char difficulty;
};

#endif