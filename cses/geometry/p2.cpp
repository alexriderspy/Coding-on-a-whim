#include<bits/stdc++.h>

using namespace std;
//geometry template
#define ll long long

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
    void operator -= (const P& b) {
        x-=b.x;
        y-=b.y;
    }
    void operator += (const P& b){
        x+=b.x;
        y+=b.y;
    }
    
    //also define * operator on points
    long long int operator * (const P& b) const {
        return ((long long)x*b.y - (long long)y*b.x);
    }
};

void solve(){
    P p1,p2,p3,p4;
    p1.read(),p2.read(),p3.read(),p4.read();

    if((p4-p3)*(p2-p1)==0){
        //cross product ==0 ?
        if(((p3-p1)*(p2-p1))!=0){
            cout<<"NO\n"; return;
        }
        //now when 2 segments are on the same line but they dont intersect
        for(int i=0;i<2;i++){
            //what if they have same x coordinate XD
            if(max(p1.x,p2.x) < min(p3.x,p4.x) || max(p1.y,p2.y) < min(p3.y,p4.y)){
                cout<<"NO\n";return;
            }
            swap(p1,p3);
            swap(p2,p4);
        }
    }
    for(int i=0;i<2;i++){
        ll sign1=(p1-p3)*(p4-p3);
        ll sign2=(p2-p3)*(p4-p3);

        if((sign2>0 && sign1>0) ||(sign2<0 && sign1<0)){
            cout<<"NO\n";return;
        }
        swap(p1,p3);swap(p2,p4);
    }
//we need to do parallel cases separately
//since in parallel, if we look at B from a point on A 
//such that B extends in both directions then we have
//opposite sign yet we have a correct case 
    cout<<"YES\n";
}   
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}