#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int a = 0;
        int p = 1;
        for (int d = 1; d <= 18; d++) {
            int c = 9 * p;
            int x = c * d;
            if (k >= x) {
                int l = p, r = p * 10 - 1;
                function<int(int)> f = [&](int n) -> int {
                    function<int(int)> g = [&](int n) -> int {
                        if (n < 10) return (n * (n + 1)) / 2;
                        int q = 1, m = n;
                        int z = 0;
                        while (m >= 10) {
                            m /= 10;
                            q *= 10;
                            z++;
                        }
                        int h = m, w = n % q;
                        int v = z * (q / 10) * 45ULL;
                        return h * v + (h * (h - 1) / 2) * q + h * (w + 1) + g(w);
                    };
                    return g(n);
                };
                a += f(r) - f(l - 1);
                k -= x;
                p *= 10;
            } else {
                int u = k / d;
                int e = k % d;
                if (u > 0) {
                    int l = p, r = p + u - 1;
                    function<int(int)> f = [&](int n) -> int {
                        function<int(int)> g = [&](int n) -> int {
                            if (n < 10) return (n * (n + 1)) / 2;
                            int q = 1, m = n;
                            int z = 0;
                            while (m >= 10) {
                                m /= 10;
                                q *= 10;
                                z++;
                            }
                            int h = m, w = n % q;
                            int v = z * (q / 10) * 45ULL;
                            return h * v + (h * (h - 1) / 2) * q + h * (w + 1) + g(w);
                        };
                        return g(n);
                    };
                    a += f(r) - f(l - 1);
                }
                if (e > 0) {
                    int n = p + u;
                    string s = to_string(n);
                    for (int i = 0; i < e; i++) a += s[i] - '0';
                }
                break;
            }
        }
        cout << a << endl;
    }
}