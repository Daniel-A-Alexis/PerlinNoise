#ifndef WORLD_H
#define WORLD_H

#include "Blocks.h"

#define WORLD_SIZE 64
extern BlockType world[WORLD_SIZE][WORLD_SIZE][WORLD_SIZE];

BlockType GetBlock(int x, int y, int z);
void SetBlock(int x, int y, int z, BlockType type);
bool IsSolid(int x, int y, int z);
bool IsBlockHidden(int x, int y, int z);
void initialiseWorld();
void debugWorld();
float PerlinFade(float t);
float PerlinLerp(float a, float b, float t);

#endif