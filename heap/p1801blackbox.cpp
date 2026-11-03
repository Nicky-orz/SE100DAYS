#include<bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n,m;
int a[maxn];
int t[maxn];
priority_queue <int, vector<int>, greater<int>> minheap;
priority_queue <int> maxheap;

int main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>t[i];
    sort(t,t+n);
    for(int i=0, j=0;i<n && j<m;j++){
        if(maxheap.empty() || a[j] < maxheap.top()){
            maxheap.push(a[j]);
            int tmax = maxheap.top();
            maxheap.pop();
            minheap.push(tmax);
        }
        else{
            minheap.push(a[j]);
        }

        while((int)maxheap.size() < i+1 && !minheap.empty()){
            maxheap.push(minheap.top());
            minheap.pop();
        }

        while(i < n && j+1 == t[i]){
            if(!maxheap.empty()) cout<<maxheap.top()<<endl;
            else cout<<"Error\n";
            i++;
            if(!minheap.empty()){
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
    }
    return 0;
}