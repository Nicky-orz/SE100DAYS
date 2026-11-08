#include <stdio.h>

#define N 3

void foo1(int* p) {
    *p = 2;
}

void foo2(int* p) {
    int y = 3;
    p = &y;
}

void foo3(int* a, int val) {
    for (int i = 0; i < N; ++i) {
        *(a + i) += val;
    }
}

void foo4(int* dst, int* src, int n) {
    while (n--) {
        *dst++ = *src++;
    }
}

void foo5(int (*m)[N], int col, int val) {
    for (int i = 0; i < 2; ++i) {
        *(*(m + i) + col) += val;
    }
}

int main() {
    int x = 1;
    int* p1 = &x;
    foo1(p1);
    int actual1 = x;
    int answer1 = 2;

    foo2(p1);
    int actual2 = *p1;
    int answer2 = 2;

    int m1[2][N] = {{1, 1, 4}, {5, 1, 4}};
    foo3(m1[1], 2);
    int actual4 = m1[1][0];
    int answer4 = 7;

    int m2[2][N] = {{1, 1, 4}, {5, 1, 4}};
    foo4(m2[1], m2[0], 2);
    int actual3 = m2[1][0];
    int answer3 = 1;

    int m3[2][N] = {{7, 2, 3}, {4, 5, 7}};
    foo5(&m3[0], 1, 3);
    int actual5 = m3[0][1];
    int answer5 = 5;

    if (answer1 == actual1 && answer2 == actual2 && answer3 == actual3 &&
        answer4 == actual4 && answer5 == actual5) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
