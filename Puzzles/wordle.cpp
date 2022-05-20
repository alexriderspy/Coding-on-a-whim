#include<iostream>

using namespace std;

int main(){
    string s="maove";
    for(int i=0;i<26;++i){
        s[0]='a'+i;
        if(s[0]=='a' || s[0]=='c' || s[0]=='d' ) continue;
        for(int j=0;j<26;++j){
            s[1]='a'+j;
            if(s[1]=='a' || s[1]=='r' || s[1]=='b' ||s[1]=='e') continue;

            for(int k=0;k<26;++k){
                s[3]='a'+k;
                if(s[3]=='n' || s[3]=='v' || s[3]=='c' ||s[3]=='d') continue;
                cout<<s<<'\n';     
            }
              
        }
    }
}