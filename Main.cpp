/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#include "Member.h"
#include "MemberList.h"
#include <iostream>

using namespace std;

int main()
{
    //Member newMember("Grandma", "Gatewood");
    //newMember.addPoints(25876);
    //newMember.setID(123);
    //cout << newMember.getID() << endl;
    //cout << newMember.getLastName() << endl;
    //cout << newMember.getPoints() << endl;
    //newMember.printMember();
    MemberList newList;
    newList.addMember("Thanh", "Pham");
    newList.addMember("Dani", "Ekbote", 4);
    //cout << newList.getLastID();
    newList.printMember(111, "Phaam");
    newList.printMember(112, "Ekbote");
    //cout << newList.getPoints(112);

}