# P17592 Crave Wave Ver.2 题解(GLM5.3)

> **一句话**：答案是只依赖 $x$ 末尾 $0$ 的个数 $s$ 与 $k$ 的函数 $U(s,k)$；把"可达"转化为"带符号的 $2$ 的幂的子集和"，得到 $U=2R-1$，而 $R$ 可以用一个 $\Theta(n^2)$ 的**相邻权值对 DP** 求出。
>
> **考点**：二进制 + 按位递推 + "相邻状态差有界 ⟹ 只追踪相邻对形态"的计数套路。
>
> **题眼**：相邻权值之差只有 $-1,0,+1$。看出来之后，剩下全是常规 DP。

---

## 一、答案只依赖 $s$ 和 $k$

设 $s=\mathrm{tz}(x)$（$x$ 末尾 $0$ 的个数）。答案 $=U(s,k)$，与 $x$ 的高位无关。



1. $y\pm\mathrm{lowbit}(y)$ 后，$\mathrm{tz}$ **严格增大**：第 $p$ 位的 $1$ 加上或减去 $2^p$ 都会向更高位进位/借位，低位全变 $0$。
2. 倒推 $k$ 步：第 $i$ 步用的指数 $p_i$ 必须小于当前 $\mathrm{tz}$，而当前 $\mathrm{tz}$ 恰好是上一步的 $p_{i-1}$，所以
$$s>p_1>p_2>\cdots>p_j,\quad j\le k.$$
   即**指数严格递减、两两不同、都 $<s$**。
3. 反过来，任给这样的指数集合 $T$ 和符号 $\varepsilon_t$，从大到小依次施加就是合法路径（归纳：每步后 $\mathrm{tz}$ 恰好等于刚用的指数）。

所以
$$\boxed{\ y=x+\sum_{t\in T}\varepsilon_t2^t,\quad T\subseteq[0,s),\ |T|\le k.\ }$$

$x$ 只是常数偏移。**只需数不同的 $m=\sum\varepsilon_t2^t$**。

---

## 二、把"数不同值"变成"数权值"

定义
$$w_s(v)=\min\{|T|:v=\sum_{t\in T}\varepsilon_t2^t,\ T\subseteq[0,s)\}.$$

三个基本事实：

- $w_s(0)=0$，$w_s(v)=w_s(-v)$；
- $v$ 可用 $\le k$ 项表示 $\iff w_s(v)\le k$；
- 表示出的 $v\in[0,2^s)$。

由正负对称：
$$\boxed{\,U(s,k)=2R(s,k)-1\,},\quad R(s,k)=\#\{v\in[0,2^s):w_s(v)\le k\}.$$

接下来只要能算 $R$。

---

## 三、$w$ 的按位递推

按 $v$ 的最低位分类：

- **$v=2u$（偶）**：位置 $0$ 上的 $\pm1$ 无法贡献到偶数，所有项 $\ge1$，同除以 $2$：
$$w_s(2u)=w_{s-1}(u).$$
- **$v=2u+1$（奇）**：位置 $0$ 必须用。要么 $+1$，剩下 $2u$；要么 $-1$，剩下 $2(u+1)$：
$$w_s(2u+1)=1+\min\bigl(w_{s-1}(u),\,w_{s-1}(u+1)\bigr).$$

---

## 四、题眼：相邻权值差只有 $-1,0,+1$

 对 $a\in[0,2^s)$ 且 $a<2^s-1$，$w_s(a+1)-w_s(a)\in\{-1,0,+1\}$。

相邻权值构成的**对**只有 3 种形态 + 1 个边界：
$$Ee(i)=(i,i),\quad Eu(i)=(i,i+1),\quad Ed(i)=(i+1,i),\quad \text{边界}=(s,\infty).$$

每层恰好 $2^s$ 个对：$Ee+Eu+Ed$ 共 $2^s-1$ 个，加 1 个边界。

---

## 五、相邻对 DP —— 逐步详解

## 问题 1：为什么不能只追踪"单个值"的权值？

回顾发动机公式（奇数情况）：
$$w_s(2u+1)=1+\min\bigl(w_{s-1}(u),\ w_{s-1}(u+1)\bigr).$$

注意 $\min$ 里出现了**两个相邻下标** $u$ 和 $u+1$。

