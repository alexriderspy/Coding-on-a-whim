#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
const int LOG = 31;

int down[LOG][N];

int main(){
    int a,n,q;cin>>n>>q;
    
    for(int i=1;i<=n;++i){
        cin>>a;
        down[0][i]=(a);
    }
    for(int i=1;i<LOG;++i){
        for(int j=1;j<=n;++j){
            down[i][j]=down[i-1][down[i-1][j]];
        }
    }
    while(q--){
        int x,k;
        cin>>x>>k;
        int val=(x);
        for(int i=0;i<LOG;++i){
            if(k&(1<<i)){
                val=down[i][val];
            }
        }
        if(val==0){
            cout<<-1<<'\n';
        }else cout<<val<<'\n';
    }
}