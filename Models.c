#include "Models.h"
#include <raylib.h>
#include <stdio.h>

Model box;
BoundingBox floorCol;
BoundingBox playerCol;

Model rock;
BoundingBox rockCol;
Model floorModel;

void LoadModels()
{
    box = LoadModel("Models/Block_Grass.glb");
    if (!IsModelValid(box))
    {
        printf("Failed to load model!\n");
    }

    rock = LoadModel("Models/Rock1.glb");
    if (!IsModelValid(rock))
    {
        printf("Failed to load model!\n");
    }
    rockCol = GetModelBoundingBox(rock);

    floorModel = LoadModel("Models/Floor_Wooden.glb");
    if (!IsModelValid(floorModel))
    {
        printf("Failed to load model!\n");
    }
    floorCol = GetModelBoundingBox(floorModel);

    playerCol.min = (Vector3){9.5f, 9.5f, 9.5f};
    playerCol.max = (Vector3){10.5f, 10.5f, 10.5f};
}

