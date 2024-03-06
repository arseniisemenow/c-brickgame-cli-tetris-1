#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_COLLISIONS_CHECKER_COLLISIONS_CHECKER_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_COLLISIONS_CHECKER_COLLISIONS_CHECKER_H_

#include "../board/board.h"
#include "../parameters/parameters.h"
#include "../player/player.h"

bool PerformCollideCheckWithSide(Board *p_board, BoardSide board_side, int x,
                                 int y);
bool CheckCollideWithSide(Player *p_player, Board *p_board,
                          BoardSide board_side);
bool CheckCollideWithUp(Player *p_player, Board *p_board);
bool CheckCollideWithDown(Player *p_player, Board *p_board);
bool CheckCollideWithLeft(Player *p_player, Board *p_board);
bool CheckCollideWithRight(Player *p_player, Board *p_board);
bool CheckCollide(Player *p_player, Board *p_board);

bool PerformFutureCollideCheckWithSide(Board *p_board, BoardSide board_side,
                                       int x, int y);
bool CheckFutureCollideWithSide(Player *p_player, Board *p_board,
                                BoardSide board_side);
bool CheckFutureCollideWithUp(Player *p_player, Board *p_board);
bool CheckFutureCollideWithDown(Player *p_player, Board *p_board);
bool CheckFutureCollideWithLeft(Player *p_player, Board *p_board);
bool CheckFutureCollideWithRight(Player *p_player, Board *p_board);

bool CheckCollideWithBlocks(Player *p_player, Board *p_board);

bool CheckFutureCollideWithBlocksLeft(Player *p_player, Board *p_board);
bool CheckFutureCollideWithBlocksRight(Player *p_player, Board *p_board);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_COLLISIONS_CHECKER_COLLISIONS_CHECKER_H_
