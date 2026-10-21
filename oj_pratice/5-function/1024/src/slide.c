#include "slide.h"

#include "board.h"

/**
 * 把 (x, y) 处的 cell 沿正方向滑动，直到不能再滑。
 *
 * @param x 行坐标（与正方向垂直的方向）
 * @param y 列坐标（沿正方向的方向）
 */
void slide_cell(int x, int y) {
    int target_y = y;
    int Board_size = board_size();
    int ori = board_get(x,y);
    while(target_y+1 < Board_size && board_get(x,target_y+1) == EMPTY_CELL)
        target_y++;
    if(target_y+1 < Board_size && board_get(x,target_y+1) == ori && !board_merged_at(x,target_y+1))
        target_y++;
    board_move(x, target_y, x, y);
}

/**
 * 向 direction 方向滑动整个棋盘。
 *
 * 通过设置正方向，我们可以复用同一套滑动逻辑：
 * 沿垂直于正方向的方向（x 轴）遍历每一行，
 * 然后按照正确的顺序依次滑动行内每个方块。
 *
 * 注意正确处理合并标记在滑动棋盘前的状态。
 *
 * @param direction 滑动方向，取枚举的取值（RIGHT / DOWN / LEFT / UP）
 */
void slide_board(int direction) {
    int Board_size = board_size();
    board_set_view(direction);
    board_clear_merged();
    for(int i=0;i<Board_size;i++)
        for(int j=Board_size-1;j>=0;j--)
            if(!board_merged_at(i,j))
                slide_cell(i,j);

}