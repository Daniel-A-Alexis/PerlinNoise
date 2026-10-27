#include <raylib.h>
#include <raymath.h>

#include "Inputs.h"
#include "Camera.h"
#include "Physics.h"

void update_KeyInputs()
{

    if (IsKeyPressed(KEY_ESCAPE))
    {
        CloseWindow();
    }

    if (IsKeyPressed(KEY_F1))
    {
        cameraMode = (cameraMode == CAMERA_FIRST_PERSON) ? CAMERA_THIRD_PERSON : CAMERA_FIRST_PERSON;

        if (cameraMode == CAMERA_THIRD_PERSON)
        {
            Vector3 direction = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
            
            camera.position = Vector3Subtract(camera.position, Vector3Scale(direction, 5.0f));
        }
    }

    if (IsKeyPressed(KEY_F2))
    {
        cameraMode = CAMERA_FREE;
    }

    if (IsKeyPressed(KEY_SPACE) && !isFalling)
    {
        velocityY = jumpStrength;
        isFalling = true;
    }
}