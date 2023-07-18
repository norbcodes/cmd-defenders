#include "headers/collision.hpp"
#include "headers/entity.hpp"
#include "headers/projectile.hpp"

/*
Detect collisions!

There are 3 types:
Projectile on Enemy collision
Enemy on Landmine (yes those will be added)
Enemy on Spiky Rock (A special tower that can deals damage to enemies walking on top of it.)
*/

struct nCoord
{
    float x, y;  // This is just to make my life easier
};
// Do not use elsewhere.

bool IsColliding(const Projectile& projectile, const Enemy& enemy)
{
    // So basically
    // We check each 4 corner peices and check if they are inside the bounding box of the enemy.
    // Easy enough

    const nCoord TopLeft        = { projectile.x,                        projectile.y                         };
    const nCoord TopRight       = { projectile.x + projectile.Box.width, projectile.y                         };
    const nCoord BottomLeft     = { projectile.x,                        projectile.y + projectile.Box.height };
    const nCoord BottomRight    = { projectile.x + projectile.Box.width, projectile.y + projectile.Box.height };

    // Cuttin' corners? HAHA no pun intended
    if (TopLeft.x > (enemy.x + enemy.Box.width))
    {
        // This is only if the top left corner x value is higher than the enemies
        // So basically we ain't collidin'
        return false;
    }

    const nCoord Corners[4] = {TopLeft, TopRight, BottomLeft, BottomRight};

    for (int i = 0; i != 4; i++)
    {
        if (Corners[i].x >= enemy.x && Corners[i].x <= (enemy.x + enemy.Box.width))
        {
            // x checks out
            if (Corners[i].y >= enemy.y && Corners[i].y <= (enemy.y + enemy.Box.height))
            {
                // y checks out, we are collidin' alright!
                return true;
            }
        }
    }
    // This loop only exists so that I don't have to write out all the if blocks
    // I'm lazy.

    return false;
}