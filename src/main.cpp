
#include <iostream>

#include "Terms.h"
#include "Context.h"
#include "Compound.h"
#include "World.h"
#include "Action.h"

// ----------------------------------------------------------------------

int main(int argc, char **argv) {

    {
        std::cout <<
        std::endl << "TEST 1 - simple application of an action on a world" << std::endl;
        std::cout << "===================================================" << std::endl <<
        std::endl;

        World world;
        world.Add(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT)));
        world.Add(Compound(Term("portal", TERM), Term("moseisley", CONSTANT), Term("desert", CONSTANT)));
        world.Add(Compound(Term("portal", TERM), Term("desert", CONSTANT), Term("moseisley", CONSTANT)));
        std::cout << world << std::endl;

        Action action;
        action.NewPrecondition(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT)));
        action.NewAdditiveFact( Compound(Term("location", TERM), Term("luke", CONSTANT), Term("moseisley", CONSTANT)));
        action.NewSubtractiveFact( Compound(Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT)));
        std::cout << action << std::endl;

        action.Apply(world);
        std::cout << world << std::endl;
    }

    {
        std::cout <<
        std::endl << "TEST 2 - evaluate a compound with var over a context" << std::endl;
        std::cout << "====================================================" << std::endl <<
        std::endl;

        Context context1;
        context1.NewBinding(Term("V1", VARIABLE), Term("V3", VARIABLE));
        context1.NewBinding(Term("V2", VARIABLE), Term("luke", CONSTANT));
        context1.NewBinding(Term("V3", VARIABLE), Term("leia", CONSTANT));
        std::cout << context1 << std::endl;

        Term term1 = Term("V1", VARIABLE);
        std::cout << term1 << " is ";
        std::cout << term1.GetActualValue(context1) << std::endl;

        Term term2 = Term("V2", VARIABLE);
        std::cout << term2 << " is ";
        std::cout << term2.GetActualValue(context1) << std::endl;
    }

    {
        std::cout <<
        std::endl << "TEST 3 - compound with a var as query over a world" << std::endl;
        std::cout << "==================================================" << std::endl <<
        std::endl;

        World world;
        world.Add(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT)));
        world.Add(Compound(Term("portal", TERM), Term("moseisley", CONSTANT), Term("desert", CONSTANT)));
        world.Add(Compound(Term("portal", TERM), Term("desert", CONSTANT), Term("moseisley", CONSTANT)));
        std::cout << world << std::endl;

        Compound compound(Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT));
        std::cout << compound << std::endl;

        std::vector<Compound> res;
        res = compound.Query(world);

        for(auto C : res) {
            std::cout << C << std::endl;

        }
    }

    return 0;
}
