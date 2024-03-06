#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_FSM_FSM_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_FSM_FSM_H_

#include "../../../gui/cli/frontend.h"
#include "../backend/backend.h"
#include "../common/defines.h"
#include "callback.h"
#include "fsm_types.h"

SignalType GetSignal(int user_input, bool hold, bool *p_key_held);
void SignalAction(SignalType signal, Parameters *p_parameters);

void ActionSpawn(Parameters *p_parameters);

void ActionMoveUp(Parameters *p_parameters);

void ActionMoveDown(Parameters *p_parameters);

void ActionMoveRight(Parameters *p_parameters);

void ActionMoveLeft(Parameters *p_parameters);

void ActionCollide(Parameters *p_parameters);

void ActionGameOver(Parameters *p_parameters);

void ActionExitState(Parameters *p_parameters);

void ActionPause(Parameters *p_parameters);

bool CheckCollisions(Parameters *p_parameters);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_FSM_FSM_H_