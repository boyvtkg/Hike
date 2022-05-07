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

class Hike
{

friend std::ostream& operator<<(std::ostream& out, const Hike& myObj);

public:
	// Default constructor
    Hike( );

    Hike(const std::string newLocation, const std::string newHikeName,
            int newDuration, char newDifficulty);

    // Accessor Function
    std::string getLocation() const;
    std::string getHikeName() const;
    int getDuration();
    std::string getDifficulty() const;

private:
	std::string location;
    std::string hikeName;
    int duration;
    char difficulty;
};

#endif
