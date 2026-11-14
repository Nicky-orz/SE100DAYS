#include <stdio.h>
#define maxn 1005

void local_change(char *p, int k, char c)
{
    p += k;
    *p = c;
}

void shared_change(char **p, int k, char c)
{
    *p += k;
    **p = c;
}

int q;
char s[maxn];
int main() {
    scanf("%s", s);
    scanf("%d", &q);
    char *p = s;
    for (int i = 0; i < q; i++) {
        char ord, c;
        int k;
        scanf(" %c %d %c", &ord, &k, &c);
        if (ord == 'L') local_change(p, k, c);
        else if (ord == 'R') shared_change(&p, k, c); 
        //printf("%c %d %c\n",ord,k,c);
    }
    printf("%s\n%d", s, p - s);
    return 0;
}