#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans = 0;
bool ok = 0;
ll n;
vector<ll> a;

ll concat(ll a, ll b){
    ll tmp = b;
    while(tmp>0){
        tmp/=10;
        a*=10;
    }return a+b;
}

void check(ll id, ll cur, ll acv){
    if(ok) return;
    if(id==n||cur>acv){
        if(cur==acv) ok = 1;
        return;
    }
    if(id==0){
        check(id+1,a[id],acv);
    }else{
        check(id+1,cur+a[id],acv);
        check(id+1,cur*a[id],acv);
        check(id+1,concat(cur,a[id]),acv);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    string s;
    while(getline(cin,s)){
        ok = 0;
        stringstream ss(s);
        string tmp;
        getline(ss,tmp,':');
        ll req = stoll(tmp);
        ll t;
        a.clear();
        while(ss>>t) a.push_back(t);
        n=a.size();
        check(0,0,req);
        if(ok) ans+= req;

    }cout<<ans<<endl;
}
