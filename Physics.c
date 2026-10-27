#include <raylib.h>
#include "Camera.h"

#define GRAVITY -9.81f

// VARIABLES
float velocityY = 0.0f;
float gravity = GRAVITY;
bool isFalling = true;
float jumpStrength = 10.0f;

void update_Physics(BoundingBox *box1, BoundingBox *box2)
{
    if (isFalling)
    {
        //GRAVITY
        float deltaTime = GetFrameTime();
        velocityY += GRAVITY * deltaTime;
        camera.position.y += velocityY * deltaTime;
        camera.target.y += velocityY * deltaTime;
        // box1->min.y += velocityY * deltaTime;
        // box1->max.y += velocityY * deltaTime;
    }

    if (!isFalling)
    {
        velocityY = 0.0f;
    }

    //PLAYER COLLISION
    if (CheckCollisionBoxes(*box1, *box2))
    {
        float amount;
        // if (box1->min.x > box2->max.x)
        // {
        //     amount = box1->min.x - box2->max.x;
        //     printf("x cross: %f ", amount);
        // }
        if (box1->min.y < box2->max.y)
        {
            amount = box2->max.y - box1->min.y;
            box1->min.y += amount;
            box1->max.y += amount;
            camera.position.y += amount;
            camera.target.y += amount;
            isFalling = false;
        }
        // if (box1->min.z > box2->max.z)
        // {
        //     amount = box1->min.z - box2->max.z;
        //     printf("z cross: %f\n", amount);
        // }
    }
}