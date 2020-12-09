//
// Created by sean on 04/12/2020.
//

#include "Context.h"
#include "Terms.h"

std::ostream& operator<<(std::ostream& os, const Context& S)
{
    for ( auto B : S.bindings){
        os <<  B.first << " -> " <<  B.second << std::endl;
    }
    return os;
}

unsigned int Context::NewBinding(Term T1, Term T2) {
    bindings.push_back(std::make_pair(T1, T2));
    return bindings.size();
}
