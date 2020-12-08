//
// Created by sean on 05/12/2020.
//

#include "Action.h"

std::ostream& operator<<(std::ostream& os, const Action& A)
{
    for ( auto F : A.preconditionList){
        os << "COND " << F << std::endl;
    }

    for ( auto F : A.subtractiveFacts){
        os << "SUB " <<  F << std::endl;
    }

    for ( auto F : A.additiveFacts){
        os << "ADD " << F << std::endl;
    }

    return os;
}
