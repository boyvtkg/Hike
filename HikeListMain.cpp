/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#include "HikeList.h"
#include "Hike.h"

using namespace std; 


int main()
{
    //Hike newHike("California", "Yosemite", 7, 'm');
    //cout << newHike;
    //cout << newHike.getHikeLocation() << endl;
    //cout << newHike.getHikeName() << endl;
    //cout << newHike.getHikeDuration() << endl;
    //cout << newHike.getHikeDifficulty() << endl;
    HikeList newList;
    newList.addHike("California", "Yosemite", 6, 'm', 3099);
    newList.addHike("California", "Redwood", 2, 'e', 245);
    newList.addHike("Utah", "Zion", 3, 's', 1099);
    newList.addHike("Utah", "Bryce", 4, 'm', 2099);
    newList.addHike("Alaska", "CuaHD", 4, 's', 5099);
    newList.addHike("Arizona", "Sedona", 4, 'e', 5099);
    newList.addHike("Georgia", "Savannah", 3, 'e', 499);
    newList.addHike("Montana", "Glacier", 6, 's', 3999);
    //newList.printAllLocations();
    //newList.printByLocation("California");
    //newList.printByDuration();
    //newList.printByDifficulty('e');
    //newList.printByPrice();
    newList.printByHikeName("Yosemite");
}