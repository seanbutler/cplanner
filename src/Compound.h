//
// Created by sean on 04/12/2020.
//

#ifndef CPPPL_COMPLEX_H
#define CPPPL_COMPLEX_H


#include <iostream>
#include <map>

#include "Terms.h"

// ----------------------------------------------------------------------

class Compound {

public:
    Compound(Term F)
    : func(F)
    {
    }

    Compound(Term F, Term A1)
    : func(F)
    {
        terms.push_back(A1);
    }

    Compound(Term F, Term A1, Term A2)
    : func(F)
    {
        terms.push_back(A1);
        terms.push_back(A2);
    }

    Compound & operator=(const Compound & other){
        if (this != &other) {
            // TODO FILL IN COPY CONSTRUCTOR HERE
            this->func = other.func;
            this->terms.erase(this->terms.begin(), this->terms.end());
            this->terms = other.terms;
        }
        return *this;
    }

    void AddTerm(Term A)
    {
        terms.push_back(A);
    }

    friend std::ostream& operator<<(std::ostream& os, const Compound& S);

    bool Equals(Compound F) {
        unsigned int count = 0;
        if ( this->func == F.func ) {
            for (unsigned int i =0; i<terms.size(); i++){
                if (this->terms[i] == F.terms[i]){
                    count++;
                }
            }
        }

        if ( count >= this->terms.size()){
            return true;
        }

        return false;
    }

    Term func;
    std::vector<Term> terms;
};

#endif //CPPPL_COMPLEX_H
