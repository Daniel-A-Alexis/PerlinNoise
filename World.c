#include <stdio.h>
#include "World.h"
#include <raylib.h>
#include <math.h>
#include <stdlib.h>
#include <raymath.h>

BlockType world[WORLD_SIZE][WORLD_SIZE][WORLD_SIZE];

int SaveWorldToFile()
{
    FILE *file;
    size_t worldSize = sizeof(world) / sizeof(world[0][0][0]);

    file = fopen("World.dat", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fwrite(world, sizeof(int), worldSize, file);
    return 0;
}

void LoadWorldFromFile()
{
    //FILE *file = fread()
}

BlockType GetBlock(int x, int y, int z)
{
    return world[x][y][z];
}

void SetBlock(int x, int y, int z, BlockType type)
{
    world[x][y][z] = type;
}

bool IsSolid(int x, int y, int z)
{
    if (x < 0 || x >= WORLD_SIZE ||
        y < 0 || y >= WORLD_SIZE ||
        z < 0 || z >= WORLD_SIZE )
    {
        return false;
    }

    return world[x][y][z] != BLOCK_AIR;
}

bool IsBlockHidden(int x, int y, int z)
{
    return IsSolid(x + 1, y, z) &&
           IsSolid(x - 1, y, z) &&
           IsSolid(x, y + 1, z) &&
           IsSolid(x, y - 1, z) &&
           IsSolid(x, y, z + 1) &&
           IsSolid(x, y, z - 1);
}

float PerlinFade(float t)
{
    return 6*t*t*t*t*t - 15*t*t*t*t + 10*t*t*t;
}

float PerlinLerp(float a, float b, float t)
{
    return a + (b - a) * t;
}

void initialiseWorld() // PERLIN FUNCTION
{
    srand(12345); // SEED

    // Perlin Variables
    int perlinReso = 3;
    float perlinX, perlinZ;
    int perlinGrid[perlinReso][perlinReso];
    Vector2 perlinVectors[4] = {
        { 0.7071f,  0.7071f},
        {-0.7071f, -0.7071f},
        {-0.7071f,  0.7071f},
        { 0.7071f, -0.7071f}
    };

    // World variables
    
    // Assign random verticies to perlinGrid
    for (int x = 0; x < perlinReso; x++)
    {
        for (int y = 0; y < perlinReso; y++)
        {
            perlinGrid[x][y] = rand() % 4;
        }
    }

    //Perform perlinNoise using perlinGrid mapped to worldGrid
    for (int x = 0; x <= WORLD_SIZE-1; x++)
    {
        for (int z = 0; z <= WORLD_SIZE-1; z++)
        {
            // Map world position to perlin position
            perlinX = (float)x / (WORLD_SIZE-1) * (perlinReso - 1);
            perlinZ = (float)z / (WORLD_SIZE-1) * (perlinReso - 1);


            // Find the correct 4 vector points to focus on
            int VecX0 = (int)floorf(perlinX);
            int VecZ0 = (int)floorf(perlinZ);

            if (VecX0 >= perlinReso-1)
                VecX0 = perlinReso-2;

            if (VecZ0 >= perlinReso-1)
                VecZ0 = perlinReso-2;

            int VecX1 = VecX0 + 1;
            int VecZ1 = VecZ0 + 1;


            //Find where within the 4 points we are currently looking at
            float tx = perlinX - VecX0;
            float tz = perlinZ - VecZ0;


            // Assign 4 vectors, using the current 4 points that are focused on
            Vector2 g00 = perlinVectors[perlinGrid[VecX0][VecZ0]];
            Vector2 g10 = perlinVectors[perlinGrid[VecX1][VecZ0]];
            Vector2 g01 = perlinVectors[perlinGrid[VecX0][VecZ1]];
            Vector2 g11 = perlinVectors[perlinGrid[VecX1][VecZ1]];


            // Calulate displacement vectors
            Vector2 d00 = {tx,          tz};
            Vector2 d10 = {tx - 1.0f,   tz};
            Vector2 d01 = {tx,          tz - 1.0f};
            Vector2 d11 = {tx - 1.0f,   tz - 1.0f};

            // Calculate dot products
            float n00 = Vector2DotProduct(g00, d00);
            float n10 = Vector2DotProduct(g10, d10);
            float n01 = Vector2DotProduct(g01, d01);
            float n11 = Vector2DotProduct(g11, d11);

            // Smoothen transitions
            float u = PerlinFade(tx);
            float v = PerlinFade(tz);

            // Interpolate horizontally
            float top = PerlinLerp(n00, n10, u);
            float bottom = PerlinLerp(n01, n11, u);

            // Interpolate vertically
            float noise = PerlinLerp(top, bottom, v);

            int height = (int)floorf(8.0f + noise * 15.0f);

            for (int y = 0; y < WORLD_SIZE; y++)
            {
                if (y <= height)
                    world[x][y][z] = BLOCK_BOX;
                else
                    world[x][y][z] = BLOCK_AIR;
            }
        }
    }

    
}



void debugWorld()
{
    for (int x = 0; x < WORLD_SIZE; x++)
    {
        for (int y = 0; y < WORLD_SIZE; y++)
        {
            for (int z = 0; z < WORLD_SIZE; z++)
            {
                printf("%d", world[x][y][z]);
            }   
        }
    }
}