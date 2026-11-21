#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
ll n, g, u;
ll *a;
ll **group;
ll *cnt;
bool *ingroup;
int main() {
    scanf("%lld %lld %lld", &n, &g, &u);
    a = malloc((n + 1) * sizeof(ll));
    ingroup = calloc((n + 1), sizeof(bool));
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    cnt = malloc((g + 1) * sizeof(ll));
    group = malloc((g + 1) * sizeof(ll));
    for (int i = 1; i <= g; i++) {
        scanf("%lld", &cnt[i]);
        group[i] = malloc((cnt[i] + 1) * sizeof(ll));
        for (int j = 1; j <= cnt[i]; j++) {
            scanf("%lld", &group[i][j]);
            ingroup[group[i][j]] = true;
        }
    }
    for (int i = 1; i <= u; i++) {
        ll A, b, c;
        scanf("%lld %lld %lld", &A, &b, &c);
        a[group[A][b]] += c;
        if (a[group[A][b]] > 1e9) a[group[A][b]] = 1e9;
        if (a[group[A][b]] < 0) a[group[A][b]] = 0;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        if (ingroup[i]) sum += a[i];
    printf("%lld\n", sum);
    for (int i = 1; i <= g; i++) {
        ll Gsum = 0;
        ll Gmax = -1;
        ll maxid = 0;
        for (int j = 1; j <= cnt[i]; j++) {
            Gsum += a[group[i][j]];
            if (a[group[i][j]] > Gmax) Gmax = a[group[i][j]], maxid = group[i][j];
        }
        printf("%lld %lld\n", Gsum, maxid);
    }
    return 0;
}