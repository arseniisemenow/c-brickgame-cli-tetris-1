#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_CELL_CELL_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_CELL_CELL_H_

#include <stdbool.h>

typedef struct {
  unsigned char color_;
  bool is_set_;
} Cell;

void InitCell(Cell *p_cell);
void CopyCell(Cell *p_cell_dest, Cell cell_src);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_CELL_CELL_H_
