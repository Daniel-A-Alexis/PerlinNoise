#ifndef PHYSICS_H
#define PHYSICS_H

extern float velocityY;
extern float gravity;
extern bool isFalling;
extern float jumpStrength;

void update_Physics(BoundingBox *box1, BoundingBox *box2);

#endif