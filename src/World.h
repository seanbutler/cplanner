//
// Created by sean on 04/12/2020.
//

#ifndef CPPPL_WORLD_H
#define CPPPL_WORLD_H

// ----------------------------------------------------------------------

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

// ----------------------------------------------------------------------

class Compound;

// ----------------------------------------------------------------------

class World {
public:
    World() {
        uid = boost::uuids::random_generator()();
    }

    ~World() {
        facts.clear();
    }

    friend std::ostream& operator<<(std::ostream& os, const World& S);

    void Add(Compound F);
    std::vector<Compound> facts;
    boost::uuids::uuid uid;
};

// ----------------------------------------------------------------------

#endif //CPPPL_WORLD_H
