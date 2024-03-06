#include "tetris.h"

#include <stdlib.h>
#include <time.h>

int main(void) {
  WIN_INIT(50);
  setlocale(LC_ALL, "");
  srand(time(NULL));

  initscr();
  noecho();
  nodelay(stdscr, TRUE);
  start_color();

  game_loop();

  endwin();

  return 0;
}

void game_loop() {
  Board board = {0};
  InitBoard(&board);

  GameStatus game_status = {0};
  InitGameStatus(&game_status);

  Player player = {0};
  Player next_player = {0};
  Player predict_player = {0};
  InitPlayer(&player);
  InitNextPlayer(&next_player);

  PlayerState state = kStart;
  PrintBegin();

  bool break_flag = FALSE;
  bool key_held = false;
  int user_input = 0;

  Records records = {0};

  long long time_in_secs = GetTimeInMS();

  Parameters parameters = {0};
  parameters.game_status_ = &game_status;
  parameters.player_state_ = &state;
  parameters.board_ = &board;
  parameters.player_ = &player;
  parameters.next_player_ = &next_player;
  parameters.predict_player_ = &predict_player;
  parameters.last_moved_time_ = &time_in_secs;
  parameters.records_ = &records;

  LoadRecords(parameters.records_, RECORDS_FILE_NAME);

  InitGameColors();

  while (!break_flag) {
    if (state == kExitState) {
      break_flag = TRUE;
    }

    SignalType signal = GetSignal(user_input, 0, &key_held);
    SignalAction(signal, &parameters);

    user_input = GET_USER_INPUT;
  }
}