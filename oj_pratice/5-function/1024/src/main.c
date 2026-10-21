#include "view.h"
#include "board.h"
#include "slide.h"

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    board_init(n);
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int value;
            scanf("%d", &value);
            board_set(row, col, value);
        }
    }

    int t;
    scanf("%d", &t);

    char word[10];
    while (t--) {
        scanf("%s", word);
        int direction = DEFAULT_DIRECTION;
        // rdlu - right / down / left / up 的首字母缩写
        while (word[0] != "rdlu"[direction]) {
            direction = (direction + 1) % DIRECTION_COUNT;
        }
        slide_board(direction);
        board_display();
    }
    //board_display();
    return 0;
}
