/*/*
    Demon

    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include "HikeList.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

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
    auto iter = find_if(theHikeList.begin(), theHikeList.end(),
        [& hikeName] (const auto& elem) 
        {return elem.first.getHikeName() == hikeName; });
    return iter->second;
}

void HikeList::printAllLocations() const
{
    auto iter = theHikeList.begin();
    auto iterEnd = theHikeList.end();
    while (iter != iterEnd)
    {
        cout << '\t' << iter->first.getHikeLocation() << endl;
        iter = theHikeList.upper_bound(iter->first);
    }
}

void HikeList::printByLocation(const string& location) const
{
    auto iter = theHikeList.begin();
    auto iterEnd = theHikeList.end();
    iter = find_if(iter, iterEnd, 
        [& location](const auto& elem) 
        {return elem.first.getHikeLocation() == location; });
    cout << fixed << showpoint << setprecision(2);

    while (iter != iterEnd)
    {
        cout << iter->first
             << "\t  Price (per person): $ " << iter->second << '\n';

        iter = find_if(++iter, iterEnd, [& location](const auto& elem)
            {return elem.first.getHikeLocation() == location; });
        cout << endl;
    }
}

void HikeList::printByDuration() const
{
    multimap<int, pair<string, string>> tempList;

    for (const auto& elem : theHikeList)
    {
        pair<string, string> newPair(elem.first.getHikeName(), elem.first.getHikeLocation());
        tempList.insert(make_pair(elem.first.getHikeDuration(), newPair));
    }

    for_each(tempList.begin(), tempList.end(),
        [](const auto& elem) {cout << "\t(" << elem.first << ") " 
        << elem.second.first << ", " << elem.second.second << endl; });
}

void HikeList::printByDuration(int days) const
{
    for (const auto& elem : theHikeList)
    {
        if (elem.first.getHikeDuration() == days)
        {
            cout << elem.first << endl;
        }
    }
}

void HikeList::printByDifficulty(char difficulty) const
{
    for (const auto& elem : theHikeList)
    {
        if (elem.first.getHikeDifficulty() == difficulty)
        {
            cout << "\t(" << difficulty << ") " << elem.first.getHikeName() << ", " 
                 << elem.first.getHikeLocation() << endl;
        }
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

    auto iter = find_if(theHikeList.begin(), theHikeList.end(), 
        [& hikeName](const auto& elem) {return elem.first.getHikeName() == hikeName; });

    cout << iter->first
         << "\t  $" << iter->second << '\n';

}

void HikeList::clearList()
{
    theHikeList.clear();
}