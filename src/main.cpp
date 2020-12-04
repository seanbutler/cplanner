


#include <iostream>

#include "Terms.h"
#include "Substitution.h"

// ----------------------------------------------------------------------

int main(int argc, char **argv) {

    Variable v1("GIRL");
    Constant c1("leia");

    Variable v2("BOY");
    Constant c2("luke");

    Variable v3("DROID");
    Constant c3("r2d2");

    Variable v4("DROID");
    Constant c5("c3po");

    Term* termPtr = &v1;
    std::cout << termPtr->getType() << std::endl;
    std::cout << v1.getType() << std::endl;
    std::cout << c1.getType() << std::endl;
//    std::cout << c1.getValue() << std::endl;

    Substitution substitution;

    substitution.AddBinding(&v1, &c1);

    return 0;
}
