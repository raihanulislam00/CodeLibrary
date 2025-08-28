#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        if (((n - b) % 2 == 0) && (a <= b || ((a - b) % 2 == 0)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
