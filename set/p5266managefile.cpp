#include<bits/stdc++.h>
using namespace std;
map <string ,int> file;
int main(){
    int q,n=0;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        switch(op){
            case 1:{
                string name;
                int score;
                cin>>name>>score;
                file[name] = score;
                cout<<"OK\n";
                break;
            }
            case 2:{
                string name;
                cin>>name;
                if(file.count(name))
                    cout<<file[name]<<"\n";
                else 
                    cout<<"Not found\n";
                break;
            }
            case 3:{
                string name;
                cin>>name;
                if(file.count(name)){
                    file.erase(name);
                    cout<<"Deleted successfully\n";
                }
                else
                    cout<<"Not found\n";
                break;
            }
            case 4:{
                cout<<file.size()<<"\n";
                break;
            }
        }
    }
    return 0;
}