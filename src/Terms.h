

#ifndef CPPPL_TERMS_H
#define CPPPL_TERMS_H


#include <iostream>
#include <vector>
#include <string>
#include <map>


//#include "Substitution.h"

class Substitution;

// ----------------------------------------------------------------------

enum TermType {
    TERM = 0,
    VARIABLE = 1,
    CONSTANT = 2
};

// ----------------------------------------------------------------------

class Term {

public:
    virtual ~Term()             { };
    virtual TermType getType()  { return type; };
    virtual Term* dup() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Term& T);

private:
    static const TermType type = TermType::TERM;
};

// ----------------------------------------------------------------------

class Variable : public Term {
public:
    Variable(std::string N)
    :   name(N)
    {
    }

    virtual TermType getType()                  { return type; }
    Term * dup()                                { return new Variable(name); }
    friend std::ostream& operator<<(std::ostream& os, const Variable& T);

    std::string name;

private:
    static const TermType type = TermType::VARIABLE;

};

// ----------------------------------------------------------------------


class Constant : public Term{
public:
    Constant(std::string V)
    :   value(V)
    {

    }
    virtual TermType getType()              { return type; }
    Term* dup()                             { return new Constant(value); }
    friend std::ostream& operator<<(std::ostream& os, const Constant& C);

    std::string value;

public:
    static const TermType type = TermType::CONSTANT;
};

// ----------------------------------------------------------------------

#endif //CPPPL_TERMS_H
