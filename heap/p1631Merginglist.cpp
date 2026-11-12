#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100005;

priority_queue <ll> max_pq; 
priority_queue <ll, vector<ll>, greater<ll>> min_pq; 
unordered_map <ll, ll> max_deleted, min_deleted;
int totalsize;

void clean() {
    while (!max_pq.empty() && max_deleted[max_pq.top()] > 0) {
        max_deleted[max_pq.top()]--;
        max_pq.pop();
    }
    while (!min_pq.empty() && min_deleted[min_pq.top()] > 0) {
        min_deleted[min_pq.top()]--;
        min_pq.pop();
    }
}

void insert(ll x) {
    max_pq.push(x);
    min_pq.push(x);
    totalsize++;
}

void pop_min() {
    clean(); 
    if (!min_pq.empty()) {
        max_deleted[min_pq.top()]++;
        min_pq.pop();
        totalsize--;
    }
}

ll get_min() {
    clean();
    return min_pq.top();
}

ll get_max() {
    clean(); 
    return max_pq.top();
}

void pop_max() {
    clean();
    if (!max_pq.empty()) {
        min_deleted[max_pq.top()]++;
        max_pq.pop();
        totalsize--;
    }
}

int n;
int a[maxn], b[maxn];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (totalsize < n || a[i] + b[j] < get_max())
                insert(a[i] + b[j]);
            else break;
            while (totalsize > n)
                pop_max();
        }
    }
    while (totalsize > 0) {
        cout << get_min() << " ";
        pop_min();
    }
    return 0;
}
//这题标准做法是多路归并