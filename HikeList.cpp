/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#include "HikeList.h"
#include <iomanip>
#include <algorithm>

using namespace std;

bool operator<(const Hike& firstObj, const Hike& secondObj)
{
    return (firstObj.getHikeLocation() < secondObj.getHikeLocation());
}

HikeList::HikeList() {}

void HikeList::addHike(const Hike& newHike, double newPrice)
{
    theHikeList.insert(make_pair(newHike, newPrice));
}

void HikeList::addHike(const string& location, const string& hikeName,
                        int duration, char difficulty, double newPrice)
{
    Hike newHike(location, hikeName, duration, difficulty);
    theHikeList.insert(make_pair(newHike, newPrice));
}

double HikeList::getPrice(const string& hikeName) const
{
    auto iter = find_if(theHikeList.begin(), theHikeList.end(), [&](const auto& elem)
                        {return elem.first.getHikeName() == hikeName; });
    return iter->second;
}

void HikeList::printAllLocations() const
{
    auto iter = theHikeList.begin();
    while (iter != theHikeList.end())
    {
        cout << '\t' << (iter->first).getHikeLocation() << endl;
        iter = theHikeList.upper_bound(iter->first);
    }
}

void HikeList::printByLocation(const string& location) const
{

    auto iter = theHikeList.begin();
    auto iterEnd = theHikeList.end();
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

    for (const auto& elem : theHikeList)
    {
        tempList.insert(make_pair(elem.first.getHikeDuration(), elem.first.getHikeLocation()));
    }

    for_each(tempList.begin(), tempList.end(), [](const auto& elem)
            {cout << "\t(" << elem.first << ") " << elem.second << endl; });
}

void HikeList::printByDifficulty(char difficulty) const
{
    for (const auto& elem : theHikeList)
    {
        if (elem.first.getHikeDifficulty().front() == difficulty)
            cout << "\t(" << difficulty << ") " << elem.first.getHikeName() << ", "
                 << elem.first.getHikeLocation() << endl;
    }
}

void HikeList::printByPrice() const
{
    multimap<double, pair<string, string>> tempList;

    for (const auto& elem : theHikeList)
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

    auto iter = find_if(theHikeList.begin(), theHikeList.end(), [&](const auto& elem)
                        {return elem.first.getHikeName() == hikeName; });

    cout << '\t' << hikeName << " (" << iter->first.getHikeLocation() << ")\n"
         << "\t  Difficulty: " << (iter->first).getHikeDifficulty() << endl
         << "\t  Duration: " << iter->first.getHikeDuration() << " day(s)\n"
         << "\t  $" << iter->second << endl;

}

void HikeList::clearList()
{
    theHikeList.clear();
}