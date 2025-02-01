#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    int cnt=0;
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        int pre = -1;
        int k;
        int error = 0;
        bool ok = 0;
        vector<int> a;
        a.clear();
        while(ss>>k){
            a.push_back(k);
        }
        vector<int> er(a.size());
        // xet di len
        for(int i=0;i<a.size();i++){
            if(pre==-1) pre = a[i] - 1;
            if(!(a[i]>pre && abs(a[i]-pre)>=1&&abs(a[i]-pre)<=3)) er[i] = 1;
            else er[i]=0;
            error += er[i];
            pre = a[i];
        }
        int _error = error;
        for(int i=0;i<a.size();i++){
            error -= er[i];
            if(i<a.size()-1){
                error -= er[i+1];
                if(i>0) error += (a[i+1]<a[i-1] || abs(a[i+1]-a[i-1]) <1 || abs(a[i+1]-a[i-1]) > 3);

            }
            if(error==0) ok = 1;
            error = _error;
        }

        pre = -1;
        error = 0;
        for(int i=0;i<a.size();i++){
            if(pre==-1) pre = a[i] + 1;
            if(!(a[i]<pre && abs(a[i]-pre)>=1&&abs(a[i]-pre)<=3)) er[i] = 1;
            else er[i] = 0;
            error += er[i];
            pre = a[i];
        } _error = error;
        for(int i=0;i<a.size();i++){
            error -= er[i];
            if(i<a.size()-1){
                error -= er[i+1];
                if(i>0)error += (a[i+1]>a[i-1] || abs(a[i+1]-a[i-1]) <1 || abs(a[i+1]-a[i-1]) > 3);
            }
            if(error==0) ok = 1;
            error = _error;
        }
        cnt+=ok;
    }
    cout<<cnt;
}
