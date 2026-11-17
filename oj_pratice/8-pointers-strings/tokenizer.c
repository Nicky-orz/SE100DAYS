#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *reserved[16] = { "const", "int", "float", "double", "long", "static", "void", "char", "extern", "return", "break", "enum", "struct", "typedef", "union", "goto" };
const char *operator[11] = { "+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"};
char ans[20005];
int cnt;
bool t = false;

void add(char *s) {
    for (int i = 0; i < strlen(s); i++) ans[cnt++] = s[i];
    ans[cnt] = '\0';
}

void process(char *s) {
    if (t) return;
    if (strlen(s) == 0) return; 
    for (int i = 0; i < 16; i++) {
        if (strcmp(s, reserved[i]) == 0) {
            add("reserved ");
            return;
        }
    }
    for (int i = 0; i < 11; i++) {
        if (strcmp(s, operator[i]) == 0) {
            add("operator ");
            return;
        }
    }

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '.') cnt1++;
        else if (s[i] >= '0' && s[i] <= '9') cnt2++;
        else cnt3++;
    }
    if (cnt1 == 1 && cnt3 == 0 && cnt2 > 0) {
        add("float ");
        return;
    }

    int tt = true;
    for (int i = 0; s[i] != '\0'; i++) 
        if (s[i] < '0' || s[i] > '9') { tt = false; break; }
    if (tt) {
        add("integer ");
        return;
    }

    if (s[0] < '0' || s[0] > '9') {
        int ttt = true;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] < '0' || s[i] > '9')
                if (s[i] < 'a' || s[i] > 'z')
                    if (s[i] < 'A' || s[i] > 'Z')
                        if (s[i] != '_') {
                            ttt = false; break;
                        }
        }
        if (ttt) {
            add("variable ");
            return;
        }
    }
    t = true; 
}

int main() {
    char *s = malloc(5000 * sizeof(char));
    while (scanf("%s", s) != EOF) { // 忽略空白符的同时持续读入字符串
        for (char *pos = strchr(s, ';'); // 找到 s 中分号第一次出现的位置
            pos; // 若能找到分号，即 pos 不为空时，进入/继续循环
            s = pos + 1, pos = strchr(s, ';')) { // 循环找出剩下所有分号
            *pos = 0; // 将分号替换为字符串结束符 '\0'
            process(s);  // 处理从 *s 到 *pos 的字符串，已经没有分号
            ans[cnt++] = '\n', ans[cnt] = '\0';
        }
        if (s[0] != '\0') {
            process(s); // 处理最后一个分号之后的字符串
        }
        //printf("%s\n", ans);

    }
    if (t || s[0] != '\0') {
        printf("Compile Error");
    }
    else {
        printf("%s", ans);
    }
    return 0;
}
/*
const int a = 1;float b = a + 1.1;int a ; float b;
*/