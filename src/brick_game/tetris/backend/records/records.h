#ifndef C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_RECORDS_RECORDS_H_
#define C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_RECORDS_RECORDS_H_

#include <stdbool.h>

#define RECORDS_NUMBER (5)
#define RECORDS_FILE_NAME "records.records"

typedef struct {
  bool is_current_player_;
  char name_[20];
  int score_;
} Record;

typedef struct {
  Record records_[RECORDS_NUMBER];
} Records;

void InitRecords(Records *p_records);

void AddRecord(Records *p_records, const char *name, int score);
void RemoveRecord(Records *p_records, const char *name);

bool SaveRecords(const Records *p_records, const char *filename);

bool LoadRecords(Records *p_records, const char *filename);

void SortRecords(Records *p_records);

#endif  // C7_BRICK_GAME_V_1_0_1_BRICK_GAME_TETRIS_BACKEND_RECORDS_RECORDS_H_
