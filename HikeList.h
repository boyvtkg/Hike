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
#ifndef HIKELIST_H
#define HIKELIST_H

#include <string>
#include <iostream>
#include <map>

class HikeList : public Hike
{
public:
	HikeList( );
		// Default constructor

	void addHike(const Hike& myHike, double newPrice);

    void HikeList::addHike(const string& locationName, const string& hikeName,
                            int duration, char difficulty, double newPrice);

    double getPrice(const string& hikeName);

    void printAllLocations();

    void printByLocation(const string& location);

    void printByDuration(int duration);

    void printByDifficulty(char difficulty);

    void printByPrice(double price);

    void printByHikeName(const string& hikeName);
    
	~HikeList( ); 
		//Destructor

private:
	multimap<Hike, double> myList;
};

#endif
