//
// Created by sean on 04/12/2020.
//

#ifndef CPPPL_SUBSTITUTION_H
#define CPPPL_SUBSTITUTION_H

#include <iostream>
#include <vector>

#include "Terms.h"

// ----------------------------------------------------------------------

class Substitution {
public:
    Substitution() {}
    virtual ~Substitution() {}

    void AddBinding(Variable* variable, Constant* constant) {
        bindings.push_back(std::make_pair<>((Variable*)variable, (Term*)constant));
    }

    Term* GetValue(Term* variable) {
        for ( unsigned int i = 0; i<bindings.size(); i++) {

            if (bindings[i].second->getType() == TermType::CONSTANT) {
                return bindings[i].second;
            }

            if (bindings[i].second->getType() == TermType::VARIABLE) {
                return GetValue(bindings[i].second);
            }
        }
        return (Term*)variable;
    }



    std::vector<std::pair<Variable*, Term*>> bindings;
};


#endif //CPPPL_SUBSTITUTION_H
