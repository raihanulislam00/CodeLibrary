#include <bits/stdc++.h>
using namespace std;

double dp[4][46656];
bool v[4][46656];
int k;
vector<int> v1, v2;
double p[6], f[6];
vector<pair<vector<int>, double>> dl[6];
int p6[6] = {1,6,36,216,1296,7776};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    v1.reserve(6);
    for(int i = 0; i < 6; i++){
        int a;
        cin >> a;
        bool flag = false;
        for(int j = 0; j < v1.size(); j++){
            if(v1[j] == a){
                v2[j]++;
                flag = true;
                break;
            }
        }
        if(!flag){
            v1.push_back(a);
            v2.push_back(1);
        }
    }
    
    k = v1.size();
    for(int i = 0; i < k; i++){
        p[i] = (double)v2[i] / 6.0;
    }
    
    f[0] = 1.0;
    for(int i = 1; i <= 5; i++){
        f[i] = f[i-1] * i;
    }
    
    for(int n = 0; n <= 5; n++){
        stack<pair<vector<int>, pair<int,int>>> st;
        st.push({vector<int>(k,0), {0,n}});
        
        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            vector<int> d = cur.first;
            int idx = cur.second.first;
            int rem = cur.second.second;
            
            if(idx == k-1){
                d[idx] = rem;
                double p1 = f[n];
                for(int i = 0; i < k; i++){
                    p1 /= f[d[i]];
                    if(d[i] > 0) p1 *= pow(p[i], d[i]);
                }
                dl[n].push_back({d, p1});
            } else {
                for(int x = 0; x <= rem; x++){
                    vector<int> nd = d;
                    nd[idx] = x;
                    st.push({nd, {idx+1, rem-x}});
                }
            }
        }
    }
    
    stack<pair<int,int>> solve;
    solve.push({0,3});
    
    while(!solve.empty()){
        auto cur = solve.top();
        int c = cur.first;
        int r = cur.second;
        
        if(v[r][c]){
            solve.pop();
            continue;
        }
        
        vector<int> cnt(k);
        int t = c;
        for(int i = 0; i < k; i++){
            cnt[i] = t % 6;
            t /= 6;
        }
        
        int sm = 0;
        for(int i = 0; i < k; i++) sm += cnt[i];
        
        if(r == 0){
            double best = 0.0;
            for(int i = 0; i < k; i++){
                double sc = v1[i] * (double)cnt[i];
                if(sc > best) best = sc;
            }
            dp[r][c] = best;
            v[r][c] = true;
            solve.pop();
            continue;
        }
        
        bool ok = true;
        int nr = 5 - sm;
        
        for(auto &pr : dl[nr]){
            vector<int> d = pr.first;
            
            stack<pair<vector<int>,int>> dfs;
            dfs.push({vector<int>(k), 0});
            
            while(!dfs.empty()){
                auto d5 = dfs.top();
                dfs.pop();
                vector<int> nc = d5.first;
                int ix = d5.second;
                
                if(ix == k){
                    int ncd = 0;
                    for(int i = 0; i < k; i++){
                        ncd += nc[i] * p6[i];
                    }
                    if(!v[r-1][ncd]){
                        ok = false;
                        solve.push({ncd, r-1});
                    }
                } else {
                    int o = d[ix];
                    int b1 = cnt[ix];
                    for(int j = 0; j <= o; j++){
                        vector<int> nnc = nc;
                        nnc[ix] = b1 + j;
                        dfs.push({nnc, ix+1});
                    }
                }
            }
        }
        
        if(ok){
            double ex = 0.0;
            for(auto &pr : dl[nr]){
                vector<int> d = pr.first;
                double p1 = pr.second;
                double bv = 0.0;
                
                stack<pair<vector<int>,int>> dfs;
                dfs.push({vector<int>(k), 0});
                
                while(!dfs.empty()){
                    auto d5 = dfs.top();
                    dfs.pop();
                    vector<int> nc = d5.first;
                    int ix = d5.second;
                    
                    if(ix == k){
                        int ncd = 0;
                        for(int i = 0; i < k; i++){
                            ncd += nc[i] * p6[i];
                        }
                        double vl = dp[r-1][ncd];
                        if(vl > bv) bv = vl;
                    } else {
                        int o = d[ix];
                        int b1 = cnt[ix];
                        for(int j = 0; j <= o; j++){
                            vector<int> nnc = nc;
                            nnc[ix] = b1 + j;
                            dfs.push({nnc, ix+1});
                        }
                    }
                }
                ex += p1 * bv;
            }
            dp[r][c] = ex;
            v[r][c] = true;
            solve.pop();
        }
    }
    
    double ans = dp[3][0];
    cout << fixed << setprecision(10) << ans;
    return 0;
}