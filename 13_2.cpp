#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f;

int main() {
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    long long ans = 0;
    while(cin.peek()!=EOF){
        for(int i=0;i<3;i++){
            string s;
            getline(cin, s);
            stringstream ss(s);
            char c;
            if(i==0){
                ss>>s>>s;
                ss>>c>>c;
                ss>>a;
                ss>>c;
                ss>>c>>c;
                ss>>d;
            }else if(i==1){
                ss>>s>>s;
                ss>>c>>c;
                ss>>b;
                ss>>c;
                ss>>c>>c;
                ss>>e;
            }else{
                ss>>s;
                ss>>c>>c;
                ss>>::c;
                ss>>c>>c>>c;
                ss>>f;
            }
        }cin.ignore();cin.ignore();
        c+=10000000000000;
        f+=10000000000000;
        long long x,y;
        y = (f*a - c*d)/(e*a - b*d);
        x = (c - y*b)/a;
        if((f*a - c*d)%(e*a - b*d)!=0) continue;
        if((c - y*b)%a!=0) continue;

        ans+= 3*x + y;
    }cout<<ans;
}
