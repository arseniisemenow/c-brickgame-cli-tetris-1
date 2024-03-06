#include "debugger.h"

#include <stdlib.h>

#include "../backend/backend.h"
#include "../fsm/fsm.h"
#include "../fsm/fsm_types.h"

void SignalInfoDebug(SignalType signal) {
  const int kXShift = 40;
  const int kYShift = 2;
  static int signal_none_y_shift = 1;
  if (signal == kSignalNone) {
    if (signal_none_y_shift < 30) {
      signal_none_y_shift++;
    } else {
      mvprintw(kYShift, kXShift, "[None signal]\n");
      signal_none_y_shift = 1;
    }
  } else if (signal == kSignalEnterButton) {
    mvprintw(kYShift + 1, kXShift, "[Enter button]\n");
  } else if (signal == kSignalEscapeButton) {
    mvprintw(kYShift + 2, kXShift, "[Escape button]\n");
  } else if (signal == kSignalMoveUp) {
    mvprintw(kYShift + 3, kXShift, "[Move up button]\n");
  } else if (signal == kSignalMoveDown) {
    mvprintw(kYShift + 4, kXShift, "[Move down button]\n");
  } else if (signal == kSignalMoveLeft) {
    mvprintw(kYShift + 5, kXShift, "[Move left button]\n");
  } else if (signal == kSignalMoveRight) {
    mvprintw(kYShift + 6, kXShift, "[Move right button]\n");
  }
}

void ParamsInfoDebug(Parameters parameters) {
  PlayerState player_state = *parameters.player_state_;
  int y_shift = 5;
  const int kXShift = 40;
  const int kMessageLength = 20;

  static int color_array[8] = {0};
  static const char *color_string_array[8] = {
      "Start state", "Spawn state",   "Moving state",    "Shifting state",
      "Reach state", "Collide state", "Game Over state", "Exit state",
  };
  const short colors[4] = {0, COLOR_BLACK, COLOR_RED, COLOR_BLUE};
  const short pair_index[8] = {10, 11, 12, 13, 14, 15, 16, 17};

  static int flags[kExitState + 1] = {};
  for (int i = 0; i <= kExitState; ++i) {
    init_pair(pair_index[color_array[i]], colors[color_array[i]], COLOR_BLACK);
    if (flags[i] <= 10) {
      flags[i]++;
    } else {
      flags[i] = 0;

      if (color_array[i] >= 1) {
        color_array[i]--;
        mvprintw(y_shift + i, kXShift, "[");

        attron(COLOR_PAIR(pair_index[color_array[i]]));

        mvprintw(y_shift + i, kXShift + 1, "%*s\n", kMessageLength,
                 color_string_array[i]);

        attroff(COLOR_PAIR(pair_index[color_array[i]]));

        mvprintw(y_shift + i, kXShift + kMessageLength + 1, "]");
      } else {
        init_pair(3, COLOR_WHITE, COLOR_BLACK);
        mvprintw(y_shift + i, kXShift, "[");
        attron(COLOR_PAIR(3));
        mvprintw(y_shift + i, kXShift + 1, "%*s\n", kMessageLength, "");
        attroff(COLOR_PAIR(3));
        mvprintw(y_shift + i, kXShift + kMessageLength + 1, "]");
      }
    }
  }

  y_shift += player_state;

  if (player_state == kStart) {
    mvprintw(y_shift, kXShift, "[%*s]\n", kMessageLength,
             color_string_array[player_state]);
  } else if (player_state == kSpawn) {
    mvprintw(y_shift, kXShift, "[%*s]\n", kMessageLength,
             color_string_array[player_state]);
  } else if (player_state == kMoving) {
    mvprintw(y_shift, kXShift, "[%*s]\n", kMessageLength,
             color_string_array[player_state]);
  } else if (player_state == kCollide) {
    mvprintw(y_shift, kXShift, "[%*s]\n", kMessageLength,
             color_string_array[player_state]);
  } else if (player_state == kGameOver) {
    mvprintw(y_shift, kXShift, "[%*s]\n", kMessageLength,
             color_string_array[player_state]);
  } else if (player_state == kExitState) {
    mvprintw(y_shift, kXShift, "[%*s]\n", kMessageLength,
             color_string_array[player_state]);
  }
  color_array[player_state] = 3;
}

void PlayerPositionInfoDebug(Player player_info) {
  const int kYShift = 15;
  const int kXShift = 40;
  const int kLength = 18;

  mvprintw(kYShift, kXShift, "[Player info]\n");
  mvprintw(kYShift, kXShift, "[x: %*c]\n", kLength, player_info.x_ + '0');
  mvprintw(kYShift + 1, kXShift, "[y: %*c]\n", kLength, player_info.y_ + '0');
  mvprintw(kYShift + 2, kXShift, "[kBlocksBitmask: %*s]\n", kLength - 5,
           GetBlockTypeString(player_info.block_type_));
  // TODO print all information
}

char *GetBlockTypeString(BlockType block_type) {
  if (block_type == kBlockI) {
    return "I";
  } else if (block_type == kBlockJ) {
    return "J";
  } else if (block_type == kBlockL) {
    return "L";
  } else if (block_type == kBlockO) {
    return "O";
  } else if (block_type == kBlockS) {
    return "S";
  } else if (block_type == kBlockT) {
    return "T";
  } else if (block_type == kBlockZ) {
    return "Z";
  }
  return "?";
}

void ActionInfoDebug(action_callback callback) {
  const int kXShift = 40;
  int y_shift = 20;
  const int kMessageLength = 20;

  static int color_array_action[8] = {0};
  static const char *color_string_array[8] = {
      "Action Spawn",     "Action Move Up",    "Action Move Down",
      "Action Move Left", "Action Move Right", "Action Collide"};

  const short colors[4] = {0, COLOR_BLACK, COLOR_YELLOW,
                           COLOR_WHITE};  // Change char to int
  const short pair_index[8] = {20, 21, 22, 23,
                               24, 25, 26, 27};  // Change char to int

  for (int i = 0; i < 8; ++i) {  // Fix loop condition
    init_pair(pair_index[color_array_action[i]], colors[color_array_action[i]],
              COLOR_BLACK);

    if (color_array_action[i] >= 1) {
      mvprintw(y_shift + i, kXShift, "[");
      attron(COLOR_PAIR(pair_index[color_array_action[i]]));
      mvprintw(y_shift + i, kXShift + 1, "%-*s", kMessageLength,
               color_string_array[i]);  // Change %*s to %-*s
      attroff(COLOR_PAIR(pair_index[color_array_action[i]]));
      mvprintw(y_shift + i, kXShift + kMessageLength + 1, "]");
      color_array_action[i]--;
    } else {
      init_pair(3, COLOR_WHITE, COLOR_BLACK);
      mvprintw(y_shift + i, kXShift, "[");
      attron(COLOR_PAIR(3));
      mvprintw(y_shift + i, kXShift + 1, "%-*s", kMessageLength,
               "");  // Change %*s to %-*s
      attroff(COLOR_PAIR(3));
      mvprintw(y_shift + i, kXShift + kMessageLength + 1, "]");
    }
  }
  int index = 0;
  if (callback == ActionSpawn) {
    index = 0;
  } else if (callback == ActionMoveUp) {
    index = 1;
  } else if (callback == ActionMoveDown) {
    index = 2;
  } else if (callback == ActionMoveLeft) {
    index = 3;
  } else if (callback == ActionMoveRight) {
    index = 4;
  } else if (callback == ActionCollide) {
    index = 5;
  }

  color_array_action[index] = 3;
}
