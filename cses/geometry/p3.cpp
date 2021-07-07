#include<bits/stdc++.h>

using namespace std;

//simple polygon doesnt mean it will be convex always, can be concave too
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
    int n;cin>>n;
    vector<P>v;
    for(int i=0;i<n;i++){
        P p;
        p.read();
        v.push_back(p);
    }
    
    for(int i=1;i<n;i++){
        v[i]-=v[0];
    }
    long long a2=0;
    for(int i=2;i<n;i++){
        a2+=(v[i]*v[i-1]);
    }

    cout<<(a2<0?-a2:a2)<<'\n';
}