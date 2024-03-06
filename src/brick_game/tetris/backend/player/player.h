#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_PLAYER_PLAYER_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_PLAYER_PLAYER_H_

#include "../block/block.h"
#include "player_board/player_board.h"

#define INIT_PLAYER_POS_X (3)
#define INIT_PLAYER_POS_Y (0)

#define INIT_NEXT_PLAYER_POS_X (16)
#define INIT_NEXT_PLAYER_POS_Y (1)

typedef struct {
  int x_;
  int y_;
  BlockType block_type_;
  BlockRotation block_rotation_;
  PlayerBoard board_;
} Player;

void InitPlayer(Player *p_player);
void InitNextPlayer(Player *p_player);
void CopyPlayer(Player *p_player_dest, Player player_src);
void InitPlayerPosition(Player *p_player);
void SetPlayerBlockType(Player *p_player, BlockType block_type);
void SetPlayerBlockRotation(Player *p_player, BlockRotation block_rotation);
void SetPlayerNextBlockRotation(Player *p_player);
void SetPlayerPreviousBlockRotation(Player *p_player);
void UpdatePlayerBoard(Player *p_player);
void SetNextPlayerColor(Player *p_player);

void MovePlayerByDXDY(Player *p_player, int d_x, int d_y);
void MovePlayerUp(Player *p_player);
void MovePlayerDown(Player *p_player);
void MovePlayerLeft(Player *p_player);
void MovePlayerRight(Player *p_player);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_PLAYER_PLAYER_H_
