#pragma once

/*
This file contains the AI Node class and functions from node.cpp.
*/

struct Node
{
    char x;
    char y;
    Node* link;

    Node(char X, char Y, Node* next_node)
    {
        this->x = X;
        this->y = Y;
        this->link = next_node;
    }

    Node* GetNext()
    {
        return this->link;
    }
};