**这意味着**：要算第 $s$ 层的权值，你得知道第 $s-1$ 层里 $u$ 和 $u+1$ **两个**值的权值。它们两个的信息必须同时被保留。

所以状态不能只记"某个 $v$ 的权值"，而必须记**一对相邻值的权值**：
$$(x,\ y)=\bigl(w_s(a),\ w_s(a+1)\bigr).$$

**这就是"相邻对"名字的由来。**

---

## 问题 2：既然差只有 $-1,0,+1$，相邻对只有哪几种？

$(w_s(a),\ w_s(a+1))$ 是两个数，差 $\in\{-1,0,+1\}$。设 $w_s(a)=i$，那么 $w_s(a+1)$ 只能是 $i-1,i,i+1$。

其中 $i-1$ 的情况意味着"先降"——但按 $a$ 从小到大扫描，$w_s(a+1)$ 比 $w_s(a)$ 小 1，这也是允许的。所以严格说有三种非平凡形态：

| 形态 | 记号 | 含义 |
|---|---|---|
| 相等 | $Ee(i)=(i,\ i)$ | 两值权值**相等**，都是 $i$ |
| 上坡 | $Eu(i)=(i,\ i+1)$ | 右边**多 1**（equal→up） |
| 下坡 | $Ed(i)=(i+1,\ i)$ | 右边**少 1**（equal→down） |

**$Ee$ 里的第二个 $e$**：等（equal）。
**$Eu$ 里的 $u$**：上（up）。
**$Ed$ 里的 $d$**：下（down）。

---

## 问题 3：怎么从第 $s$ 层推到第 $s+1$ 层？

用发动机公式：
$$w_{s+1}(2b)=w_s(b),\qquad w_{s+1}(2b+1)=1+\min\bigl(w_s(b),w_s(b+1)\bigr).$$

设 $b$ 这一对是 $(x,y)=(w_s(b),w_s(b+1))$，那么：

- **$a=2b$** 的对 $=\bigl(w_{s+1}(2b),\ w_{s+1}(2b+1)\bigr)=\bigl(x,\ 1+\min(x,y)\bigr)$；
- **$a=2b+1$** 的对 $=\bigl(w_{s+1}(2b+1),\ w_{s+1}(2b+2)\bigr)=\bigl(1+\min(x,y),\ y\bigr)$。

因为 $b$ 遍历 $[0,2^s)$ 时，$2b$ 和 $2b+1$ 恰好覆盖 $[0,2^{s+1})$，每个 $b$ 生成 2 个新对，所以新层恰好 $2^{s+1}$ 个对 ✓。

### 代入三种形态

**源：$Ee(i)$，即 $(x,y)=(i,i)$**：
- $a=2b$：$(i,\ 1+\min(i,i))=(i,\ i+1)=Eu(i)$。
- $a=2b+1$：$(1+\min(i,i),\ i)=(i+1,\ i)=Ed(i)$。

**源：$Eu(i)$，即 $(x,y)=(i,i+1)$**：
- $a=2b$：$(i,\ 1+\min(i,i+1))=(i,\ i+1)=Eu(i)$。
- $a=2b+1$：$(1+\min(i,i+1),\ i+1)=(i+1,\ i+1)=Ee(i+1)$。

**源：$Ed(i)$，即 $(x,y)=(i+1,i)$**：
- $a=2b$：$(i+1,\ 1+\min(i+1,i))=(i+1,\ i+1)=Ee(i+1)$。
- $a=2b+1$：$(1+\min(i+1,i),\ i)=(i+1,\ i)=Ed(i)$。

**源：边界 $(s,\infty)$**：
- $a=2b$：$(s,\ 1+\min(s,\infty))=(s,\ s+1)=Eu(s)$。
- $a=2b+1$：$(1+\min(s,\infty),\ \infty)=(s+1,\ \infty)=$ **新边界 $(s+1)$**。

### 汇总成一张表

| 源形态 | $a=2b$ 生成 | $a=2b+1$ 生成 |
|---|---|---|
| $Ee(i)$ | $Eu(i)$ | $Ed(i)$ |
| $Eu(i)$ | $Eu(i)$ | $Ee(i+1)$ |
| $Ed(i)$ | $Ee(i+1)$ | $Ed(i)$ |
| 边界 $(s,\infty)$ | $Eu(s)$ | 边界 $(s+1)$ |

