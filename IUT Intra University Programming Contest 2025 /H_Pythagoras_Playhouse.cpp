#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N = 20000000;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> c0;
    int M = (int)sqrt(MAX_N);
    for (int m = 2; m <= M; m++) {
        for (int n = 1; n < m; n++) {
            if (m % 2 != n % 2) {
                int a = m, b = n;
                while (b) {
                    int t = b;
                    b = a % b;
                    a = t;
                }
                if (a == 1) {
                    int c = m*m + n*n;
                    if (c <= MAX_N) {
                        c0.push_back(c);
                    }
                }
            }
        }
    }
    
    sort(c0.begin(), c0.end());
    
    vector<int> g(MAX_N+1, 0);
    for (int c0 : c0) {
        for (int i = c0; i <= MAX_N; i += c0) {
            g[i]++;
        }
    }
    
    vector<int> p(MAX_N+1, 0);
    for (int i = 1; i <= MAX_N; i++) {
        p[i] = p[i-1] + g[i];
    }
    
    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        cout << p[2*r] << endl;
    }
    
    return 0;
}