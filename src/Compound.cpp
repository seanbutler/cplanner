//
// Created by sean on 04/12/2020.
//

#include "Compound.h"

std::ostream& operator<<(std::ostream& os, const Compound& S)
{
    for ( auto B : S.terms){
        os << B << " ";
    }

    return os;
}

Compound Compound::Evaluate(Context & C, World & W) {
    Compound actualCompound;
    for ( auto T : this->terms ) {
        actualCompound.terms.push_back(T.GetActualValue(C));
    }
    std::cout << actualCompound;

    return actualCompound;
}

std::vector<Compound> Compound::Query(World & W) {
    std::vector<Compound> results;
    for (auto F : W.facts ) {
        if ( F == *this)
        {
            results.push_back(F);
        }
    }
    return results;
}

