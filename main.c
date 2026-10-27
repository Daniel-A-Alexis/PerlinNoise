#include <stdio.h>
#include <raylib.h>
#include <math.h>
#include <time.h>
#include <raymath.h>

#include "world.h"
#include "Blocks.h"
#include "Render.h"
#include "Models.h"
#include "Camera.h"
#include "Player.h"
#include "Physics.h"
#include "Inputs.h"

int main ()
{
    SetupScreen();

    LoadModels();
    initialiseWorld();

    // GAME LOOP
    while (!WindowShouldClose())
    {
        update_KeyInputs();

        UpdateCamera(&camera, cameraMode);
        UpdateCameraBound();
 
        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);

        DrawWorld();

        EndMode3D();

        EndDrawing();
    }
}