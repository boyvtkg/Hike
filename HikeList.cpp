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
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


// Overloaded less operator
bool operator<(const Hike& firstObj, const Hike& secondObj)
{
    return (firstObj.getHikeLocation() < secondObj.getHikeLocation());
}

// Default constructor
HikeList::HikeList() {}

// Adding Hike functions
void HikeList::addHike(const Hike& newHike, double newPrice)
{
    myList.insert(make_pair(newHike, newPrice));
}

void HikeList::addHike(const string& location, const string& hikeName,
    int duration, char difficulty, double newPrice)
{
    Hike newHike(location, hikeName, duration, difficulty);
    myList.insert(make_pair(newHike, newPrice));
}

// Print Functions
double HikeList::getPrice(const string& hikeName) const
{
    auto iter = find_if(myList.begin(), myList.end(), [&](const auto& elem)
        {return elem.first.getHikeName() == hikeName; });
    return iter->second;
}

void HikeList::printAllLocations() const
{
    auto iter = myList.begin();
    while (iter != myList.end())
    {
        cout << '\t' << (iter->first).getHikeLocation() << endl;
        iter = myList.upper_bound(iter->first);
    }
}

void HikeList::printByLocation(const string& location) const
{

    auto iter = myList.begin();
    auto iterEnd = myList.end();
    iter = find_if(iter, iterEnd, [&](const auto& elem)
        {return elem.first.getHikeLocation() == location; });
    cout << fixed << showpoint << setprecision(2);

    while (iter != iterEnd)
    {

        cout << '\t' << iter->first.getHikeName() << " (" << location << ")" << endl
            << "\t  Difficulty: " << (iter->first).getHikeDifficulty() << endl
            << "\t  Duration: " << (iter->first).getHikeDuration() << " day(s)" << endl
            << "\t  Price (per person): $ " << iter->second << endl;

        ++iter;
        iter = find_if(iter, iterEnd, [&](const auto& elem)
            {return elem.first.getHikeLocation() == location; });
        cout << endl;
    }
}

void HikeList::printByDuration() const
{
    multimap<int, string> tempList;

    for (const auto& elem : myList)
    {
        tempList.insert(make_pair(elem.first.getHikeDuration(),
            elem.first.getHikeLocation()));
    }

    for_each(tempList.begin(), tempList.end(), [](const auto& elem)
        {cout << "\t(" << elem.first << ") " << elem.second << endl; });
}

void HikeList::printByDifficulty(char difficulty) const
{
    for (const auto& elem : myList)
    {
        if (elem.first.getHikeDifficulty().front() == difficulty)
            cout << "\t(" << difficulty << ") " << elem.first.getHikeName() << ", "
            << elem.first.getHikeLocation() << endl;
    }
}

void HikeList::printByPrice() const
{
    multimap<double, pair<string, string>> tempList;
    for (const auto& elem : myList)
    {
        pair<string, string> newPair(elem.first.getHikeLocation(), elem.first.getHikeName());
        tempList.emplace(elem.second, newPair);
    }
    cout << fixed << showpoint << setprecision(2);

    for (const auto& elem : tempList)
    {
        cout << "\t$ " << setw(7) << elem.first << " - "
            << elem.second.first << " (" << elem.second.second << ")\n";
    }
}

void HikeList::printByHikeName(const string& hikeName) const
{
    cout << fixed << showpoint << setprecision(2);

    auto iter = find_if(myList.begin(), myList.end(), [&](const auto& elem)
        {return elem.first.getHikeName() == hikeName; });

    cout << '\t' << hikeName << " (" << iter->first.getHikeLocation() << ")\n"
        << "\t  Difficulty: " << (iter->first).getHikeDifficulty() << endl
        << "\t  Duration: " << iter->first.getHikeDuration() << " day(s)\n"
        << "\t  $" << iter->second << endl;

}

void HikeList::clearList()
{
    myList.clear();
}