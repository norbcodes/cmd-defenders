#pragma once

/*
This file contains the AI Node class and functions from node.cpp.
*/

struct Node
{
    char x;
    char y;
    Node* link_next;
    Node* link_prev;

    // Default constructor
    Node() {}

    Node* GetNext() const
    {
        return this->link_next;
    }

    Node* GetPrevious() const
    {
        return this->link_prev;
    }
};