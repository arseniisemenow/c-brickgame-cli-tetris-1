#include "frontend.h"

#include <ctype.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "../../brick_game/tetris/backend/parameters/parameters.h"
#include "../../brick_game/tetris/common/defines.h"

void PrintOverlay(void) {
  PrintRectangle(0, BOARD_HEIGHT + 1, 0, BOARD_WIDTH + 1);
  PrintRectangle(0, BOARD_HEIGHT + 1, BOARD_WIDTH + 2,
                 BOARD_WIDTH + HUD_WIDTH + 3);

  PrintRectangle(1, 6, BOARD_WIDTH + 3, BOARD_WIDTH + HUD_WIDTH + 2);

  PrintRectangle(7, 9, BOARD_WIDTH + 3, BOARD_WIDTH + HUD_WIDTH + 2);
  PrintRectangle(10, 12, BOARD_WIDTH + 3, BOARD_WIDTH + HUD_WIDTH + 2);

  MVPRINTW(1, BOARD_WIDTH + 5, "Next");
  MVPRINTW(7, BOARD_WIDTH + 5, "Score");
  MVPRINTW(10, BOARD_WIDTH + 5, "Level");
}

void PrintUserNamePrompt() {
  PrintRectangle(BOARD_HEIGHT / 2 - 5, BOARD_HEIGHT / 2 + 5, BOARDS_BEGIN,
                 BOARDS_BEGIN + BOARD_WIDTH * 2);
  for (int i = BOARD_HEIGHT / 2 - 5 + 1; i < BOARD_HEIGHT / 2 - 5 + 1 + 9;
       ++i) {
    for (int j = BOARDS_BEGIN + 1; j < BOARDS_BEGIN + 1 + 19; ++j) {
      MVPRINTW(i, j, " ");
    }
  }

  MVPRINTW(7, 5, "Enter your name:");
}

void PrintRectangle(int top_y, int bottom_y, int left_x, int right_x) {
  MVADDCH(top_y, left_x, ACS_ULCORNER);

  int i = left_x + 1;

  for (; i < right_x; i++) MVADDCH(top_y, i, ACS_HLINE);
  MVADDCH(top_y, i, ACS_URCORNER);

  for (int i_2 = top_y + 1; i_2 < bottom_y; i_2++) {
    MVADDCH(i_2, left_x, ACS_VLINE);
    MVADDCH(i_2, right_x, ACS_VLINE);
  }

  MVADDCH(bottom_y, left_x, ACS_LLCORNER);
  i = left_x + 1;
  for (; i < right_x; i++) MVADDCH(bottom_y, i, ACS_HLINE);
  MVADDCH(bottom_y, i, ACS_LRCORNER);
}

void PrintGameStatus(GameStatus *p_game_status) {
  MVPRINTW(8, BOARD_WIDTH + 5, "%7d", p_game_status->score_);
  MVPRINTW(11, BOARD_WIDTH + 5, "%7d", p_game_status->level_);
}

void ClearGame() {
  for (int row_index = 0; row_index < 24; ++row_index) {
    for (int column_index = 0; column_index < 28; ++column_index) {
      attron(COLOR_PAIR(INIT_COLOR_PAIR));
      mvprintw(row_index + BOARDS_BEGIN + 1, column_index + BOARDS_BEGIN + 1,
               " ");
      attroff(COLOR_PAIR(INIT_COLOR_PAIR));
    }
  }
}

void PrintGame(Parameters *p_parameters) {
  ClearGame();
  PrintOverlay();
  PrintBoard(p_parameters->board_);
  PrintGameStatus(p_parameters->game_status_);
  PrintRecords(p_parameters);
  PrintBlock(p_parameters->predict_player_);
  PrintBlock(p_parameters->player_);
  PrintBlock(p_parameters->next_player_);
}

void PrintBoard(Board *p_board) {
  for (int row_index = 0; row_index < 20; ++row_index) {
    for (int column_index = 0; column_index < 10; ++column_index) {
      if (p_board->cells_[row_index][column_index].is_set_) {
        int color = p_board->cells_[row_index][column_index].color_;
        attron(COLOR_PAIR(kBlockColorPairsArray[color]));
        mvprintw(row_index + BOARDS_BEGIN + 1, column_index + BOARDS_BEGIN + 1,
                 "S");
        attroff(COLOR_PAIR(kBlockColorPairsArray[color]));
      } else {
        attron(COLOR_PAIR(INIT_COLOR_PAIR));
        mvprintw(row_index + BOARDS_BEGIN + 1, column_index + BOARDS_BEGIN + 1,
                 " ");
        attroff(COLOR_PAIR(INIT_COLOR_PAIR));
      }
    }
  }
}

