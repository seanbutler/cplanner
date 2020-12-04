

#ifndef CPPPL_TERMS_H
#define CPPPL_TERMS_H


#include <iostream>
#include <vector>
#include <string>
#include <map>

// ----------------------------------------------------------------------

enum TermType {
    TERM = 0,
    VARIABLE = 1,
    CONSTANT = 2
};

// ----------------------------------------------------------------------

class Term {

public:
    Term(std::string V, TermType T = TERM)
    : value(V)
    , type(T)
    {
    }

    virtual TermType getType()  { return type; };
    friend std::ostream& operator<<(std::ostream& os, const Term& T);

    const TermType type;
    std::string value;
};

// ----------------------------------------------------------------------

#endif //CPPPL_TERMS_H
