#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000 + 5;
static vector<int> adj[MAXN];
static bool visited_global[MAXN];
static int distJump[MAXN];
static int visited_label[MAXN]; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if(!(cin>>T)) {
        return 0;
    }
    int BFSid = 0;
    while(T--){
        int N, K;
        cin>>N>>K;
        for(int i=1;i<=N;i++){
            adj[i].clear();
            visited_global[i] = false;
            distJump[i] = -1;
        }
        for(int i=0;i<N-1;i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        visited_global[1] = true;
        distJump[1] = 0;
        vector<int> frontier;
        frontier.reserve(16);
        frontier.push_back(1);
        int level = 0;
        vector<int> nextFrontier;
        nextFrontier.reserve(16);
        while(!frontier.empty()){
            nextFrontier.clear();
            BFSid++;
            queue<pair<int,int>> Q;
            for(int u: frontier){
                visited_label[u] = BFSid;
                Q.push({u, 0});
            }
            while(!Q.empty()){
                auto pr = Q.front(); Q.pop();
                int u = pr.first;
                int d = pr.second;
                if(d == K){
                    if(!visited_global[u]){
                        visited_global[u] = true;
                        distJump[u] = level + 1;
                        nextFrontier.push_back(u);
                    }
                    continue;
                }
                for(int v: adj[u]){
                    if(visited_label[v] == BFSid) continue;
                    if(visited_global[v]) continue;
                    visited_label[v] = BFSid;
                    Q.push({v, d+1});
                }
            }
            frontier.swap(nextFrontier);
            level++;
        }
        if(N >= 2){
            cout<< (visited_global[2] ? distJump[2] : -1);
            for(int i=3; i<=N; i++){
                cout << ' ';
                if(visited_global[i]) cout<<distJump[i];
                else cout<<-1;
            }
        }
        cout << '\n';
    }
    return 0;
}
