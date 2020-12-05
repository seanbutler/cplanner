
#include <iostream>

#include "Terms.h"
#include "Substitution.h"
#include "Complex.h"
#include "World.h"

// ----------------------------------------------------------------------

int main(int argc, char **argv) {

//    Term f1("LOC", TermType::TERM);
//    Term f2("ADJ", TermType::TERM);
//
//    Term v1("GIRL", TermType::VARIABLE);
//    Term c1("leia", TermType::CONSTANT);
//
//    Term v2("BOY", TermType::VARIABLE);
//    Term c2("luke", TermType::CONSTANT);
//
//    Term v3("DROID", TermType::VARIABLE);
//    Term c3("r2d2", TermType::CONSTANT);
//
//    Term v4("DROID", TermType::VARIABLE);
//    Term c4("c3po", TermType::CONSTANT);
//
//    Term l1("deathstar", TermType::CONSTANT);
//    Term l2("farm", TermType::CONSTANT);
//    Term l3("shack", TermType::CONSTANT);
//    Term l4("moseisley", TermType::CONSTANT);
//    Term l5("canteen", TermType::CONSTANT);


//    Substitution substitution;
//    substitution.AddBinding(&v1, &c1);
//    substitution.AddBinding(&v2, &c2);
//    substitution.AddBinding(&v3, &c3);
//    substitution.AddBinding(&v4, &c4);

    World world;

    world.Add(Complex(
            Term("LOC", TermType::TERM),
            Term("leia", TermType::CONSTANT),
            Term("deathstar", TermType::CONSTANT)
    ));

    world.Add(Complex(
            Term("LOC", TermType::TERM),
            Term("luke", TermType::CONSTANT),
            Term("desert", TermType::CONSTANT)
    ));

    world.Add(Complex(
            Term("ADJACENT", TermType::TERM),
            Term("moseisley", TermType::CONSTANT),
            Term("desert", TermType::CONSTANT)
    ));

    world.Add(Complex(
            Term("ADJACENT", TermType::TERM),
            Term("desert", TermType::CONSTANT),
            Term("moseisley", TermType::CONSTANT)
    ));

    world.Add(Complex(
            Term("ADJACENT", TermType::TERM),
            Term("moseisley", TermType::CONSTANT),
            Term("cantina", TermType::CONSTANT)
    ));

    world.Add(Complex(
            Term("ADJACENT", TermType::TERM),
            Term("cantina", TermType::CONSTANT),
            Term("moseisley", TermType::CONSTANT)
    ));

    world.Add(Complex(
            Term("LOC", TermType::TERM),
            Term("hans", TermType::CONSTANT),
            Term("cantina", TermType::CONSTANT)
    ));

//    world.Dump();

    std::cout << world << std::endl;

    return 0;
}
