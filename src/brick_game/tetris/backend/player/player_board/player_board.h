#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_PLAYER_PLAYER_BOARD_PLAYER_BOARD_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_PLAYER_PLAYER_BOARD_PLAYER_BOARD_H_

#include "../../../common/color_handler.h"
#include "../../block/block.h"
#include "../../cell/cell.h"

#define PLAYER_BOARD_SIZE (4)

typedef struct {
  Cell board_[PLAYER_BOARD_SIZE][PLAYER_BOARD_SIZE];
} PlayerBoard;

void InitPlayerBoard(PlayerBoard *p_player_board);
void CopyPlayerBoard(PlayerBoard *p_player_board_dest,
                     PlayerBoard player_board_src);

void SetPlayerBoardBlock(PlayerBoard *p_player_board, BlockType block_type,
                         BlockRotation block_rotation);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_PLAYER_PLAYER_BOARD_PLAYER_BOARD_H_
