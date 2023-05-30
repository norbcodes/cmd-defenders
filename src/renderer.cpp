#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "headers/world.hpp"

static std::string RendererCache[MAP_W * MAP_H];
// This is the first image that gets rendered, and it's only the path.
// Then we draw decorations, towers, enemies over it.

struct NodeInfo
{
    char x;
    char y;
    // Up | Down | Right | Left
    bool LinkDirs[4] = {0, 0, 0, 0};
};

void GenerateCache(WorldClass* world)
{
    // Generate the RendererCache.

    std::vector<NodeInfo> NodeInfos;
    std::vector<int> NodeCoords;
    NodeInfos.reserve(255); NodeCoords.reserve(255);
    // Do stuff
    for (std::vector<Node>::iterator node = world->Ai_Nodes.begin(); node != world->Ai_Nodes.end(); ++node)
    {
        bool modify_existing = false;
        NodeInfo* node_to_modify = nullptr;

        // Does this Node already have a NodeInfo?
        if (std::find(NodeCoords.begin(), NodeCoords.end(), (node->x + (node->y * MAP_W))) != NodeCoords.end())
        {
            // If yes, take its pointer
            for (int index = 0; index != NodeInfos.size(); ++index)
            {
                if (NodeInfos[index].x == node->x && NodeInfos[index].y == node->y)
                {
                    modify_existing = true;
                    node_to_modify = &(NodeInfos[index]);
                    break;
                }
            }
        }

        // If we are modifying an existing NodeInfo object.
        if (modify_existing)
        {
            // What direction?
            if (node_to_modify->x == node->GetNext()->x && node_to_modify->y != node->GetNext()->y)
            {
                switch ((node_to_modify->y - node->GetNext()->y) < 0)
                {
                    case true:  // The selected node is below our node
                        node_to_modify->LinkDirs[1] = true;
                        continue;
                    case false:  // The selected node is above our node
                        node_to_modify->LinkDirs[0] = true;
                        continue;
                }
            }

            if (node_to_modify->x != node->GetNext()->x && node_to_modify->y == node->GetNext()->y)
            {
                switch ((node_to_modify->x - node->GetNext()->x) < 0)
                {
                    case true:  // The selected node is on the right of our node
                        node_to_modify->LinkDirs[2] = true;
                        continue;
                    case false:  // The selected node is on the left of our node
                        node_to_modify->LinkDirs[3] = true;
                        continue;
                }
            }
        }

        // Inserting a new NodeInfo.
        NodeInfo new_node;
        new_node.x = node->x; 
        new_node.y = node->y;

        if (new_node.x == node->GetNext()->x && new_node.y != node->GetNext()->y)
            {
                switch ((new_node.y - node->GetNext()->y) < 0)
                {
                    case true:  // The selected node is below our node
                        new_node.LinkDirs[1] = true;
                        continue;
                    case false:  // The selected node is above our node
                        new_node.LinkDirs[0] = true;
                        continue;
                }
            }

            if (new_node.x != node->GetNext()->x && new_node.y == node->GetNext()->y)
            {
                switch ((new_node.x - node->GetNext()->x) < 0)
                {
                    case true:  // The selected node is on the right of our node
                        new_node.LinkDirs[2] = true;
                        continue;
                    case false:  // The selected node is on the left of our node
                        new_node.LinkDirs[3] = true;
                        continue;
                }
            }

        NodeInfos.emplace_back(new_node);
    }
}