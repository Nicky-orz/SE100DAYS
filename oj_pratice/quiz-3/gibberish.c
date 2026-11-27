#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define For(n) for(int i = 0; i < n; i++)
typedef struct action{
    char name[5];
    int arg;
    int id;
}action;
int t, n;
action actions[105];
char ans[10005];
int tail;

void inc(int arg) {
    ans[tail] = (char) arg;
    ans[++tail] = '\0';
}

void del(int arg) {
    int w = 0;
    For(tail)
        if (ans[i] != arg) ans[w++] = ans[i];
    tail = w;
    ans[tail] = '\0';
}

void rev(int arg) {
    if (strchr(ans, arg) == NULL) return;
    int l = strchr(ans, arg) - ans;
    int r = strrchr(ans, arg) - ans;
    if (l != r) {
        char ori[10005];
        for (int i = l; i <= r; i++)
            ori[i] = ans[i];
        for (int i = l; i <= r; i++)
            ans[i] = ori[r - (i - l)];
    }
}

void rot(int arg) {
    char *p = strchr(ans, arg);
    if (p == NULL) return;
    char newans[10005];
    memset(newans, 0, sizeof(newans));
    strncpy(newans, p, tail - (p - ans));
    For(p - ans) newans[tail - (p - ans) + i] = ans[i];
    strcpy(ans, newans);
    ans[tail] = '\0';
}

void act(char name[4], int arg) {
    if (strcmp(name, "inc") == 0)
        inc(arg);
    else if(strcmp(name, "del") == 0)
        del(arg);
    else if(strcmp(name, "rev") == 0)
        rev(arg);
    else if(strcmp(name, "rot") == 0)
        rot(arg);
}
int main(){
    scanf("%d %d", &t, &n);
    For(n) scanf("%s %d %d", actions[i].name, &actions[i].arg, &actions[i].id);
    For(t) {
        int isact = 0;
        for(int j = 0; j < n; j++)
            if (!isact && actions[j].id == (i + 1)) isact = 1, act(actions[j].name, actions[j].arg);
        if (!isact) act("inc", 97 + ((i + 1) % 26));
        //printf("%s\n", ans);
    }
    printf("%s\n", ans);
    return 0;
}