#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        cin >> n >> m; 
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        long double sum = 0.0L;
        for (int i = 0; i < n; i++) {
            int t_i;
            cin >> t_i;
            sum += 1.0L / (t_i - s[i] + 1.0L);
        }
        long double avg = sum / n;
        cout << fixed << setprecision(6) << (double)avg << "\n";
    }
    return 0;
}
