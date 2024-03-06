#ifndef C7_BRICK_GAME_V_1_0_1_GUI_CLI_FRONTEND_H_
#define C7_BRICK_GAME_V_1_0_1_GUI_CLI_FRONTEND_H_

#include "../../brick_game/tetris/backend/block/block.h"
#include "../../brick_game/tetris/backend/board/board.h"
#include "../../brick_game/tetris/backend/cell/cell.h"
#include "../../brick_game/tetris/backend/game_status/game_status.h"
#include "../../brick_game/tetris/backend/parameters/parameters.h"
#include "../../brick_game/tetris/backend/player/player.h"

#define MAX_LENGTH_NAME (10)

void PrintUserNamePrompt();
void PrintOverlay(void);
void PrintRectangle(int top_y, int bottom_y, int left_x, int right_x);
void PrintGameStatus(GameStatus *p_game_status);
void PrintGame(Parameters *p_parameters);
void ClearGame();
void PrintBlock(Player *p_player);
void PrintBoard(Board *p_board);
void GetPlayerName(char p_parameters[]);
void PrintBegin();
void PrintPause();
void ClearRecords();
void PrintRecords(Parameters *p_parameters);

#endif  // C7_BRICK_GAME_V_1_0_1_GUI_CLI_FRONTEND_H_