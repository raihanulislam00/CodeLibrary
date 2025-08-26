#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {int x,y,s;};
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h,w;
    cin>>h>>w;
    vector<string> a(h);
    for(int i=0;i<h;i++) cin>>a[i];
    int sx,sy,gx,gy;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        if(a[i][j]=='S'){sx=i;sy=j;}
        if(a[i][j]=='G'){gx=i;gy=j;}
    }
    vector<vector<vector<int>>> v(h,vector<vector<int>>(w,vector<int>(2,-1)));
    queue<Node> q;
    v[sx][sy][0]=0;
    q.push({sx,sy,0});
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    while(!q.empty()){
        auto [x,y,s]=q.front();q.pop();
        int d=v[x][y][s];
        for(int k=0;k<4;k++){
            int nx=x+dx[k],ny=y+dy[k];
            if(nx<0||ny<0||nx>=h||ny>=w) continue;
            char c=a[nx][ny];
            if(c=='#') continue;
            if(c=='x' && s==0) continue;
            if(c=='o' && s==1) continue;
            int ns=s;
            if(c=='?') ns^=1;
            if(v[nx][ny][ns]==-1){
                v[nx][ny][ns]=d+1;
                q.push({nx,ny,ns});
            }
        }
    }
    int ans=-1;
    if(v[gx][gy][0]!=-1) ans=v[gx][gy][0];
    if(v[gx][gy][1]!=-1) {
        if(ans==-1) ans=v[gx][gy][1];
        else ans=min(ans,v[gx][gy][1]);
    }
    cout<<ans<<endl;
}
