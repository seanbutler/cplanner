//
// Created by sean on 04/12/2020.
//

#ifndef CPPPL_CONTEXT_H
#define CPPPL_CONTEXT_H

#include <iostream>
#include <vector>

class Term;

// ----------------------------------------------------------------------

class Context {
public:
    Context() {}
    virtual ~Context() {}

    friend std::ostream& operator<<(std::ostream& os, const Context& S);

    unsigned int NewBinding(Term T1, Term T2);

    std::vector<std::pair<Term, Term>> bindings;
};

#endif //CPPPL_CONTEXT_H
