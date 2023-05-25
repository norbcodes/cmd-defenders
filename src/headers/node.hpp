#pragma once

/*
This file contains the AI Node class and functions from node.cpp.
*/

struct Node
{
    char x;
    char y;
    Node* link;

    // Default constructor
    Node() {}

    Node* GetNext()
    {
        return this->link;
    }
};