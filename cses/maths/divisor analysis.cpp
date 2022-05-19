#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    int x=1,sum=1,num=1;
    vector<pair<int,int>>p(n);
    for(int i=0;i<n;++i){
        cin>>p[i].first>>p[i].second;
        x*=(pow(p[i].first,p[i].second));
        num*=(p[i].second+1);
        sum*=(pow(p[i].first,p[i].second+1)-1)/(p[i].first-1);
    }

    cout<<num<<' '<<sum<<' ';

}