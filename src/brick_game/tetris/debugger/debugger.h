#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_DEBUGGER_DEBUGGER_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_DEBUGGER_DEBUGGER_H_

#include "../backend/parameters/parameters.h"
#include "../backend/player/player.h"
#include "../fsm/callback.h"
#include "../fsm/fsm_types.h"

void SignalInfoDebug(SignalType signal);

void ParamsInfoDebug(Parameters parameters);

void PlayerPositionInfoDebug(Player player_info);

void ActionInfoDebug(action_callback callback);

char* GetBlockTypeString(BlockType block_type);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_DEBUGGER_DEBUGGER_H_