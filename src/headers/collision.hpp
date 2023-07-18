#pragma once

// E -> Enemy
#define E_HITBOX_W      1.5f
#define E_HITBOX_H      1.5f

// P -> Projectile
#define P_HITBOX_W      1.5f
#define P_HITBOX_H      1.5f

// L -> Landmine
#define L_HITBOX_W      0.95f
#define L_HITBOX_H      0.95f

// LE -> Landmine Explosion
#define LE_HITBOX_W     3.75f
#define LE_HITBOX_H     3.75f

// S -> Spiky Rock
#define S_HITBOX_W      1.5f
#define S_HITBOX_H      1.5f

struct BoundingBox
{
    float width;
    float height;

    BoundingBox() : width(0.0f), height(0.0f) {}

    BoundingBox(float width, float height) : width(width), height(height) {}
};