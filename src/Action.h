//
// Created by sean on 05/12/2020.
//

#ifndef CPLANNER_ACTION_H
#define CPLANNER_ACTION_H

// ----------------------------------------------------------------------

#include "Terms.h"
#include "World.h"
#include "Compound.h"

// ----------------------------------------------------------------------

class Action {

public:
    Action(){}

    friend std::ostream& operator<<(std::ostream& os, const Action& S);

    void Apply(World & W){
        if ( Test(W)) {
            Add(W);
            Remove(W);
        }
    }

    bool Test(World & W){
        unsigned int count = 0;
        for (auto F : W.facts) {
            for (auto PC : preconditionList) {
                if (F.Equals(PC))
                {
                    count++;
                    break;
                }
            }
        }

        if ( count >= preconditionList.size()){
            return true;
        }

        return false;
    }

    void Add(World & W) {
        for (auto PC : additiveFacts) {
            W.facts.push_back(PC);
        }
    }

    void Remove(World & W) {
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

    void NewPrecondition(Compound F) {
        preconditionList.push_back(F);
    }

    void NewAdditiveFact(Compound F) {
        additiveFacts.push_back(F);
    }

    void NewSubtractiveFact(Compound F) {
        subtractiveFacts.push_back(F);
    }

// TODO refactor so there are +ve and -ve preconditions

//    std::vector<Compound>positivePreconditionList;
//    std::vector<Compound>negativePreconditionList;

    std::vector<Compound>preconditionList;
    std::vector<Compound>additiveFacts;
    std::vector<Compound>subtractiveFacts;
};

#endif //CPLANNER_ACTION_H
