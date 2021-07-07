#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll L(ll x,ll y,ll x1,ll y1, ll x2,ll y2){
    return ((y-y1)*(x2-x1) - (y2-y1)*(x-x1));
}
void solve(){
    ll x1,y1,x2,y2;
    ll x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(L(x3,y3,x1,y1,x2,y2)==0) cout<<"TOUCH\n";
    else{
        //shifting origin to p1
        x3=x3-x1,y3=y3-y1,x2=x2-x1,y2=y2-y1;
        //check sign of y3x2-x3y2
        if(y3*x2-x3*y2>0){
            cout<<"LEFT\n";

        }else cout<<"RIGHT\n";
    }
}
int main(){
    int t;cin>>t;
    while(t--) solve();
}