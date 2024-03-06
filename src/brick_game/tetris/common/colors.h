#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_COMMON_COLORS_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_COMMON_COLORS_H_

#ifndef COLOR_BLACK
#define COLOR_BLACK (0)
#endif  // COLOR_BLACK

typedef enum {
  kBlockColorI = 0,
  kBlockColorJ = 1,
  kBlockColorL = 2,
  kBlockColorO = 3,
  kBlockColorS = 4,
  kBlockColorT = 5,
  kBlockColorZ = 6,
  kBlockColorPredict = 7,
} BlockColorType;

/** Set colors for corresponding block type.
 * Setting by index
 **/
static const BlockColorType kBlockColors[] = {0, 1, 2, 3, 4, 5, 6, 7};

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_COMMON_COLORS_H_
