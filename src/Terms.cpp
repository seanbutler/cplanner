//
// Created by sean on 04/12/2020.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Terms.h"


std::string termTypeStr[] = {
    "TERM",
    "VARIABLE",
    "CONSTANT"
};

std::ostream& operator<<(std::ostream& os, const Term& T)
{
    os << termTypeStr[T.type] << " " /* << T.type */;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Variable& V)
{

    os << termTypeStr[V.type] /*<< " "  << V.type */ << " " << V.name;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Constant& C)
{
    os << termTypeStr[C.type] /* << " " << C.type */ << " " << C.value;
    return os;
}
