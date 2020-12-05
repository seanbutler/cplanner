//
// Created by sean on 04/12/2020.
//

#ifndef CPPPL_WORLD_H
#define CPPPL_WORLD_H

// ----------------------------------------------------------------------

#include "Terms.h"
#include "Complex.h"

// ----------------------------------------------------------------------

class World {
public:
    World()
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const World& S);


    void Add(Complex F){
        facts.push_back(F);
    }

    void Dump(){
        for (auto F : facts) {
            F.Dump();
        }
    }

    std::vector<Complex> facts;
};

// ----------------------------------------------------------------------

class Action {
public:
    Action(){}

    bool Test(World & W){
        unsigned int count = 0;
        for (auto PC : preconditionList) {
            for (auto F : W.facts) {
                if (F.Equals(PC))
                {
                    count++;
                    break;
                }
            }
        }

        if ( count == preconditionList.size()){
            return true;
        }

        return false;
    }

    void Remove(World & W){
        unsigned int count = 0;
        for (auto PC : subtractiveFacts) {
            for (unsigned int i = 0; i<W.facts.size(); i++) {
                if (W.facts[i].Equals(PC))
                {
                    W.facts.erase(W.facts.begin()+i);
                }
            }
        }
    }

    void Apply(World & W){
        if ( Test(W)) {
            Remove(W);
        }
    }

    void NewPrecondition(Complex F) {
        preconditionList.push_back(F);
    }

    void NewAdditiveFact(Complex F) {
        additiveFacts.push_back(F);
    }

    void NewSubtractiveFact(Complex F) {
        subtractiveFacts.push_back(F);
    }

    std::vector<Complex>preconditionList;
    std::vector<Complex>additiveFacts;
    std::vector<Complex>subtractiveFacts;
};

// ----------------------------------------------------------------------

#endif //CPPPL_WORLD_H
