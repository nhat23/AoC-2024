#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int tmp;

int consecutive_number(string s, int pos, char schr){
    tmp = 0;
    string ttmp = "";
    int ans = -1;
    while(pos<s.length()&&s[pos]-'0'>=0 && '9' - s[pos] >=0){
        ttmp+=s[pos];
        pos++;
        ans=pos;
    }
    if(ans==-1) return ans;
    tmp = stoi(ttmp);
    if(pos<s.length()) if(s[pos] == schr) ans++; else ans = -1;

    return ans;
}

int val(string s){
    int res = 0;
    for(int i=0;i<s.length();i++){
        if(s.substr(i,4)=="mul("){
            int ii=consecutive_number(s,i+4,',');
            if(ii!=-1){
                int a = tmp;
                int iii = consecutive_number(s,ii,')');
                if(iii!=-1){
                    int b = tmp;
                    res+= a*b;
                }
            }
        }
    }return res;
}

int main() {
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    string s;
    while(getline(cin,s)){
        cnt+=val(s);
    }
    cout<<cnt;
}
