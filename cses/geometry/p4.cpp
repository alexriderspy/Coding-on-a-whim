#include<bits/stdc++.h>

using namespace std;

struct P{
    long long x,y;
    void read(){
        cin>>x>>y;
    }
    //last const to tell compiler not to change the value
    P operator - (const P &b) const {
        return P{x-b.x,y-b.y};
    }
    //use const not to copy the value
    void operator -= (const P& b) {
        x-=b.x;
        y-=b.y;
    }
    void operator += (const P& b){
        x+=b.x;
        y+=b.y;
    }
    
    //also define * operator on points
    long long operator * (const P& b) const {
        return (x*b.y - y*b.x);
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<P>polygon(n);
    for(P &p:polygon){
        p.read();
    }
    while(m--){
        P p;
        p.read();
        
    }
}