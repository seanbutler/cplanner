//
// Created by sean on 05/12/2020.
//

#include "Action.h"
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Action& A)
{
    const unsigned int width = 8;
    os << std::left << std::setw(width) << "IF ";
    for ( auto F = A.preconditionList.begin();
              F < A.preconditionList.end();
              F++)
    {
        os << *F;
        os << std::endl;

        if (F != A.preconditionList.end()-1) {
            os << std::left << std::setw(width) << "AND ";
        }

    }

    for ( auto F : A.subtractiveFacts){
        os << std::left << std::setw(width) << "REMOVE " <<  F << std::endl;
    }

    for ( auto F : A.additiveFacts){
        os << std::left << std::setw(width) << "ADD " << F << std::endl;
    }

    return os;
}
