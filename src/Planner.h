//
// Created by sean on 06/12/2020.
//

#ifndef CPLANNER_PLANNER_H
#define CPLANNER_PLANNER_H

// ----------------------------------------------------------------------

#include "World.h"
#include "Action.h"

// ----------------------------------------------------------------------

class Node {

public:
    Node (Node PN, Action A)
//    :   parentNode(PN)
//    ,   action(A)
    {

    }

public:
//    Node & parentNode;
//    std::vector<Node&> children;
};

// ----------------------------------------------------------------------

class Planner {

public:
    Planner(World & initialState, World & goalState)
    {
    }

    void BuildTree(Node previousState) {
    }

    World initialState;
    Action possibleActions;
};

// ----------------------------------------------------------------------

#endif // CPLANNER_PLANNER_H
