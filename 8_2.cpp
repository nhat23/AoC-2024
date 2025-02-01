#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans = 0;
char c[100][100];
bool vi[100][100];
int n=0,m;

struct pi{
    int fi,se;
    pi(int a,int b){
        fi = a;
        se = b;
    }
};

bool chk(int x, int y){
    return !(x<1||x>n||y<1||y>m);
}

void check(int x,int y){
    if(!vi[x][y]) ans++,vi[x][y]=1;
}

map<char,vector<pi>> mp;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        n++;
        int k = 0;
        while(ss>>c[n][++k]);
        k--;
        m=k;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]!='.') mp[c[i][j]].push_back({i,j});
        }
    }
    for(auto it:mp){
        vector<pi> &tmp = it.second;

        int sz = tmp.size();
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                pi a = tmp[i];
                pi b = tmp[j];
                if(a.se>b.se) swap(a,b);
                int dx = abs(a.fi-b.fi);
                int dy = abs(a.se-b.se);
                int ddx;
                if(b.fi>a.fi){
                    ddx = -dx;
                }else{
                    ddx = dx;
                }

                for(int i=a.fi,j=a.se;chk(i,j);i+=ddx,j-=dy)
                    check(i,j);
                for(int i=b.fi,j=b.se;chk(i,j);i-=ddx,j+=dy)
                    check(i,j);

            }
        }
    }
    cout<<ans<<endl;
}
