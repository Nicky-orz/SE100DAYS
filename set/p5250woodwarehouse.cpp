#include<bits/stdc++.h>
using namespace std;
set <int> s;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int order,wood;
        cin>>order>>wood;
        if(order == 1){
            if(!s.count(wood))
                s.insert(wood);
            else    
                cout<<"Already Exist"<<endl;
        }
            
        if(order == 2){
            if(s.empty()){
                cout<<"Empty"<<endl;
                continue;
            }
            auto ans = s.lower_bound(wood);
            if(ans == s.end()){
                ans--;
                cout<<*ans<<endl;
                s.erase(ans);
                continue;
            }
            if(*ans == wood){
                cout<<wood<<endl;
                s.erase(ans);
            }
            else{
                if(ans == s.begin()){
                    cout<<*ans<<endl;
                    s.erase(ans);
                    continue;
                }
                auto next = ans;
                auto last = --ans;
                if(wood - *last <= *next - wood){
                    cout<<*last<<endl;
                    s.erase(last);
                }
                else{
                    cout<<*next<<endl;
                    s.erase(next);
                }
            }
        }
    }
    return 0;
}