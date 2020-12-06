//
// Created by sean on 04/12/2020.
//

#ifndef CPPPL_WORLD_H
#define CPPPL_WORLD_H

// ----------------------------------------------------------------------

#include "Terms.h"
#include "Compound.h"

// ----------------------------------------------------------------------

class World {
public:
    World() { }

    friend std::ostream& operator<<(std::ostream& os, const World& S);

    void Add(Compound F){
        facts.push_back(F);
    }

    std::vector<Compound> facts;
};


// ----------------------------------------------------------------------

#endif //CPPPL_WORLD_H
