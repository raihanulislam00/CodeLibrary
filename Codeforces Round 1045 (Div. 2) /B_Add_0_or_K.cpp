#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int g = 0;
        for (int x : a) {
            g = gcd(g, x);
        }
        if (g > 1) {
            for (int x : a) {
                cout << x << ' ';
            }
            cout << '\n';
        } else {
            if (k % 2 == 1) {
                for (int x : a) {
                    if (x % 2 == 0) {
                        cout << x << ' ';
                    } else {
                        cout << x + k << ' ';
                    }
                }
                cout << '\n';
            } else {
                int p = 3;
                while (k % p == 0 || !is_prime(p)) {
                    p += 2;
                }
                int mod = k % p;
                int inv = 1;
                while (inv < p) {
                    if ((mod * inv) % p == 1) {
                        break;
                    }
                    inv++;
                }
                for (int x : a) {
                    int r = x % p;
                    int d = (-r) % p;
                    if (d < 0) d += p;
                    int x1 = (d * inv) % p;
                    cout << x + x1 * k << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}