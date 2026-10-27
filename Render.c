#include "Render.h"
#include "Models.h"
#include "World.h"
#include "Models.h"
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_MIDDLE_X SCREEN_WIDTH/2
#define SCREEN_MIDDLE_Y SCREEN_HEIGHT/2
#define TARGET_FPS 60

void SetupScreen()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Perlin Noise");
    SetTargetFPS(TARGET_FPS);
    DisableCursor();
}

void DrawWorld()
{
    for (int x = 0; x < WORLD_SIZE; x++)
    {
        for (int y = 0; y < WORLD_SIZE; y++)
        {
            for (int z = 0; z < WORLD_SIZE; z++)
            {
                if (!IsSolid(x, y, z))
                    continue;

                if (IsBlockHidden(x, y, z))
                    continue;

                switch (world[x][y][z])
                {
                case BLOCK_BOX:
                    DrawModel(box, (Vector3){x, y, z}, 0.5f, WHITE);
                    break;
                }
            }
        }
    }
}