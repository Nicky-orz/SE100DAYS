#include "view.h"

/**
 * 旋转坐标系、使 RIGHT / DOWN / LEFT / UP 分别成为正方向后，新坐标系的原点
 * 在原坐标系下的坐标（已归一化）。
 *
 * 例如，若棋盘边长为 n，那么以向上为正方向时，新坐标系的原点在原坐标系下的坐标为 (n - 1, 0)；
 * 取归一化系数为 n - 1，归一化后即为 (1, 0)。
 */
static int o_x[DIRECTION_COUNT] = {0, 0, 1, 1};
static int o_y[DIRECTION_COUNT] = {0, 1, 1, 0};

/**
 * 旋转坐标系、使 RIGHT / DOWN / LEFT / UP 分别成为正方向后，新坐标系 x 轴正向的
 * 单位向量 e 在原坐标系下的坐标。
 *
 * 注意，y 轴正向的单位向量可由 e 逆时针旋转 90 度得到，故它在原坐标系下的坐标为 (-e_y, e_x)，不需要额外存储。
 */
static int e_x[DIRECTION_COUNT] = {1, 0, -1, 0};
static int e_y[DIRECTION_COUNT] = {0, -1, 0, 1};

/**
 * 以 direction 为正方向（即旋转坐标系）后，新坐标系中的点 (x, y) 在原坐标系下的 x 坐标。
 *
 * 坐标变换公式如下，其中 k = n - 1 为原点坐标的归一化系数。
 *
 * 参考 latex 渲染网站：<a href="https://www.latexlive.com/">LaTeX Live</a>
 *
<pre>
\begin{pmatrix} e_x & -e_y \\ e_y & e_x \end{pmatrix}
\begin{pmatrix} x \\ y \end{pmatrix} +
k \begin{pmatrix} o_x \\ o_y \end{pmatrix} =
\begin{pmatrix} view\_x \\ view\_y \end{pmatrix}
</pre>
 *
 * @param direction 正方向，取枚举的取值（RIGHT / DOWN / LEFT / UP）
 * @param x 新坐标系下的 x 坐标
 * @param y 新坐标系下的 y 坐标
 * @param n 棋盘边长
 * @return 新坐标系中的点 (x, y) 在默认坐标系下的 x 坐标
 */
int view_x(int direction, int x, int y, int n) {
    return e_x[direction] * x - e_y[direction] * y + (n - 1) * o_x[direction];
}

/**
 * 以 direction 为正方向（即旋转坐标系）后，新坐标系中的点 (x, y) 在原坐标系下的 y 坐标。
 *
 * @param direction 正方向，取枚举的取值（RIGHT / DOWN / LEFT / UP）
 * @param x 新坐标系下的 x 坐标
 * @param y 新坐标系下的 y 坐标
 * @param n 棋盘边长
 * @return 新坐标系中的点 (x, y) 在默认坐标系下的 y 坐标
 */
int view_y(int direction, int x, int y, int n) {
    return e_y[direction] * x + e_x[direction] * y + (n - 1) * o_y[direction];
}