**这就是全题最核心的转移表。** 记住这张表，DP 就写出来了。

---

## 问题 4：$R$ 的递推怎么来的？

### 思路：按 $v$ 的奇偶拆开

$R(s,k)$ 数的是 $[0,2^s)$ 里权值 $\le k$ 的 $v$ 的个数。按奇偶分类。

### 偶数部分

偶 $v=2u$，$u\in[0,2^{s-1})$。由发动机公式 $w_s(2u)=w_{s-1}(u)$，条件是 $w_{s-1}(u)\le k$。

所以偶数的贡献就是：
$$\boxed{R(s-1,k)}.$$

### 奇数部分

奇 $v=2u+1$，$u\in[0,2^{s-1})$。条件是
$$w_s(2u+1)=1+\min\bigl(w_{s-1}(u),w_{s-1}(u+1)\bigr)\le k,$$
即
$$\min\bigl(w_{s-1}(u),w_{s-1}(u+1)\bigr)\le k-1.$$

**用容斥**：$\min\le k-1$ 等价于"$w(u)\le k-1$ **或** $w(u+1)\le k-1$"。并集大小 $=$ 各自大小之和 $-$ 交集大小：

$$\{u:\min\le k-1\}=\underbrace{\{u:w(u)\le k-1\}}_{A}+\underbrace{\{u:w(u+1)\le k-1\}}_{B}-\underbrace{\{u:\text{两者都}\le k-1\}}_{C}.$$

逐项算：

- **$A$**：$u$ 遍历 $[0,2^{s-1})$，条件 $w_{s-1}(u)\le k-1$，这不就是 $R(s-1,k-1)$ 吗？✓

- **$B$**：$u+1$ 遍历 $[1,2^{s-1}]$，条件 $w_{s-1}(u+1)\le k-1$。
  - $u+1$ 取 $1,2,\dots,2^{s-1}-1$ 时和 $A$ 一样多（去掉 $u+1=0$ 那个）；
  - $u+1=2^{s-1}$ 时 $w=\infty$，不计。
  - 所以 $B=R(s-1,k-1)-[\text{0 那个算不算}]$。$A$ 里含 $u=0$（$w=0\le k-1$ 当 $k\ge1$），$B$ 里没有 $u+1=0$，所以 $B=R(s-1,k-1)-[k\ge1]$。

- **$C$**：下面定义Q来处理。

所以奇数部分：
$$R(s-1,k-1)+\bigl[R(s-1,k-1)-[k\ge1]\bigr]-Q(s-1,k-1).$$

### 合起来

$$R(s,k)=\underbrace{R(s-1,k)}_{\text{偶}}+\underbrace{2R(s-1,k-1)-[k\ge1]-Q(s-1,k-1)}_{\text{奇}}.$$

即：
$$\boxed{\,R(s,k)=R(s-1,k)+2R(s-1,k-1)-[k\ge1]-Q(s-1,k-1).\,}$$

---

## 问题 5：怎么从"对"的计数推出 $R(s,k)$？

### 先定义 $Q$

$$Q(s,k)=\bigl\{a\in[0,2^s):\ w_s(a)\le k\ \text{且}\ w_s(a+1)\le k\bigr\}.$$

**含义**：第 $s$ 层里，**相邻两个权值都 $\le k$** 的对的个数。

### 按形态展开 $Q$

四种形态里：
- $Ee(i)=(i,i)$：两个权值都 $=i$，要求 $i\le k$，贡献 $Ee(i)$；
- $Eu(i)=(i,i+1)$：要求 $i\le k$ **且** $i+1\le k$，即 $i\le k-1$，贡献 $Eu(i)$；
- $Ed(i)=(i+1,i)$：同理要求 $i\le k-1$，贡献 $Ed(i)$；
- 边界 $(s,\infty)$：第二项是 $\infty$，永远不满足。

所以：
$$Q(s,k)=\sum_{i\le k}Ee(i)\ +\ \sum_{i\le k-1}\bigl(Eu(i)+Ed(i)\bigr). {}$$

**实现上**：扫一遍 $Ee$ 和 $(Eu+Ed)$ 的前缀和，就能 $O(1)$ 查 $Q(s,k)$。



---

## 六、实现要点

