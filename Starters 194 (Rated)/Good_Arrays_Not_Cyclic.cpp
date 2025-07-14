#include <bits/stdc++.h>

using namespace std;

static const int MOD = 1e9+7;

int add(int a, int b){ a+=b; if(a>=MOD) a-=MOD; return a; }

int mul(long long a, long long b){ return (int)( (a*b) % MOD ); }

int main(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int T; 

    cin >> T;

    while(T--){

        int N;

        cin >> N;

        vector<string> M(N);

        for(int i=0; i<N; i++) 

            cin >> M[i];

        int total = 1;

        for(int i=0; i<N; i++){

            int cnt = 0;

            for(char c: M[i]) if(c=='1') cnt++;

            total = mul(total, cnt);

        }

        int k = N/2;

        vector<int> dp_old(1, 1);

        int offset = N;

        int Dsize = 2*offset+1;

        for(int i=1; i<=k; i++){

            int rB = k - i;

            int rC = 2*k - i;

            static int fb[101], fc[101];

            memset(fb, 0, sizeof fb);

            memset(fc, 0, sizeof fc);

            for(int v=1; v<=N; v++){

                if(M[rB][v-1]=='1') fb[v]=1;

        if(M[rC][v-1]=='1') fc[v]=1;

            }

            static int fd[201];

            memset(fd, 0, sizeof fd);

            for(int x=1; x<=N; x++) if(fb[x]){

                for(int y=1; y<=N; y++) if(fc[y]){

                    fd[y-x+offset]++;

                }

            }

            vector<pair<int,int>> deltas;

            deltas.reserve(Dsize);

            int min_z = -(N-1), max_z = (N-1);

            for(int z = min_z; z<=max_z; z++){

                int cnt = fd[z+offset];

                if(cnt) deltas.emplace_back(z, cnt);

            }

            int dmax_old = (int)dp_old.size() - 1;

            int dmax_new = dmax_old + max_z;

            vector<int> dp_new(dmax_new + 1, 0);

            for(int d_old=0; d_old<=dmax_old; d_old++){

                int ways = dp_old[d_old];

                if(!ways) continue;

                for(auto &p: deltas){

                    int z = p.first;

                    int cnt = p.second;

                    int d_new = d_old + z;

                    if(d_new < 0 || d_new > dmax_new) continue;

                    dp_new[d_new] = add(dp_new[d_new], mul(ways, cnt));

                }

            }

            dp_old.swap(dp_new);

        }

        int count_bad = dp_old[0];

        int ans = total - count_bad;

        if(ans < 0) ans += MOD;

        cout << ans << "\n";

    }

    return 0;

}