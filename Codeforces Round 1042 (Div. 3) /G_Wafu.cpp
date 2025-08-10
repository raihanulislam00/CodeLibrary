#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1000000007;
int p[62];
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    p[0] = 1;
    p[1] = 1;
    for (int i = 2; i < 62; i++) p[i] = (p[i-1] * i % M) * p[i-1] % M;
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int op = 1;
        int c = 1;
        for (int i = 1; i < n; i++) {
            if (a[i-1] > 60) break;
            int need = 1LL << (a[i-1] - 1);
            if (op + need <= k) op += need, c++;
            else break;
        }
        int p1 = 1;
        for (int i = 0; i < c; i++) p1 = p1 * (a[i] % M) % M;
        int p2 = 1;
        for (int i = 0; i < c-1; i++) {
            int x = a[i] - 1;
            if (x >= 0) p2 = p2 * p[x] % M;
        }
        int r = k - op;
        if (r <= 0 || a[c-1] == 1) {
            cout << (p1 * p2) % M << "\n";
            continue;
        }
        int N = a[c-1] - 1, n0 = 0;
        while (((1LL << n0) - 1) < r) n0++;
        if (n0 > N) n0 = N;
        int ans = 1;
        {
            int n1 = n0;
            int r1 = r;
            vector<pair<int,int>> st;
            while (true) {
                if (r1 == 0 || n1 <= 1) { ans = (ans * 1) % M; break; }
                int h = (1LL << (n1-1)) - 1;
                if (r1 <= h) { n1--; continue; }
                if (r1 == h + 1) { ans = ans * (p[n1-1] * n1 % M) % M; break; }
                ans = ans * (p[n1-1] * n1 % M) % M;
                r1 -= (h + 1);
                n1--;
            }
        }
        cout << p1 * p2 % M * ans % M << "\n";
    }
}
