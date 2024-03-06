#include <time.h>

#include "fsm.h"

action_callback fsm_table[7][8] = {
    {NULL, NULL, NULL, NULL, NULL, ActionExitState, ActionSpawn, NULL},
    {ActionSpawn, ActionSpawn, ActionSpawn, ActionSpawn, ActionSpawn,
     ActionSpawn, ActionSpawn, NULL},
    {NULL, ActionMoveUp, ActionMoveDown, ActionMoveLeft, ActionMoveRight,
     ActionExitState, NULL, ActionPause},
    {ActionCollide, ActionCollide, ActionCollide, ActionCollide, ActionCollide,
     ActionCollide, ActionCollide, ActionCollide},
    {ActionGameOver, ActionGameOver, ActionGameOver, ActionGameOver,
     ActionGameOver, ActionGameOver, ActionSpawn, ActionCollide},
    {ActionExitState, ActionExitState, ActionExitState, ActionExitState,
     ActionExitState, ActionExitState, ActionExitState, ActionExitState},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, ActionPause},
};

void SignalAction(SignalType signal, Parameters *p_parameters) {
  action_callback act = fsm_table[*p_parameters->player_state_][signal];

  if (act) {
    act(p_parameters);
  }
  bool flag_print_game = (*p_parameters->player_state_ != (kStart));
  flag_print_game &= (*p_parameters->player_state_ != (kPause));
  if (flag_print_game) {
    PrintGame(p_parameters);
  }

  long long time_in_ms = GetTimeInMS();

  if (*p_parameters->player_state_ == kMoving) {
    long long time_step = GetTimeStepMS(p_parameters->game_status_);
    if (time_in_ms - *p_parameters->last_moved_time_ > time_step) {
      *p_parameters->last_moved_time_ = time_in_ms;
      ActionMoveDown(p_parameters);
    }
  }
}

SignalType GetSignal(int user_input, bool hold, bool *p_key_held) {
  SignalType signal = kSignalNone;
  if (hold) {
    *p_key_held = true;
  } else {
    if (user_input == KEY_UP) {
      signal = kSignalMoveUp;
    } else if (user_input == KEY_DOWN) {
      signal = kSignalMoveDown;
    } else if (user_input == KEY_LEFT) {
      signal = kSignalMoveLeft;
    } else if (user_input == KEY_RIGHT) {
      signal = kSignalMoveRight;
    } else if (user_input == ESCAPE) {
      signal = kSignalEscapeButton;
    } else if (user_input == ENTER_KEY) {
      signal = kSignalEnterButton;
    } else if (user_input == PAUSE_KEY) {
      signal = kSignalPauseButton;
    }
    *p_key_held = false;
  }

  return signal;
}

bool CheckCollisions(Parameters *p_parameters) {
  bool flag = false;

  if (CheckFutureCollideWithDown(p_parameters->player_, p_parameters->board_)) {
    *p_parameters->player_state_ = kCollide;
    flag = true;
  } else if (CheckCollideWithBlocks(p_parameters->player_,
                                    p_parameters->board_)) {
    *p_parameters->player_state_ = kCollide;
    flag = true;
  }
  return flag;
}

void ActionSpawn(Parameters *p_parameters) {
  InitPlayer(p_parameters->player_);
  InitPlayerPosition(p_parameters->player_);

  BlockType next_block_type = p_parameters->next_player_->block_type_;
  SetPlayerBlockType(p_parameters->player_, next_block_type);
  if (CheckCollisions(p_parameters)) {
    *p_parameters->player_state_ = kGameOver;
  } else {
    UpdatePredictPlayer(p_parameters->predict_player_, *p_parameters->player_,
                        p_parameters->board_);

    SetPlayerBlockType(p_parameters->next_player_, GetRandomBlockType());

    *p_parameters->player_state_ = kMoving;
  }
}

void ActionMoveUp(Parameters *p_parameters) {
  SetPlayerNextBlockRotation(p_parameters->player_);
  if (CheckCollide(p_parameters->player_, p_parameters->board_)) {
    SetPlayerPreviousBlockRotation(p_parameters->player_);
  }
  UpdatePredictPlayer(p_parameters->predict_player_, *p_parameters->player_,
                      p_parameters->board_);
  CheckCollisions(p_parameters);
}

void ActionMoveDown(Parameters *p_parameters) {
  MovePlayerDown(p_parameters->player_);

  CheckCollisions(p_parameters);
}

void ActionMoveLeft(Parameters *p_parameters) {
  bool flag_ok =
      !CheckFutureCollideWithLeft(p_parameters->player_, p_parameters->board_);
  flag_ok &= !CheckFutureCollideWithBlocksLeft(p_parameters->player_,
                                               p_parameters->board_);
  if (flag_ok) {
    MovePlayerLeft(p_parameters->player_);
  }
  UpdatePredictPlayer(p_parameters->predict_player_, *p_parameters->player_,
                      p_parameters->board_);
  CheckCollisions(p_parameters);
}

void ActionMoveRight(Parameters *p_parameters) {
  bool flag_ok =
      !CheckFutureCollideWithRight(p_parameters->player_, p_parameters->board_);
  flag_ok &= !CheckFutureCollideWithBlocksRight(p_parameters->player_,
                                                p_parameters->board_);
  if (flag_ok) {
    MovePlayerRight(p_parameters->player_);
  }
  UpdatePredictPlayer(p_parameters->predict_player_, *p_parameters->player_,
                      p_parameters->board_);
  CheckCollisions(p_parameters);
}

void ActionCollide(Parameters *p_parameters) {
  BoardOverlayBlock(p_parameters->player_, p_parameters->board_);

  *p_parameters->player_state_ = kSpawn;

  int complete_lines_count = HandleBoardCompleteLines(p_parameters->board_);

  if (complete_lines_count > 0) {
    AddScoreGameStatus(p_parameters->game_status_, complete_lines_count);
    UpdateGameStatusLevel(p_parameters->game_status_);
    AddRecord(p_parameters->records_, "Unnamed",
              p_parameters->game_status_->score_);
  }
}

void ActionGameOver(Parameters *p_parameters) {
  char name[14] = {0};
  GetPlayerName(name);

  RemoveRecord(p_parameters->records_, "Unnamed");
  AddRecord(p_parameters->records_, name, p_parameters->game_status_->score_);

  InitBoard(p_parameters->board_);
  InitGameStatus(p_parameters->game_status_);
  *p_parameters->player_state_ = kStart;

  PrintBegin();
}

void ActionExitState(Parameters *p_parameters) {
  SaveRecords(p_parameters->records_, RECORDS_FILE_NAME);
  *p_parameters->player_state_ = kExitState;
}
void ActionPause(Parameters *p_parameters) {
  if (*p_parameters->player_state_ != kPause) {
    *p_parameters->player_state_ = kPause;
    PrintPause();
  } else {
    *p_parameters->player_state_ = kMoving;
  }
}