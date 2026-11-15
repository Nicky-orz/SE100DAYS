#include <stdio.h>
#include <stdbool.h>
#define maxn 85
#define maxm 305
int n, m, k;
int add[maxn][maxm];

bool check(int C) {
    bool Cche = false;
    for (int line = 1; line < n; line++) {
        bool Lche = true;
        int Usum = 0, Dsum = 0, knum = 0;
        for (int row = 1; row <= m; row++) {
            int U = add[line][row]- add[line][row - 1];
            int D = add[n][row] - add[line][row] - add[n][row-1] + add[line][row-1];
            if (U > C) {Lche = false; break;}
            if (D > C) {Lche = false; break;}
            Usum += U;
            Dsum += D;
            if (Usum > C || Dsum > C) {
                knum++;
                Usum = U;
                Dsum = D;
            }
        }
        if (Lche && knum < k) {
            Cche = true;
            break;
        }
    }
    return Cche;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int t;
            scanf("%d", &t);
            add[i][j] = add[i-1][j] + add[i][j-1] - add[i-1][j-1] + t;
        }
    int l = 0, r = add[n][m]+1;
    while (l < r) {
        int mid = (l + r)/2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d", l);
    return 0;
}
/*
T2 - 超正方体 (tesseract.c)
超正方体 (tesseract.c)
100 ms
256000 KiB
195/2550 = 7.65%

 题目描述
 提交列表
题目描述
出题助教：冯思博、赵心泉（加入了史莱姆 😈）

验题助教：赵心泉、胡燃、李建宇、郑袭明、梁志浩、曹宇航

小 🔥 发现 8 只方方正正的史莱姆聚集在了一起，奇迹般地变成了超正方体史莱姆！难道这就是奇迹史莱姆的真身？

超正方体是四维空间内的“立方体”。超正方体之于立方体，就如同立方体之于正方形。标准正交四维坐标系中，单位超正方体的顶点坐标为 
，每维坐标均只能为 
 或 
。记各个顶点的编号为：

例如，顶点 
 的编号为 
，顶点 
 的编号为 
，顶点 
 的编号为 
……不难看出，顶点编号的范围为 
。

超正方体的棱由只有一个维度的坐标不同的两个顶点构成，如顶点 
 与 
 构成了超正方体的一条棱。

现在给出一个可能不完整的单位超正方体，请计算：添加哪一个缺失顶点，可以使新增的棱数量最多？

“新增的”棱是指原本缺失，添加顶点后出现的棱。

如果有多个候选顶点，选择编号最小的；如果原超正方体完整，则输出 
。

输入格式
一个长度恰好为 
 的字符串 
，仅由字符 0 和 1 组成，第 
 个字符表示编号为 
 的顶点状态，0 表示缺失，1 表示正常。

输出格式
一个整数，表示新增棱数量最多时，应添加的顶点编号。

若所有顶点均正常，输出 -1。

公开用例 #1
公开用例 #2
题目注解
数据分布
 的测试数据中，原超正方体是完好的。
 的测试数据中，原超正方体是空的。
 的测试数据中，原超正方体恰缺少一个顶点。
样例解释
缺失顶点的编号为 
。分别添加它们时，新增完整棱的数量如下：

添加顶点	新增棱
因此，问题的答案为 
。

image

一
个
超
正
方
体
的
三
维
投
影
解题思路
本题数据量很小，因此你可以直接二重循环遍历所有顶点的两两组合，再判断每个组合是不是超正方体中合法的棱。

至于计数，你可以任选一种你认为容易理解的方式：

先计算出初始棱的数量，然后遍历每个缺失顶点，分别计算添加每个缺失顶点后新增棱的数量；

枚举所有棱（无论初始是否存在），为 欲使初始不存在的棱出现，需要添加的顶点 累计贡献值（思考什么情况下添加一个顶点能够新增棱？）。

贡献值即为添加该缺失顶点能够新增的棱的数量


*/