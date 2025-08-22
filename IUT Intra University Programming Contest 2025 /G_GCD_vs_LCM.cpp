#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    while(t--){
        int n;
        int l;
        cin >> n >> l;
        if (n > (int)primes.size()) {
            cout << -1;
        } else {
            __int128 P = 1;
            for(int i=0; i<n; ++i) {
                P *= primes[i];
                if (P > l) break;
            }
            if (P > l) {
                cout << -1;
            } else {
                int p = (int)P;
                for(int i=0; i<n; ++i) {
                    int ai = p / primes[i];
                    cout << ai << (i+1<n ? ' ' : '\n');
                }
            }
        }
        if (t) cout << '\n';
    }
    return 0;
}
