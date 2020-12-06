

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
            , type(T) {

    }

    Term(const Term & other)
            : value(other.value)
            , type(other.type) {

    }

    void operator = (const Term & other ) {
        this->value = other.value;
        this->type = other.type;
    }

    bool operator == (const Term & other ) {
        return (( this->value == other.value) &&  ( this->type == other.type ));
    }

    virtual TermType getType()  { return type; };
    friend std::ostream& operator<<(std::ostream& os, const Term& T);

    std::string value;
    TermType type;
};

// ----------------------------------------------------------------------

#endif //CPPPL_TERMS_H
