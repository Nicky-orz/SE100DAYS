#include "const.h"
#include "solve.h"

#include <stdio.h>

char alphabet[MAX_A + 1];
int nums[MAX_N];

int main() {
    scanf("%s", alphabet);

    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    solve(nums, n, alphabet);
    return 0;
}
