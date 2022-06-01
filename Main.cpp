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
    
    HikeList newHikeList;
    getHikeData(newHikeList);
    
    MemberList newMemberList;
    getMemberData(newMemberList);

    Reservations reservationList;
    getReservationData(reservationList);
    
    displayMenu();
    processReservation(newHikeList, newMemberList, reservationList);

    return 0;
}