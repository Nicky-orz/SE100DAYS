#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
  int a, b;
  int *pa = &a, *pb = &b;
  scanf("%d%d", pa, pb);
  swap(pa, pb);
  printf("%d %d", a, b);
  return 0;
}