void PrintBlock(Player *p_player) {
  int player_pos_x = p_player->x_;
  int player_pos_y = p_player->y_;
  PlayerBoard player_board = p_player->board_;

  for (int row_index = 0; row_index < PLAYER_BOARD_SIZE; ++row_index) {
    for (int column_index = 0; column_index < PLAYER_BOARD_SIZE;
         ++column_index) {
      int print_y = player_pos_y + BOARDS_BEGIN + 1 + row_index;
      int print_x = player_pos_x + BOARDS_BEGIN + 1 + column_index;
      if (player_board.board_[row_index][column_index].is_set_) {
        int color = player_board.board_[row_index][column_index].color_;
        attron(COLOR_PAIR(kBlockColorPairsArray[color]));
        mvprintw(print_y, print_x, "F");
        attroff(COLOR_PAIR(kBlockColorPairsArray[color]));
      }
    }
  }
}

void GetPlayerName(char str[]) {
  PrintUserNamePrompt();
  int ch;
  int i = 0;

  flushinp();

  refresh();
  while ((ch = getch()) != '\n') {
    if (ch == ERR) {
      continue;
    } else if (ch == KEY_BACKSPACE || ch == DELETE) {
      if (i > 0) {
        i--;
        str[i] = '\0';
        mvprintw(12, 6, "%*s", MAX_LENGTH_NAME + 8, " ");
        mvprintw(12, 6, "%s", str);
        move(MAX_LENGTH_NAME, 6 + i);
        refresh();
      }
    } else if (i < MAX_LENGTH_NAME - 1 && isprint(ch)) {
      str[i++] = ch;
      str[i] = '\0';
      mvprintw(12, 6, "%s", str);
      refresh();
    }
  }
  getch();
}

void PrintBegin() {
  ClearGame();

  PrintRectangle(0, BOARDS_BEGIN + BOARD_HEIGHT - 1, 0,
                 BOARDS_BEGIN + BOARD_WIDTH + HUD_WIDTH + 1);
  mvprintw(12, 8, "Press Enter");
}

void PrintPause() {
  PrintRectangle(0 + 8, BOARDS_BEGIN + BOARD_HEIGHT - 1 - 8, 0 + 4,
                 BOARDS_BEGIN + BOARD_WIDTH + HUD_WIDTH + 1 - 4);
  for (int i = 11; i < 15; ++i) {
    for (int j = 7; j < 23; ++j) {
      mvprintw(i, j, " ");
    }
  }
  mvprintw(12, 8, "Game is paused");
}

void ClearRecords() {}

void PrintRecords(Parameters *p_parameters) {
  ClearRecords();
  PrintRectangle(13, 20, 13, 24);
  mvprintw(15, 17, "Records");

  attron(COLOR_PAIR(RECORD_1_COLOR_PAIR_INDEX));
  mvprintw(16, 16, "1. %7d", p_parameters->records_->records_[0].score_);
  attron(COLOR_PAIR(RECORD_1_COLOR_PAIR_INDEX));
  attron(COLOR_PAIR(RECORD_2_COLOR_PAIR_INDEX));
  mvprintw(17, 16, "2. %7d", p_parameters->records_->records_[1].score_);
  attroff(COLOR_PAIR(RECORD_2_COLOR_PAIR_INDEX));
  attron(COLOR_PAIR(RECORD_3_COLOR_PAIR_INDEX));
  mvprintw(18, 16, "3. %7d", p_parameters->records_->records_[2].score_);
  attroff(COLOR_PAIR(RECORD_3_COLOR_PAIR_INDEX));

  attron(COLOR_PAIR(RECORD_4_5_COLOR_PAIR_INDEX));
  mvprintw(19, 16, "4. %7d", p_parameters->records_->records_[3].score_);
  attroff(COLOR_PAIR(RECORD_4_5_COLOR_PAIR_INDEX));
  attron(COLOR_PAIR(RECORD_4_5_COLOR_PAIR_INDEX));
  mvprintw(20, 16, "5. %7d", p_parameters->records_->records_[4].score_);
  attroff(COLOR_PAIR(RECORD_4_5_COLOR_PAIR_INDEX));
}
