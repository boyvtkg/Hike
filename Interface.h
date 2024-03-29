/*
    Demon

    Pham, Thanh

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

#include <string>

void displayMenu();
void processReservation(HikeList& hikeList, 
    MemberList& memberList, Reservations& reservationList);
void chooseByLocation(HikeList& hikeList, 
    MemberList& memberList, Reservations& reservationList);
void chooseByDuration(HikeList& hikeList, 
    MemberList& memberList, Reservations& reservationList);
void chooseByDifficulty(HikeList& hikeList, 
    MemberList& memberList, Reservations& reservationList);
void chooseByPrice(HikeList& hikeList, 
    MemberList& memberList, Reservations& reservationList);
void makeReservation(HikeList& hikeList, 
    MemberList& memberList, Reservations& reservationList);
void viewReservation(HikeList& hikeList, 
    MemberList& memberList, Reservations& reservationList);
void cancelReservation(HikeList& hikeList, 
    MemberList& memberList, Reservations& reservationList);
void askToReserve(HikeList& hikeList, 
    MemberList& memberList, Reservations& reservationList);
int askIfMember(MemberList& memberList);
int addNewMember(MemberList& memberList);

#endif