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

    void AddBinding(Variable* variable, Variable* other) {
        bindings.push_back(std::make_pair<>((Variable*)variable, (Term*)other));
    }

    Term* GetValue(Variable* variable) {
        for ( unsigned int i = 0; i<bindings.size(); i++) {
            if (bindings[i].second->getType() == TermType::VARIABLE) {

            }
        }
        return (Term*)variable;
    }

    std::vector<std::pair<Variable*, Term*>> bindings;
};


#endif //CPPPL_SUBSTITUTION_H