1. **按 $s$ 分组**：同一 $s$ 的询问共用一次 DP，逐层推到第 $s$ 层时回答。
2. **截断**：转移只把下标往上推，$i>K$ 的形态永远回不到 $\le K$，直接丢。
3. **饱和**：$k\ge s$ 时 $R=2^s$、$U=2^{s+1}-1$，直接 $k\leftarrow\min(k,s)$。
4. 复杂度 $O(\max S\cdot K)\le O(n^2)$，$n=3000$ 跑约 $9\times10^6$ 次，$0.3$ s。

---

## 总结

> **转化** → 带符号子集和；**对称** → $U=2R-1$；**相邻对递推** → $w_s(2u)=w_{s-1}(u)$，$w_s(2u+1)=1+\min(\cdot)$；**题眼** → 相邻差 $\in\{-1,0,+1\}$，所以只追 3 种对 + 1 个边界；**递推** → $R(s,k)=R(s-1,k)+2R(s-1,k-1)-[k\ge1]-Q(s-1,k-1)$，$O(n^2)$ 收工。

## AC代码:


```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;

    vector<int> qs(T), qk(T);
    int maxS = 0;
    static char buf[3005];
    for(int i = 0; i < T; i++){
        int n, k;
        cin >> n >> k >> buf;
        int s = 0;
        while(s < n && buf[n - 1 - s] == '0') s++; 
        qs[i] = s;
        qk[i] = min(k, s);             
        if(s > maxS) maxS = s;
    }
    int K = 0;
    for(int i = 0; i < T; i++) if(qk[i] > K) K = qk[i];
    vector<vector<pair<int,int>>> byS(maxS + 1);
    for(int i = 0; i < T; i++) byS[qs[i]].push_back({qk[i], i});

    vector<ll> ans(T, 0);

    // level-0 state
    vector<ll> Ee(K+2,0), Eu(K+2,0), Ed(K+2,0);
    vector<ll> R(K+1, 1);            // R(0,k) = 1
    vector<ll> A(K+1), B(K+1);
    vector<ll> nR(K+1), nEe(K+2), nEu(K+2), nEd(K+2);

    auto answerAt = [&](int s){
        for(auto &pr : byS[s]){
            int k = pr.first, idx = pr.second;
            ans[idx] = (2 * R[k] % MOD - 1 + MOD) % MOD;
        }
    };

    answerAt(0);

    for(int s = 0; s < maxS; s++){
        ll acc = 0, accb = 0;
        for(int i = 0; i <= K; i++){
            acc = (acc + Ee[i]) % MOD;
            A[i] = acc;
            accb = (accb + Eu[i] + Ed[i]) % MOD;
            B[i] = accb;
        }
        // R'(k) = R(k) + 2R(k-1) - [k>=1] - A(k-1) - B(k-2)
        for(int k = 0; k <= K; k++){
            ll v = R[k];
            if(k >= 1){
                v = (v + 2 * R[k-1]) % MOD;
                v = (v - 1 + MOD) % MOD;
                v = (v - A[k-1] + MOD) % MOD;
                if(k >= 2) v = (v - B[k-2] + MOD) % MOD;
            }
            nR[k] = v;
        }
        R.swap(nR);
        fill(nEe.begin(), nEe.end(), 0);
        fill(nEu.begin(), nEu.end(), 0);
        fill(nEd.begin(), nEd.end(), 0);
        for(int i = 0; i <= K; i++){
            ll e = Ee[i], u = Eu[i], d = Ed[i];
            if(e){
                nEu[i] = (nEu[i] + e) % MOD;
                nEd[i] = (nEd[i] + e) % MOD;
            }
            if(u){
                nEu[i] = (nEu[i] + u) % MOD;
                if(i+1 <= K) nEe[i+1] = (nEe[i+1] + u) % MOD;
            }
            if(d){
                if(i+1 <= K) nEe[i+1] = (nEe[i+1] + d) % MOD;
                nEd[i] = (nEd[i] + d) % MOD;
            }
        }
        if(s <= K) nEu[s] = (nEu[s] + 1) % MOD;
        Ee.swap(nEe); Eu.swap(nEu); Ed.swap(nEd);

        answerAt(s + 1);
    }

    for(int i = 0; i < T; i++) cout << ans[i] << '\n';
    return 0;
}

```

### Deepseek进行了写作和Markdown规范以及LateX公式的辅助