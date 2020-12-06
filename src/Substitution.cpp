//
// Created by sean on 04/12/2020.
//

#include "Substitution.h"

std::ostream& operator<<(std::ostream& os, const Substitution& S)
{
    for ( auto B : S.bindings){
        os << *(B.first) << " -> " << *(B.second) << std::endl;
    }
    return os;
}

