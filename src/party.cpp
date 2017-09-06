/**
	Party class, party.cpp
	Purpose: To server as the blueprint of our one party
*/
#include <iostream>
#include "party.h"

Party::Party()
{
    for (int denomination = 0; denomination < sizeof(this->purse)/sizeof(this->purse[0]))
    {
        this->purse[denomination] = 0;
    }
//    this->purse[0] = 0;
};