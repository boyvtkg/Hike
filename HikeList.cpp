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

#include "HikeList.h"
#include <string>
#include <map>

using namespace std;

auto iter = myList.begin();
auto iterEnd = myList.end();

void HikeList::addHike(const Hike& newHike, double newPrice)
{
}

void HikeList::addHike(const string& locationName, const string& hikeName,
                        int duration, char difficulty, double newPrice)
{
}

double HikeList::getPrice(const string& hikeName)
{
    auto it = find_if(iter, iterEnd, [ ] (const auto& elem) {return elem.hikeName == hikeName;} );
    return it->second;
}

void HikeList::printAllLocations()
{
    cout << for ();
}

void HikeList::printByLocation(const string& location)
{

}

void HikeList::printByDuration(int duration)
{

}

void HikeList::printByDifficulty(char difficulty)
{

}

void HikeList::printByPrice(double price)
{

}

void HikeList::printByHikeName(const string& hikeName)
{

}
