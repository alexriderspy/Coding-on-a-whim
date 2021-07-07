#include<bits/stdc++.h>

using namespace std;

const int inf=1e7;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n,0);
    for(auto &x:coins) cin>>x;
    vector<int>num(x+1,inf);
    num[0]=0;
    for(int j=0;j<=x;j++){
        for(auto coin:coins){
            if(j+coin<=x)
            num[j+coin]=min(num[j]+1,num[j+coin]);
        }
    }
    if(num[x]<1e7)
    cout<<num[x] <<'\n';
    else
    cout<<-1<<'\n';

}