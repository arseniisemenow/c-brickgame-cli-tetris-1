#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_BACKEND_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_BACKEND_H_

#include <string.h>

#include "../time_handler/time_handler.h"
#include "block/block.h"
#include "board/board.h"
#include "cell/cell.h"
#include "collisions_checker/collisions_checker.h"
#include "game_status/game_status.h"
#include "parameters/parameters.h"
#include "player/player.h"
#include "records/records.h"

#define MAX_LEVEL_COUNT (10)

static const long long kArrayOfTimeStep[11] = {1000, 875, 625, 550, 425, 350,
                                               325,  300, 250, 200, 150};

void BoardOverlayBlock(Player *p_player, Board *p_board);
void MovePredictPlayerDown(Player *p_player, Board *p_board);
void UpdatePredictPlayer(Player *p_player_dest, Player player_src,
                         Board *p_board);
long long int GetTimeStepMS(GameStatus *p_game_status);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_BACKEND_H_