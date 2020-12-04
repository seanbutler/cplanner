//
// Created by sean on 04/12/2020.
//

#ifndef CPPPL_COMPLEX_H
#define CPPPL_COMPLEX_H


#include <iostream>
#include <map>

#include "Terms.h"

// ----------------------------------------------------------------------

class Complex {

public:
    Complex(Term A)
    {
        terms.push_back(A);
    }

    Complex(Term A1, Term A2)
    {
        terms.push_back(A1);
        terms.push_back(A2);
    }

    Complex(Term A1, Term A2, Term A3)
    {
        terms.push_back(A1);
        terms.push_back(A2);
        terms.push_back(A3);
    }

    void Dump(){
        for (auto A : terms) {
            std::cout << A << " ";
        }
        std::cout << std::endl;
    }

    bool Equals(Complex F) {
//        unsigned int i=0;
//        for (auto A : terms) {
//            if ( F.terms[i] != A )
//                return false;
//            i++;
//        }
        return true;
    }

    std::vector<Term> terms;
};

#endif //CPPPL_COMPLEX_H
