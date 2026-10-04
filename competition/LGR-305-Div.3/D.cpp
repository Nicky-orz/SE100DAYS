#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 思路：答案只依赖 tz(x)=s 和 k；用相邻对 DP 逐层推进，每层回答对应的询问
// 难点：
//1.引入最少操作次数w，把y的存在性 → 项数最小值，找递推，进而想到相邻对DP；
//2.相邻对存项数下，有多少个合法的对
//3.相邻权值差只有-1，0，+1，分奇偶，从而得到三种相邻对及其转移方程；
//4.R(s,k) 数的是 ws(v)≤k的 v个数
const ll MOD = 1000000007LL;

int main(){
    ios::sync_with_stdio(false);        // 关闭 cin/cout 与 stdio 同步，加速读入
    cin.tie(nullptr);                   // 解除 cin 与 cout 的绑定，避免每次输出都 flush

    int T;
    if(!(cin >> T)) return 0;           // 读入询问组数，读失败则直接退出

    vector<int> qs(T), qk(T);           // qs[i]: 第 i 组询问的 s=tz(x)；qk[i]: 截断后的 k
    int maxS = 0;                       // 所有询问中最大的 s，决定 DP 要推进多少层
    static char buf[3005];              // 二进制串缓冲区（n<=3000）
    for(int i = 0; i < T; i++){
        int n, k;
        cin >> n >> k >> buf;           // 读入 n, k 和二进制串
        int s = 0;
        while(s < n && buf[n - 1 - s] == '0') s++;   // 从右往左数末尾 0 的个数 = tz(x)
        qs[i] = s;                      // 记下这一组询问的 s
        qk[i] = min(k, s);              // k>=s 时答案饱和为 2^{s+1}-1，截断 k 到 s 节省空间
        if(s > maxS) maxS = s;          // 更新最大的 s
    }
    int K = 0;                          // 所有询问中截断后最大的 k，决定 DP 的 k 维度
    for(int i = 0; i < T; i++) if(qk[i] > K) K = qk[i];

    // 把询问按 s 分组：推进到第 s 层时，一次性回答所有 s 相同的询问
    vector<vector<pair<int,int>>> byS(maxS + 1);   // byS[s] = {(k, 原询问下标), ...}
    for(int i = 0; i < T; i++) byS[qs[i]].push_back({qk[i], i});

    vector<ll> ans(T, 0);               // 存放每组询问的最终答案

    // ===== 第 0 层状态 =====
    // s=0 时只允许位置集合为空，只有 v=0 可表示，w_0(0)=0
    vector<ll> Ee(K+2,0), Eu(K+2,0), Ed(K+2,0);  // 三种相邻对形态的计数（第0层全0）
    vector<ll> R(K+1, 1);               // R(0,k) = 1（只有 v=0 一个值，对任意 k>=0 都满足）
    vector<ll> A(K+1), B(K+1);          // 前缀和缓存：A(k)=sum_{i<=k}Ee(i)，B(k)=sum_{i<=k}(Eu(i)+Ed(i))
    vector<ll> nR(K+1), nEe(K+2), nEu(K+2), nEd(K+2);  // 下一层的缓存（滚动数组）

    // 回答 s 这一层的所有询问：答案 U(s,k) = 2·R(s,k) - 1
    auto answerAt = [&](int s){
        for(auto &pr : byS[s]){
            int k = pr.first, idx = pr.second;    // k 是截断后的，idx 是原询问下标
            ans[idx] = (2 * R[k] % MOD - 1 + MOD) % MOD;   // 对称性：U = 2R - 1
        }
    };

    answerAt(0);                        // 先回答 s=0 的所有询问

    // ===== 逐层推进：从第 s 层推到第 s+1 层 =====
    for(int s = 0; s < maxS; s++){
        // ---- 步骤 1：用第 s 层的 Ee/Eu/Ed 算前缀和 A, B ----
        // Q(s,k) = A(k) + B(k-1)，其中 A(k)=sum_{i<=k}Ee(i)，B(k)=sum_{i<=k}(Eu(i)+Ed(i))
        ll acc = 0, accb = 0;
        for(int i = 0; i <= K; i++){
            acc = (acc + Ee[i]) % MOD;      // A(i) = A(i-1) + Ee(i)
            A[i] = acc;                     // 存下 A(i)
            accb = (accb + Eu[i] + Ed[i]) % MOD;   // B(i) = B(i-1) + Eu(i) + Ed(i)
            B[i] = accb;                    // 存下 B(i)
        }

        // ---- 步骤 2：用递推式算下一层的 R ----
        // R(s,k) = R(s-1,k) + 2R(s-1,k-1) - [k>=1] - Q(s-1,k-1)
        // Q(s-1,k-1) = A(k-1) + B(k-2)
        for(int k = 0; k <= K; k++){
            ll v = R[k];                    // 先取 R(s-1,k) 项
            if(k >= 1){
                v = (v + 2 * R[k-1]) % MOD;              // 加 2R(s-1,k-1)
                v = (v - 1 + MOD) % MOD;                 // 减 [k>=1]
                v = (v - A[k-1] + MOD) % MOD;            // 减 Q 中的 Ee 前缀和
                if(k >= 2) v = (v - B[k-2] + MOD) % MOD; // 减 Q 中的 (Eu+Ed) 前缀和
            }
            nR[k] = v;                      // 写入下一层
        }
        R.swap(nR);                         // 滚动：新层成为当前层

        // ---- 步骤 3：用转移表把相邻对形态推到下一层 ----
        // 转移表：
        //   Ee(i) --a=2b-->   Eu(i)；   --a=2b+1--> Ed(i)
        //   Eu(i) --a=2b-->   Eu(i)；   --a=2b+1--> Ee(i+1)
        //   Ed(i) --a=2b--> Ee(i+1)；   --a=2b+1--> Ed(i)
        //   边界(s,∞) --a=2b--> Eu(s)； --a=2b+1--> 边界(s+1)
        fill(nEe.begin(), nEe.end(), 0);    // 清空下一层缓存
        fill(nEu.begin(), nEu.end(), 0);
        fill(nEd.begin(), nEd.end(), 0);
        for(int i = 0; i <= K; i++){        // 只处理 i<=K 的部分，i>K 永远不会回流到 <=K
            ll e = Ee[i], u = Eu[i], d = Ed[i];   // 取出第 s 层的三种形态计数
            // Ee(i) -> Eu(i), Ed(i)
            if(e){
                nEu[i] = (nEu[i] + e) % MOD;        // Ee(i) 的 a=2b 分支贡献给 Eu(i)
                nEd[i] = (nEd[i] + e) % MOD;        // Ee(i) 的 a=2b+1 分支贡献给 Ed(i)
            }
            // Eu(i) -> Eu(i), Ee(i+1)
            if(u){
                nEu[i] = (nEu[i] + u) % MOD;        // Eu(i) 的 a=2b 分支贡献给 Eu(i)
                if(i+1 <= K) nEe[i+1] = (nEe[i+1] + u) % MOD;   // a=2b+1 分支贡献给 Ee(i+1)
            }
            // Ed(i) -> Ee(i+1), Ed(i)
            if(d){
                if(i+1 <= K) nEe[i+1] = (nEe[i+1] + d) % MOD;   // Ed(i) 的 a=2b 分支贡献给 Ee(i+1)
                nEd[i] = (nEd[i] + d) % MOD;        // a=2b+1 分支贡献给 Ed(i)
            }
        }
        // 边界对 (s, ∞)：a=2b 时变成 Eu(s)，a=2b+1 时变成新的边界 (s+1, ∞)（边界不参与 Q 计算，丢弃）
        if(s <= K) nEu[s] = (nEu[s] + 1) % MOD;
        Ee.swap(nEe); Eu.swap(nEu); Ed.swap(nEd);   // 滚动：新层成为当前层

        answerAt(s + 1);                    // 回答 s+1 层的所有询问
    }

    for(int i = 0; i < T; i++) cout << ans[i] << '\n';   // 按原顺序输出答案
    return 0;
}