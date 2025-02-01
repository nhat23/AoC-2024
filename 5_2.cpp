#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int apr[10000];
vector<int> req[10000];
string s;
bool ok;
void fix(vector<int> &q, int &i, int k){
    int swp = 100000;
    for(int ii:req[i]) if(apr[ii]!=-1){
        ok = false;
        swp = min(swp,apr[ii]);
    }
    if(swp!=100000){
        apr[i] = swp;
        apr[q[swp]] = k;
        swap(i,q[swp]);
        fix(q,i,k);
    }else apr[i]=k;
}

int main() {
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    int a,b;
    memset(apr, -1, 10000*sizeof(int));
    while(scanf("%d|%d",&a,&b)){
        req[a].push_back(b);
    }
    cin.ignore();
    while(true){

        vector<int> q;
        q.clear();
        getline(cin,s);
        stringstream ss(s);
        while(getline(ss,s,',')){
            if(s=="") break;
            q.push_back(stoi(s));
        }
        if(q.size()==0) break;

        ok = true;
        int k = 0;
        for(int &i:q){
            fix(q,i,k);
            k++;
        }
        for(int i:q) apr[i] = -1;
        if(!ok) ans+=q[q.size()/2];
    }
    cout<<ans;
}
