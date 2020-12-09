
#include <iostream>

#include "Terms.h"
#include "Context.h"
#include "Compound.h"
#include "World.h"
#include "Action.h"

// ----------------------------------------------------------------------

int main(int argc, char **argv) {

    std::cout <<
    std::endl << "TEST 1 - simple application of a rule on a world" << std::endl;
    std::cout << "================================================" << std::endl <<
    std::endl;

    World testworld1;
    testworld1.Add(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT) ) );
    testworld1.Add(Compound(Term("portal", TERM), Term("moseisley", CONSTANT), Term("desert", CONSTANT) ) );
    testworld1.Add(Compound(Term("portal", TERM), Term("desert", CONSTANT), Term("moseisley", CONSTANT) ) );
    std::cout << testworld1 << std::endl;

    Action testaction1;
    testaction1.NewPrecondition(Compound( Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT) ) );
    testaction1.NewAdditiveFact(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("moseisley", CONSTANT) ) );
    testaction1.NewSubtractiveFact(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT) ) );
    std::cout << testaction1 << std::endl;

    testaction1.Apply(testworld1);
    std::cout << testworld1 << std::endl;

    std::cout <<
    std::endl << "TEST 2 - evaluate a compound with var over a context" << std::endl;
    std::cout << "================================================" << std::endl <<
    std::endl;

    World world2;
    world2.Add(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT) ) );
    world2.Add(Compound(Term("portal", TERM), Term("moseisley", CONSTANT), Term("desert", CONSTANT) ) );
    world2.Add(Compound(Term("portal", TERM), Term("desert", CONSTANT), Term("moseisley", CONSTANT) ) );
    std::cout << world2 << std::endl;

    Action action2;
    action2.NewPrecondition(Compound( Term("location", TERM), Term("luke", CONSTANT), Term("P1", VARIABLE) ) );
    action2.NewPrecondition(Compound( Term("portal", TERM), Term("P1", VARIABLE), Term("P2", VARIABLE) ) );
    action2.NewAdditiveFact(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("P2", VARIABLE) ) );
    action2.NewSubtractiveFact(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("P1", CONSTANT) ) );
    std::cout << action2 << std::endl;

    Context context2;
    context2.NewBinding(Term("V1", VARIABLE), Term("V3", VARIABLE));
    context2.NewBinding(Term("V2", VARIABLE), Term("luke", CONSTANT));
    context2.NewBinding(Term("V3", VARIABLE), Term("leia", CONSTANT));
    std::cout << context2 << std::endl;

    Term term1 = Term("V1", VARIABLE);
    std::cout << term1  << " is ";
    std::cout << term1.GetActualValue(context2) << std::endl;

    Term term2 = Term("V2", VARIABLE);
    std::cout << term2  << " is ";
    std::cout << term2.GetActualValue(context2) << std::endl;

    return 0;
}
