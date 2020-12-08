
#include <iostream>

#include "Terms.h"
#include "Substitution.h"
#include "Compound.h"
#include "World.h"
#include "Action.h"

// ----------------------------------------------------------------------

int main(int argc, char **argv) {

    World world;

//    world.Add(Compound(
//            Term("LOC", TermType::TERM),
//            Term("leia", TermType::CONSTANT),
//            Term("deathstar", TermType::CONSTANT)
//    ));

    world.Add(Compound(
            Term("LOC", TermType::TERM),
            Term("luke", TermType::CONSTANT),
            Term("desert", TermType::CONSTANT)
    ));

    world.Add(Compound(
            Term("PORT", TermType::TERM),
            Term("moseisley", TermType::CONSTANT),
            Term("desert", TermType::CONSTANT)
    ));

    world.Add(Compound(
            Term("PORT", TermType::TERM),
            Term("desert", TermType::CONSTANT),
            Term("moseisley", TermType::CONSTANT)
    ));

//    world.Add(Compound(
//            Term("PORT", TermType::TERM),
//            Term("moseisley", TermType::CONSTANT),
//            Term("cantina", TermType::CONSTANT)
//    ));

//    world.Add(Compound(
//            Term("PORT", TermType::TERM),
//            Term("cantina", TermType::CONSTANT),
//            Term("moseisley", TermType::CONSTANT)
//    ));

//    world.Add(Compound(
//            Term("LOC", TermType::TERM),
//            Term("hans", TermType::CONSTANT),
//            Term("cantina", TermType::CONSTANT)
//    ));

    std::cout << world << std::endl;

    Action action;
    action.NewPrecondition(Compound( Term("LOC", TermType::TERM),
                                    Term("luke", TermType::CONSTANT),
                                    Term("P1", TermType::VARIABLE)));

    action.NewPrecondition(Compound( Term("PORT", TermType::TERM),
                                     Term("P1", TermType::CONSTANT),
                                     Term("P2", TermType::VARIABLE)));

    action.NewAdditiveFact(Compound(Term("LOC", TermType::TERM),
                                    Term("luke", TermType::CONSTANT),
                                    Term("P2", TermType::VARIABLE)));

    action.NewSubtractiveFact(Compound(Term("LOC", TermType::TERM),
                                    Term("luke", TermType::CONSTANT),
                                    Term("P1", TermType::VARIABLE)));

    std::cout << action << std::endl;

    action.Apply(world);

    std::cout << world << std::endl;

    return 0;
}
