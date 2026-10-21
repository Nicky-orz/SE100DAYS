#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

/** 棋盘的最大边长。 */
#define MAX_N 100

/** 棋盘上空位的取值。 */
#define EMPTY_CELL 0

void board_init(int size);

void board_set(int x, int y, int value);

int board_size();

void board_set_view(int direction);

void board_display();

int board_get(int x, int y);

bool board_merged_at(int x, int y);

void board_clear_merged();

void board_move(int x, int y, int origin_x, int origin_y);

#endif //BOARD_H
