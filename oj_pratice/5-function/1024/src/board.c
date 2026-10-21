#include "board.h"

#include "view.h"

#include <stdbool.h>
#include <stdio.h>

/** 棋盘的边长。 */
static int n;

/**
 * 棋盘上所有 cell，存储其数值。
 *
 * x 为行，y 为列。即原点在 (0, 0)，x 轴向下，y 轴向右。
 *
 * 空位用 EMPTY_CELL 表示。
 */
static int cells[MAX_N][MAX_N];

/**
 * 合并标记。
 *
 * merged[x][y] 表示默认坐标系下 (x, y) 处的 cell 是否为本轮移动中由两个 cell 合并得到的。
 */
static bool merged[MAX_N][MAX_N];

/**
 * 当前的正方向。外界通过改变正方向，来改变看棋盘时所用的坐标系。
 *
 * 2048 有右、下、左、上四种移动方向，但每种方向要做的事情是相同的。
 * 因此我们希望抽象出一份共同的移动逻辑。  
 * 为此引入正方向 D：记本次移动方向为 D，D 取右、下、左、上之一。  
 * 选定 D 后，我们变换棋盘的坐标系，使 y 轴正向指向 D，x 轴与它垂直。
 * 这样，四种方向的移动就可以统一为：合理变换坐标系后，沿 y 轴正向（即正方向）移动方块。
 *
 * 正方向总是 y 轴正向，而变换坐标系的目的是让 y 轴指向移动方向。
 * 因此确定了正方向就确定了坐标系。
 *
 * 默认坐标系的 x 轴向下，y 轴向右，我们定义默认正方向为右。
 * _ 和 * 便于看格子，无特殊含义。
<pre>
    0 1 2 3
    - - - - > y
0 | * * * *
1 | * _ _ _
2 | * _ _ _
3 | * * * *
  v
  x
</pre>
 *
 * 如果我们现在以向上为正方向，则坐标系需要逆时针旋转 90 度；注意，原点也发生了变化。
 *
<pre>
  y
  ^
3 | * * * *
2 | * _ _ _
1 | * _ _ _
0 | * * * *
    - - - - > x
    0 1 2 3
</pre>
 */
static int positive_direction;

/**
 * 把棋盘重置为 size × size 的空棋盘。
 *
 * @param size 棋盘边长
 */
void board_init(int size) {
    n = size;
    positive_direction = DEFAULT_DIRECTION;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cells[x][y] = EMPTY_CELL;
            merged[x][y] = false;
        }
    }
}

/**
 * 获取当前棋盘的边长。
 *
 * @return 棋盘的边长 n
 */
int board_size() {
    return n;
}

/**
 * 设置 (x, y) 处的 cell。
 *
 * 坐标是在以 positive_direction 为正方向的坐标系下的坐标。
 *
 * @param x x 坐标，与正方向垂直的方向
 * @param y y 坐标，沿正方向的方向
 * @param value 新的数值，EMPTY_CELL 表示空位
 */
void board_set(int x, int y, int value) {
    int direction = positive_direction;
    cells[view_x(direction, x, y, n)][view_y(direction, x, y, n)] = value;
}

/**
 * 设置当前的正方向。
 *
 * @param direction 新的正方向，取枚举的取值（RIGHT / DOWN / LEFT / UP）
 */
void board_set_view(int direction) {
    positive_direction = direction;
}

/**
 * 输出棋盘。
 *
 * 共输出 n 行，每行 n 个 cell，同一行的 cell 之间用空格分隔，行末换行。
 */
void board_display() {
    for (int x = 0; x < n; x++) {
        printf("%d", cells[x][0]);
        for (int y = 1; y < n; y++) {
            printf(" %d", cells[x][y]);
        }
        printf("\n");
    }
}

/**
 * 读取 (x, y) 处的 cell。
 *
 * 坐标是在以 positive_direction 为正方向的坐标系下的坐标。
 *
 * @param x x 坐标，与正方向垂直的方向
 * @param y y 坐标，沿正方向的方向
 * @return (x, y) 处的 cell 值
 */
int board_get(int x, int y) {
    int direction = positive_direction;
    return cells[view_x(direction, x, y, n)][view_y(direction, x, y, n)];
}

/**
 * 判断 (x, y) 处的 cell 是不是本轮移动中合并出来的。
 *
 * 坐标是在以 positive_direction 为正方向的坐标系下的坐标。
 *
 * @param x x 坐标，与正方向垂直的方向
 * @param y y 坐标，沿正方向的方向
 * @return 若本轮中该位置的 cell 是由两个 cell 合并得到的，则返回 true，否则返回 false
 */
bool board_merged_at(int x, int y) {
    int direction = positive_direction;
    return merged[view_x(direction, x, y, n)][view_y(direction, x, y, n)];
}

/**
 * 清除棋盘上所有非空格的合并标记。
 */
void board_clear_merged() {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (cells[x][y] != EMPTY_CELL) {
                merged[x][y] = false;
            }
        }
    }
}

/**
 * 将 (origin_x, origin_y) 处的 cell 直接移动到 (x, y)，并处理可能发生的合并。
 *
 * 坐标是在以 positive_direction 为正方向的坐标系下的坐标。
 *
 * 规则是：
 * - 将起始格的 cell 直接搬到目标格；
 * - 目标格为空时，cell 直接落入；
 * - 目标格上数值相同时，合并为原来的两倍，并标记该格在本轮中发生了合并；
 * - 目标格上数值不同时（调用方本不该这样调用），撤销移动并直接返回。
 *
 * @param x 目标位置的 x 坐标
 * @param y 目标位置的 y 坐标
 * @param origin_x 起始位置的 x 坐标
 * @param origin_y 起始位置的 y 坐标
 */
void board_move(int x, int y, int origin_x, int origin_y) {
    // TODO: 实现 board_move
    if(origin_x == x && origin_y == y)
        return;
    int ori = board_get(origin_x,origin_y);
    int tar = board_get(x,y);
    if(tar == EMPTY_CELL){
        board_set(x,y,ori);
        board_set(origin_x,origin_y,EMPTY_CELL);
    }
    else if(ori == tar){
        board_set(x,y,ori+tar);
        board_set(origin_x,origin_y,EMPTY_CELL);
        int direction = positive_direction;
        merged[view_x(direction, x, y, n)][view_y(direction, x, y, n)] = true;
    }
    else return;
}
