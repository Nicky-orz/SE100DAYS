#include <bits/stdc++.h>
using namespace std;

char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd()
{
	int x=0,f=1;
	char ch=nc();
	while(ch<48||ch>57)
	{
		if(ch=='-')
			f=-1;
		ch=nc();
	}
	while(ch>=48&&ch<=57)
		x=x*10+ch-48,ch=nc();
	return x*f;
}

typedef long long ll;
const int maxm = 1000005;

int m,n;
vector <ll> collected;
int f[maxm];
int a[maxm];

priority_queue <int> max_pq; 
priority_queue <int, vector<int>, greater<int>> min_pq; 
unordered_map <int, int> max_deleted, min_deleted;
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

void insert(int x) {
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

int get_max() {
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

void add(int x) {
    if (x == 0) return;
    insert(a[x]);
    if (totalsize > n) pop_min();
    add(f[x]);
}

void collect() {
    if (totalsize > 0){
        collected.push_back(get_max());
        pop_max();
    }
    else {
        collected.push_back(0);
    }
}

int main() {
    m = rd(); n = rd();
    for (int i = 1; i <= m; i++)
        f[i] = rd();
    for (int i = 1; i <= m; i++)
        a[i] = rd();
    while (n--) {
        int op = rd();
        if (op == 1)
            add(rd());
        if (op == 2)
            collect();
    }
    ll ans = collected[0];
    for (int i = 1; i < (int)collected.size(); i++){
        ans = ans ^ ((i + 1) * collected[i]);
    }
    printf("%lld", ans);
    return 0;
}