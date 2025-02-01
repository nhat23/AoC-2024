#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
string s[10000];
int n,m;

int check(int x, int y){
    string c = "XMAS", cc= "SAMX";
    string v,h,d1,d2;
    int res = 0;
    if(y+3<m)
        for(int j = y;j<y+4;j++){
            h+=s[x][j];
        }
    if(x+3<m)
        for(int i = x;i<x+4;i++){
            v+=s[i][y];
        }
    if(y+3<m && x+3<n)
        for(int j = y, i = x;(j<y+4)&&(i<x+4);j++,i++){
            d1+=s[i][j];
        }
    if(y-3>=0 && x+3<n)
        for(int j = y, i = x;(j>y-4)&&(i<x+4);j--,i++){
            d2+=s[i][j];
        }
    if(h==c||h==cc) res++;
    if(v==c||v==cc) res++;
    if(d1==c||d1==cc) res++;
    if(d2==c||d2==cc) res++;
    return res;
}

int main() {
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    n = 0;
    while(getline(cin,s[n++]));
    n--;
    m = s[0].length();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            ans+=check(i,j);
        }
    cout<<ans;
}
