#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_BOARD_BOARD_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_BOARD_BOARD_H_

#include "../../common/defines.h"
#include "../cell/cell.h"

typedef enum {
  kBoardSideUp = 0,
  kBoardSideDown = 1,
  kBoardSideLeft = 2,
  kBoardSideRight = 3,
} BoardSide;

typedef struct {
  int height_;
  int width_;
  Cell cells_[BOARD_HEIGHT][BOARD_WIDTH];
} Board;

void InitBoard(Board *p_board);
int HandleBoardCompleteLines(Board *p_board);
void RemoveBoardLine(Board *p_board, int line_index);
void ApplyPhysics(Board *p_board);
void ShiftBoardDown(Board *p_board, int empty_row_index);
void CopyBoardLine(Board *p_board, int index_dest, int index_src);
bool CheckBoardCompleteLine(Board *p_board, int row_index);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_BOARD_BOARD_H_
