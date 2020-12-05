//
// Created by sean on 04/12/2020.
//

#include "Complex.h"

std::ostream& operator<<(std::ostream& os, const Complex& S)
{
    for ( auto B : S.terms){
        os << B << " ";
    }
//    os << std::endl;
    return os;
}

