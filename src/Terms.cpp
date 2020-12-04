//
// Created by sean on 04/12/2020.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Terms.h"

// ----------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Term& T)
{
    std::string termTypeStr[] = {
            "TERM",
            "VARIABLE",
            "CONSTANT"
    };

    os << "[" << termTypeStr[T.type] << ":" << T.value << "]";
    return os;
}

// ----------------------------------------------------------------------
