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
    Compound() {
    }

    Compound(Term F) {
        terms.push_back(F);
    }

    virtual ~Compound() {
        terms.clear();
    }

    Compound(Term F, Term A1)
    {
        terms.push_back(F);
        terms.push_back(A1);
    }

    Compound(Term F, Term A1, Term A2)
    {
        terms.push_back(F);
        terms.push_back(A1);
        terms.push_back(A2);
    }

    void AddTerm(Term A) {
        terms.push_back(A);
    }

    Compound & operator=(const Compound & other){
        if (this != &other) {
            this->terms.erase(this->terms.begin(), this->terms.end());
            this->terms = other.terms;
        }
        return *this;
    }

    bool operator==(const Compound & other){
        unsigned int count = 0;
        for (unsigned int i =0; i<terms.size(); i++){
            if (this->terms[i] == other.terms[i]){
                count++;
            }
        }

        if ( count >= this->terms.size()){
            return true;
        }

        return false;
    }



    friend std::ostream& operator<<(std::ostream& os, const Compound& S);
    Compound Evaluate(Context & C, World & W);
    std::vector<Compound> Query(World & W);

    std::vector<Term> terms;
};

#endif // CPPPL_COMPLEX_H
