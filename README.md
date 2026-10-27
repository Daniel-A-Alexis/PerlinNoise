# PerlinNoise
Contains an implementation of the Perlin Noise function

Perlin noise implementation is within World.c:
- **void initialiseWorld()** // Implements perlin noise
- **float PerlinLerp()** // Used for linear interpolation between 2 points during Perlin calculation
- **float PerlinFade()** // Used to smoothen interpolation and stop harsh changes on the edges

Notes:
- You can change the WORLD_SIZE definition within **World.h** to see it cover a larger landscape but due to poor optimisation it'll probably lag, so I've left it at a 64x64x64 world size
- I was messing with a few different ideas here so this project will have some extra unused code in places!

Usage:
1. Download the repo
2. Use Main.exe to open
