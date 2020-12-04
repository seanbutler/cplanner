//
// Created by sean on 04/12/2020.
//

#ifndef CPPPL_COMPLEX_H
#define CPPPL_COMPLEX_H


#include <iostream>
#include <map>


#include "Terms.h"

// ----------------------------------------------------------------------

class Fact {

public:
    Fact(Variable A)
    {
        atoms.push_back(A);
    }

    Fact(Variable A1, Variable A2)
    {
        atoms.push_back(A1);
        atoms.push_back(A2);
    }

    Fact(Variable A1, Variable A2, Variable A3)
    {
        atoms.push_back(A1);
        atoms.push_back(A2);
        atoms.push_back(A3);
    }

    void Dump(){
//        for (auto A : atoms) {
//            std::cout << A. << " ";
//        }
    }

    bool Equals(Fact F) {
//        unsigned int i=0;
//        for (auto A : atoms) {
//            if ( F.atoms[i] != A )
//                return false;
//            i++;
//        }
        return true;
    }

    std::vector<Variable> atoms;
};



#endif //CPPPL_COMPLEX_H
