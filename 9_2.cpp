#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans = 0;
vector<ll> f,e;
vector<pair<ll,ll>> req[20005];


struct segmentTree {
    ll n, t[4*20004];

    segmentTree(){

    }
    void build(vector<ll> a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(a, v*2+1, tl, tm);
            build(a, v*2+2, tm+1, tr);
            t[v] = max(t[v*2+1] , t[v*2+2]);
        }
    }

    ll getmax(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        ll tm = (tl + tr) / 2;
        return max(getmax(v*2+1, tl, tm, l, min(r, tm))
               ,getmax(v*2+2, tm+1, tr, max(l, tm+1), r));
    }

    void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2+1, tl, tm, pos, new_val);
            else
                update(v*2+2, tm+1, tr, pos, new_val);
            t[v] = max(t[v*2+1],t[v*2+2]);
        }
    }
};

segmentTree fen;

ll bs(ll l, ll r, ll x){
    ll res = -1;
    while(l<=r){
        ll m = (l+r)>>1;
        ll mx = fen.getmax(0,0,e.size()-1,0,m);
        if(mx>=x){
            res=m;
            r=m-1;
        }else l=m+1;
    }return res;
}

void print(){
    int i=0;
    while(i<f.size()){
        for(int fi=0;fi<f[i];fi++){
            cerr<<i;
        }
        for(auto ii:req[i]){
            for(int fi=0;fi<ii.second;fi++)
                cerr<<ii.first;
        }
        for(int ei=0;ei<e[i];ei++)
            cerr<<'.';
        i++;
    }cerr<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    char c;
    ll id = 0;
    while(cin>>c){
        if(id==0) f.push_back(c-'0');
        else e.push_back(c-'0');
        id = (id+1)%2;
    }
    fen.build(e,0,0,e.size()-1);
    for(ll f_end = f.size() - 1;f_end>=0;f_end--){
        ll pos = bs(0,f_end-1,f[f_end]);
        if(pos==-1) continue;
        fen.update(0,0,e.size()-1,pos,e[pos]-f[f_end]);
        e[pos]-=f[f_end];
        req[pos].push_back({f_end,f[f_end]});
        if(f_end>0) e[f_end-1] += f[f_end];
        f[f_end] = 0;

    }
    id = 0;
    for(ll fi = 0;fi<f.size();fi++){
        ans+=fi*(id*f[fi]+(f[fi]*(f[fi]-1))/2);
        id+=f[fi];
        for(auto i:req[fi]){
            ans+=i.first*(id*i.second+(i.second*(i.second-1))/2);
            id+=i.second;
        }id+=e[fi];
    }
    cout<<ans<<endl;
}
