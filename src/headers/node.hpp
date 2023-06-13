#pragma once

/*
This file contains the AI Node class and functions from node.cpp.
*/

struct Node
{
    unsigned int x;
    unsigned int y;
    Node* link_next;
    Node* link_prev;

    // Default constructor
    Node() : x(-1), y(-1)
    {}

    Node(unsigned int x, unsigned int y) : x(x), y(y)
    {}

    Node* GetNext() const
    {
        return this->link_next;
    }

    Node* GetPrevious() const
    {
        return this->link_prev;
    }
};