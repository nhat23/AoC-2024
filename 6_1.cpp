#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
char a[1000][1000];
int n,m;
int x,y;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool vis[1000][1000];
bool vi[1000][1000][4];

struct node{
    int x,y,dir;
    node(int xx, int yy, int dirr){
        x=xx;
        y=yy;
        dir=dirr;
    }
};

bool check(int x, int y){
    if(x<1||x>n||y<1||y>m) return 1;
    return 0;
}

void bfs(int x,int y,int dir){
    queue<node> q;
    q.push({x,y,dir});
    while(q.size()>0){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();
        if(!vis[x][y]) ans++,vis[x][y]=1;
        if(vi[x][y][dir]) continue;
        vi[x][y][dir]=1;
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if(check(xx,yy)) continue;
        else if(a[xx][yy]=='#') q.push({x,y,(dir+1)%4});
        else q.push({xx,yy,dir});
    }
}

int main() {
    #define file "test"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        char c;
        int k = 0;
        n++;
        while(ss>>c) {
            k++;
            a[n][k]=c;
            if(c=='^') x=n,y=k;

        }

        m=k;
    }
    cout<<ans;
}
