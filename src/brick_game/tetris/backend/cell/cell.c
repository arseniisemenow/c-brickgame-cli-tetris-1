#include "cell.h"

#include "../../common/colors.h"

void InitCell(Cell *p_cell) {
  p_cell->is_set_ = false;
  p_cell->color_ = COLOR_BLACK;
}

void CopyCell(Cell *p_cell_dest, Cell cell_src) {
  p_cell_dest->color_ = cell_src.color_;
  p_cell_dest->is_set_ = cell_src.is_set_;
}
