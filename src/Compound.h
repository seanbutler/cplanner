//
// Created by sean on 04/12/2020.
//

#ifndef CPPPL_COMPLEX_H
#define CPPPL_COMPLEX_H

// ----------------------------------------------------------------------

#include <iostream>
#include <map>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

// ----------------------------------------------------------------------

#include "Terms.h"
#include "World.h"

// ----------------------------------------------------------------------

// a compound is a list of terms used to represent a logical function (like an s-expression)

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

    std::vector<Compound> Query(World & W) {
        for (auto F : W.facts ) {
            if ( this->func == F.func ) {  // the funcs must match, no choice
                for (unsigned int i =0; i<terms.size(); i++){
                    if (this->terms[i].type == CONSTANT && F.terms[i].type == CONSTANT ) {

                    // WORKING HERE

                    }
                }
            }
        }
    }

    Term func;
    std::vector<Term> terms;
};

#endif //CPPPL_COMPLEX_H
