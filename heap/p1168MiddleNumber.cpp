#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n;
int h[maxn];

priority_queue <int> maxheap;
priority_queue <int, vector<int>, greater<int>> minheap;

void balance(int x){
    while (!minheap.empty() && (int) maxheap.size() < x) {
        maxheap.push(minheap.top());
        minheap.pop();
    }
    while ( (int) maxheap.size() > x) {
        minheap.push(maxheap.top());
        maxheap.pop();
    }
}


void insert(int num) {
    int x = maxheap.size();
    if (maxheap.empty() || num < maxheap.top())
        maxheap.push(num);
    else
        minheap.push(num);
    balance(x);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        int t;
        cin >> t;
        insert(t);
        if (i % 2 == 1) {
            balance((i + 1) / 2);
            cout << maxheap.top() << "\n";
        }
    }

    return 0;
}