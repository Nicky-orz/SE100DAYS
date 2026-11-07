#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;

vector <int> ord; 

int GetRank(int x) {
    cout << "?" << x;
    for (int i : ord)
        cout << " " << i;
    cout << " " << x << endl;
    int t;
    cin >> t;
    return t;

}

int main(){
    int n, k;
    cin >> n >> k;
    ord.push_back(1);
    for (int i = 2; i <= n; i++){
        int rank = GetRank(i);
        ord.insert(ord.begin() + rank - 1, i);
    }
    int ans[maxn];
    for (int i = 0; i < n; i++)
        ans[ord[i]] = i + 1;
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << ans[i];
    return 0;
}