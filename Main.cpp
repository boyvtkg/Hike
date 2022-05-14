/*
    Demon
    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/
#include "HikeReader.h"
#include "MemberReader.h"
#include "ReservationReader.h"
#include "Interface.h"

using namespace std;

int main()
{
    //Hike newHike("Montana", "Glacier", 6, 's');
    //cout << newHike;
    //cout << newHike.getHikeLocation() << endl;
    //cout << newHike.getHikeName() << endl;
    //cout << newHike.getHikeDuration() << endl;
    //cout << newHike.getHikeDifficulty() << endl;
    HikeList newHikeList;
    getHikeData(newHikeList);
    //newHikeList.printAllLocations();
    //newHikeList.printByLocation("California");
    //newHikeList.printByDuration();
    //newHikeList.printByDuration(3);
    //newHikeList.printByDifficulty('e');
    //newHikeList.printByPrice();
    //newHikeList.printByHikeName("Yosemite");
    //Member newMember("Grandma", "Gatewood");
    //newMember.addPoints(25876);
    //newMember.setID(123);
    //cout << newMember.getID() << endl;
    //cout << newMember.getLastName() << endl;
    //cout << newMember.getPoints() << endl;
    //newMember.printMember();
    MemberList newMemberList;
    getMemberData(newMemberList);

    //newMemberList.~MemberList();
    //newMemberList.printMember(111, "Gatewood");
    //cout << newMemberList.getLastID() << endl;
    //cout << newMemberList.getPoints(136) << endl;
    Reservations reservationList;
    getReservationData(reservationList);
    //reserList.cancelReservation(50003);
    //reserList.printForward();
    //cout << endl;
    //reserList.printReverse();
    //cout << endl;
    //reserList.printReservation(50008, newHikeList, newMemberList);
    //HikeList newHikeList;
    //MemberList newMemberList;
    //Reservations reserList;
    displayMenu();
    processReservation(newHikeList, newMemberList, reservationList);
}