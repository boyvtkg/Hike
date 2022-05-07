#include "MemberList.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Member newObj("Thanh", "Pham");
    // newObj.printMember();
    MemberList newList;
    newList.addMember("Thanh", "Pham");
    newList.addMember("Dani", "Ekbote");
}