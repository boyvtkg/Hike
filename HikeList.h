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

class HikeList
{
public:
    HikeList() {}

    void addHike(const Hike& newHike, double newPrice);
    void addHike(const std::string& location, const std::string& hikeName, 
        int duration, char difficulty, double newPrice);

    double getPrice(const std::string& hikeName) const;

    void printAllLocations() const;
    void printByLocation(const std::string& location) const;
    void printByDuration() const;
    void printByDuration(int days) const;
    void printByDifficulty(char difficulty) const;
    void printByPrice() const;
    void printByHikeName(const std::string& hikeName) const;

    void clearList();
    ~HikeList() {}    
private:
	std::multimap<Hike, double> theHikeList;
};

#endif
