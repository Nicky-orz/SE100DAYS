#include <bits/stdc++.h>
using namespace std;
int C[27][27];
void init(){
    for(int i=0;i<=26;i++){
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}
int main() {
    init();
    string s;
    cin>>s;
    int L = s.size();
    if(L < 1 || L > 6) { cout << 0; return 0; }
    for(char c : s)
        if(c < 'a' || c > 'z') { cout << 0; return 0; }
    for(int i=1;i<L;i++)
        if(s[i] <= s[i-1]){cout << 0; return 0; }
    long long ans = 0;
    for(int len=1;len<L;len++)
        ans += C[26][len];
    int prev = 0;
    for (int i=0;i<L;i++) {
        int cur = s[i] - 'a' + 1;
        int rem = L-i-1;
        for (int x=prev+1;x<cur;x++) {
            ans += C[26 - x][rem];
        }
        prev = cur;
    }
    cout<<ans+1;
    return 0;
}