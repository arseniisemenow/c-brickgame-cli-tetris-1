#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_FSM_FSM_TYPES_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_FSM_FSM_TYPES_H_

typedef enum {
  kStart = 0,
  kSpawn = 1,
  kMoving = 2,
  kCollide = 3,
  kGameOver = 4,
  kExitState = 5,
  kPause = 6,
} PlayerState;

typedef enum {
  kSignalNone = 0,
  kSignalMoveUp = 1,
  kSignalMoveDown = 2,
  kSignalMoveLeft = 3,
  kSignalMoveRight = 4,
  kSignalEscapeButton = 5,
  kSignalEnterButton = 6,
  kSignalPauseButton = 7,
} SignalType;

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_FSM_FSM_TYPES_H_
