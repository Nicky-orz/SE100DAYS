#include <stdio.h>

int main() {
    int arr[6] = {10, 20, 30, 40, 50, 60};
    int* p1 = &arr[1];
    int* p2 = &arr[4];

    int actual1 = p2 - p1;
    int answer1 = 3; // 修改为第一个指针减法的正确结果

    int m[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    int* r1 = &m[1][0];
    int* r2 = &m[1][1];
    int actual2 = r2 - r1;
    int answer2 = 1; // 修改为第二个指针减法的正确结果

    int(*q1)[3] = &m[1];
    int(*q2)[3] = &m[3];
    int actual3 = q2 - q1;
    int answer3 = 2; // 修改为第三个指针减法的正确结果

    if (answer1 == actual1 && answer2 == actual2 && answer3 == actual3) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
