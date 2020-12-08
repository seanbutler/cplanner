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
    :   parentNode(PN)
    ,   action(A)
    {

    }

public:
    Node & parentNode;
    Action & action;
    std::vector<Node&> children;
};

// ----------------------------------------------------------------------

class Planner {

public:
    Planner(World & initialState)
    {
        root.initialState = initialState
    }

    void Initialise(World & initialState) {
        root.world = initialState;
    }

    void BuildTree(Node previousState) {

    }

    Node root;

    World goalState;
    Action possibleActions;
};

// ----------------------------------------------------------------------

#endif //CPLANNER_PLANNER_H
