#ifndef VIEW_H
#define VIEW_H

/**
 * 枚举，你可以理解为
<pre>
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
#define DIRECTION_COUNT 4
</pre>
 *
 * 四个取值与题面输入中的 right / down / left / up 一一对应。
 */
enum Dir {
    RIGHT,
    DOWN,
    LEFT,
    UP,
    DIRECTION_COUNT
};

#define DEFAULT_DIRECTION RIGHT

int view_x(int direction, int x, int y, int n);

int view_y(int direction, int x, int y, int n);

#endif //VIEW_H
