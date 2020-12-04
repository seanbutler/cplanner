


#include <iostream>

#include "src/Terms.h"
#include "src/Substitution.h"

// ----------------------------------------------------------------------

int main(int argc, char **argv) {


    Variable v1("GIRL");
    Constant c1("leia");

    Term* termPtr = &v1;
    std::cout << termPtr->getType() << std::endl;
    std::cout << v1.getType() << std::endl;
    std::cout << c1.getType() << std::endl;

    Substitution substitution;

    substitution.AddBinding(&v1, &c1);


    return 0;
}
