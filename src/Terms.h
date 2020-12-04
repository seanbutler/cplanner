

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
    virtual ~Term()             {};
    virtual TermType getType()  { return type; };
    virtual Term* dup() = 0;
    Term* clone();
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

    virtual TermType getType() {return type;}
    Term * dup(){ return new Variable(name); }

//    const Term* getValue(const Substitution & assoc){
//        return assoc->getBound(this);
//    }

protected:
    std::string name;

private:
    static const TermType type = TermType::VARIABLE;

};


class Constant : public Term{
public:
    Constant(std::string V)
    :   value(V)
    {

    }
    virtual TermType getType() {return type;}
    static const TermType type = TermType::CONSTANT;


    Term* dup(){
        return new Constant(value);
    }

//    const Term* getValue(const Substitution & assoc){
//        return this;
//    }

protected:
    std::string value;
};


// ----------------------------------------------------------------------


#endif //CPPPL_TERMS_H
