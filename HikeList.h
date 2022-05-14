/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#ifndef HIKELIST_H
#define HIKELIST_H

#include "Hike.h"
#include <string>
#include <map>

/**
 * Interface of the class HikeList.
 */
class HikeList
{
    // Overloaded less operator for comparing 2 Locations from 2 Hike objects
    friend bool operator<(const Hike& firstObj, const Hike& secondObj);

public:
	// Default constructor
    HikeList( );

	// Adding Hike functions
    void addHike(const Hike& newHike, double newPrice);

    void addHike(const std::string& location, const std::string& hikeName,
                    int duration, char difficulty, double newPrice);

    // Accessor Function
    double getPrice(const std::string& hikeName) const;

    // Print Functions
    void printAllLocations() const;

    void printByLocation(const std::string& location) const;

    void printByDuration() const;

    void printByDuration(int days) const;

    void printByDifficulty(char difficulty) const;

    void printByPrice() const;

    void printByHikeName(const std::string& hikeName) const;

    // The function to empty 
    void clearList();
    
private:
	std::multimap<Hike, double> theHikeList;
};

#endif
