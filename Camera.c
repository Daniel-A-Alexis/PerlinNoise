#include <raylib.h>

#include "Camera.h"
#include "Models.h"
#include "Physics.h"

int cameraMode = CAMERA_FREE;

Camera3D camera = {
    .position = {10.0f, 20.0f, 10.0f},
    .target = {0.0f, 0.0f, 0.0f},
    .up = {0.0f, 1.0f, 0.0f},
    .fovy = 45.0f,
    .projection = CAMERA_PERSPECTIVE
};

void UpdateCameraBound()
{
    if (cameraMode != CAMERA_FREE)
    {
        update_Physics(&playerCol, &floorCol);
    }

    playerCol.min = (Vector3){
        camera.position.x - 1.0f,
        camera.position.y - 1.0f,
        camera.position.z - 1.0f,
    };

    playerCol.max = (Vector3){
        camera.position.x + 1.0f,
        camera.position.y + 1.0f,
        camera.position.z + 1.0f,
    };
}