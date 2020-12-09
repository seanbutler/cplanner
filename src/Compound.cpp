//
// Created by sean on 04/12/2020.
//

#include "Compound.h"

std::ostream& operator<<(std::ostream& os, const Compound& S)
{
    os << S.func << "( ";
    for ( auto B : S.terms){
        os << B << " ";
    }
    os << ") ";

    return os;
}

