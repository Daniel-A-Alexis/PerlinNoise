#ifndef BLOCKS_H
#define BLOCKS_H

typedef enum{
    BLOCK_AIR = 0, 
    BLOCK_BOX = 1
}BlockType;

typedef struct{
    BlockType type;
    bool isHidden; 
}Block;

#endif