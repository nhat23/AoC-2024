#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans = 0;
string f,e;
vector<pair<ll,ll>> req;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    char c;
    ll id = 0;
    while(cin>>c){
        if(id==0)
            f+=c;
        else e+=c;
        id = (id+1)%2;
    }

    ll f_end = f.length() - 1;
    ll f_begin = 0;

    for(ll e_cur=0;e_cur<e.length();e_cur++){
        // put the file in the left
        req.push_back({f_begin,f[f_begin]-'0'});
        // examine the empty space next the checked file
        ll e_size = e[e_cur] - '0';
        while(f_end>f_begin&&e_size>0){
            ll load = min(e_size,(ll)f[f_end]-'0');
            req.push_back({f_end,load});
            e_size-=load;
            f[f_end] = '0' + (f[f_end]-'0') - load;
            if(f[f_end]=='0') f_end--;
        }
        f_begin++;
    }
    id = 0;
    for(auto i:req){
	//math
        ans+=i.first*(id*i.second+(i.second*(i.second-1))/2);
        id+=i.second;
    }//for(ll ii=0;ii<i.second;ii++) ans+=(id++)*i.first;
    cout<<ans<<endl;
}
