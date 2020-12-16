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

Compound Compound::Reify(Context & C, World & W) {
    Compound actualCompound;
    for ( auto T : this->terms ) {
        actualCompound.terms.push_back(T.Reify(C));
    }
    std::cout << actualCompound;

    return actualCompound;
}

//std::vector<Compound> Compound::Filter(World & W) {
//    std::vector<Compound> results;
//    for (auto F : W.facts ) {
//
//        if ( F == *this)
//        {
//            results.push_back(F);
//        }
//    }
//    return results;
//}

World Compound::Query(World & W) {

//    std::vector<Compound> results;
    World result;

    for (auto F : W.facts )
    {
        for ( unsigned int i = 0; i < F.terms.size(); i++)
        {
            if (F.terms[i].type != VARIABLE)
            {
                if ( F.terms[i] == terms[i])
                {
                    result.facts.push_back(F);
                }
            }
        }
    }

    return result;
}

