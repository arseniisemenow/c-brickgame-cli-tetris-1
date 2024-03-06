#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_BLOCK_BLOCK_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_BLOCK_BLOCK_H_
#include "../../common/colors.h"

static const int kBlocksBitmask[][4] = {
    {0b0100010001000100, 0b0000000011110000, 0b0100010001000100,
     0b0000000011110000},  // I
    {0b0000001000100110, 0b0000010001110000, 0b0000001100100010,
     0b0000000001110001},  // J
    {0b0000001000100011, 0b0000000001110100, 0b0000011000100010,
     0b0000000101110000},  // L
    {0b0000011001100000, 0b0000011001100000, 0b0000011001100000,
     0b0000011001100000},  // O
    {0b0000000000110110, 0b0000010001100010, 0b0000000000110110,
     0b0000010001100010},  // S
    {0b0000001001110000, 0b0000001000110010, 0b0000000001110010,
     0b0000001001100010},  // T
    {0b0000000001100011, 0b0000001001100100, 0b0000000001100011,
     0b0000001001100100},  // Z
};

typedef enum {
  kBlockI = 0,
  kBlockJ = 1,
  kBlockL = 2,
  kBlockO = 3,
  kBlockS = 4,
  kBlockT = 5,
  kBlockZ = 6,
} BlockType;

typedef enum {
  kBlockRotationFirst = 0,
  kBlockRotationSecond = 1,
  kBlockRotationThird = 2,
  kBlockRotationForth = 3,
} BlockRotation;

BlockType GetRandomBlockType();
BlockRotation GetNextBlockRotation(BlockRotation block_rotation);
BlockRotation GetPreviousBlockRotation(BlockRotation block_rotation);
BlockColorType GetBlockColor(BlockType block_type);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_BLOCK_BLOCK_H_