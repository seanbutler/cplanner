
#include <iostream>

#include "Terms.h"
#include "Context.h"
#include "Compound.h"
#include "World.h"
#include "Action.h"

// ----------------------------------------------------------------------

int main(int argc, char **argv) {

    World world;
    world.Add(Compound(Term("location", TERM), Term("luke", CONSTANT), Term("desert", CONSTANT)));
    world.Add(Compound(Term("location", TERM), Term("hans", CONSTANT), Term("moseisley", CONSTANT)));
    world.Add(Compound(Term("portal", TERM), Term("moseisley", CONSTANT), Term("desert", CONSTANT)));
    world.Add(Compound(Term("portal", TERM), Term("desert", CONSTANT), Term("moseisley", CONSTANT)));
    std::cout << "World... " << std::endl;
    std::cout << world << std::endl;

    Action action;
    action.NewPrecondition( Compound(Term("location", TERM), Term("X", VARIABLE), Term("P1", VARIABLE) ) );
    action.NewPrecondition( Compound(Term("portal", TERM), Term("P1", VARIABLE), Term("P2", VARIABLE)) );
    action.NewAdditiveFact( Compound(Term("location", TERM), Term("X", VARIABLE), Term("P2", VARIABLE)) );
    action.NewSubtractiveFact( Compound(Term("location", TERM), Term("X", VARIABLE), Term("P1", VARIABLE)) );
    std::cout << "Action... " << std::endl;
    std::cout << action << std::endl;

    World scratchWorld;
    World result;
    Context tmpContext;

    // iterate over all the preconditions of the current action
    for ( auto currentPreCondition : action.preconditionList ) {
        std::cout << currentPreCondition << std::endl;

        // iterate over all the facts in the world
        for ( auto currentWorldFact : world.facts ) {

            // first terms (the function term) match type and value, so proceed with the rest of the test
            if ( currentWorldFact.terms[0] == currentPreCondition.terms[0] ) {

                unsigned int i = 0;
                for ( int i =0; i< currentPreCondition.terms.size(); i++) {

                    if (currentWorldFact.terms[i].type == CONSTANT) {
                        if (currentPreCondition.terms[i].type == VARIABLE) {
                            tmpContext.NewBinding(currentPreCondition.terms[i], currentWorldFact.terms[i]);

//                            scratchWorld.Add(Compound(currentWorldFact.terms[0],
//                                                      currentPreCondition.terms[i].Reify(tmpContext),
//                                                      currentWorldFact.terms[i].Reify(tmpContext)));

                        }
                    }
                }
            }
        }
    }


    std::cout << "tmpContext " << std::endl << tmpContext << std::endl;
    std::cout << "scratchworld " << std::endl << scratchWorld << std::endl;


//        for (auto T : compound.terms) {
//            if ( T.type == VARIABLE ) {
//                for (unsigned int j = 0;
//                         filteredWorld.facts[j].terms.size();
//                         j++)
//                {
//
//
//                }
//            }
//        }
//    }

//    std::cout << testCompound << " - " << filteredWorld << std::endl;


    Context context;

//        for (auto rcompound : results) {
//            std::cout << " ** " << rcompound << std::endl;
//
//            for ( unsigned int pcount=0;pcount<action.preconditionList.size(); pcount++) {
//
//                for ( unsigned int rcount=0; rcount < results.size(); rcount++) {
//                    std::cout << " RESULT - " << results[rcount] << std::endl;
//
//                    for ( unsigned int tcount = 0; tcount < results[rcount].terms.size(); tcount++ ) {
//                        std::cout << " RES - " << results[rcount].terms[tcount] << std::endl;
//                        std::cout << " QRY - " << action.preconditionList[0].terms[tcount] << std::endl;
//
//                        if ( ( rcompound.terms[tcount].type == CONSTANT ) &&
//                             ( action.preconditionList[0].terms[tcount].type == VARIABLE ) ) {
//                            context.NewBinding(action.preconditionList[0].terms[tcount],rcompound.terms[tcount]);
//                        }
//                    }
//                }
//            }
//        }

//    std::cout << context;

    return 0;
}
