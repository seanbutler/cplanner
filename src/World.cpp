//
// Created by sean on 04/12/2020.
//

#include "World.h"

std::ostream& operator<<(std::ostream& os, const World& W)
{
    for ( auto F : W.facts){
        os << F << std::endl;
    }
    return os;
}

