#include <stdio.h>
int main() {
    unsigned int a;
    scanf("%x",&a);
    printf("%d\n%u\n%.6f\n%.3e", *(int*)&a, a, *(float*)&a, *(float*)&a);
    return 0;
}