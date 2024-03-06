#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_PARAMETERS_PARAMETERS_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_PARAMETERS_PARAMETERS_H_

#include <utime.h>

#include "../../fsm/fsm_types.h"
#include "../board/board.h"
#include "../game_status/game_status.h"
#include "../player/player.h"
#include "../records/records.h"

typedef struct {
  GameStatus *game_status_;
  PlayerState *player_state_;
  Board *board_;
  Player *player_;
  Player *next_player_;
  Player *predict_player_;
  Records *records_;
  long long *last_moved_time_;
} Parameters;

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_PARAMETERS_PARAMETERS_H_
