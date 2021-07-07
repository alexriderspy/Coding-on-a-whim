#include<bits/stdc++.h>

using namespace std;
//geometry template
struct P{
    int x,y;
    void read(){
        cin>>x>>y;
    }
    //last const to tell compiler not to change the value
    P operator - (const P &b) const {
        return P{x-b.x,y-b.y};
    }
    //use const not to copy the value
    void operator -= (const P& b) const{
        x-=b.x;
        y-=b.y;
    }
    //also define * operator on points
    long long int operator * (const P& b) const {
        return ((long long)x*b.y - (long long)y*b.x);
    }
};
void solve(){
    P p1,p2,p3;
    p1.read(),p2.read(),p3.read();
    p2=p2-p1;
    p3=p3-p1;
    //p2-=p1,p3-=p1
    long long cross_prod=p3*p2;
    if(cross_prod<0) cout<<"LEFT\n";
    else if(cross_prod>0) cout<<"RIGHT\n";
    else cout<<"TOUCH\n";   
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}