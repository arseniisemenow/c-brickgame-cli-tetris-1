#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_GAME_STATUS_GAME_STATUS_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_GAME_STATUS_GAME_STATUS_H_

#define MAX_LEVEL (10)
#define MAX_AVAILABLE_COMPLETE_LINES_COUNT (4)
#define SCORE_PER_LEVEL (600)

static const int kScoreCompleteLinesCountArray[4] = {100, 300, 700, 1500};

typedef struct {
  int score_;
  int level_;
} GameStatus;

void InitGameStatus(GameStatus *p_game_status);
void AddScoreGameStatus(GameStatus *p_game_status, int complete_lines_count);
void UpdateGameStatusLevel(GameStatus *p_game_status);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_GAME_STATUS_GAME_STATUS_H_
