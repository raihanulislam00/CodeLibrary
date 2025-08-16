#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> diff(n+2, 0);
    for(int i = 0; i < m; ++i){
        int L, R;
        cin >> L >> R;
        diff[L] += 1;
        if(R + 1 <= n) diff[R+1] -= 1;
    }
    for(int i = 1; i <= n; ++i){
        diff[i] += diff[i-1];
    }
    for(int i = 1; i <= n; ++i){
        if(diff[i] % 2 != 0){
            s[i-1] = t[i-1];
        }
    }
    cout << s;
    return 0;
}
