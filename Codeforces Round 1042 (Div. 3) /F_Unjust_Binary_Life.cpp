#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a;
        cin >> b;
        int b0 = b[0] - '0';
        vector<int> v(n, 0);
        v[0] = (a[0] - '0' != b0) ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            v[i] = v[i-1] + ((a[i] - '0') != b0);
        }
        vector<int> s(n, 0);
        s[0] = (b[0] - '0' != b0) ? 1 : 0;
        for (int j = 1; j < n; ++j) {
            s[j] = s[j-1] + ((b[j] - '0') != b0);
        }
        vector<int> u(n), v1(n);
        for (int i = 0; i < n; ++i) {
            u[i] = 2LL * v[i] - i;
        }
        for (int j = 0; j < n; ++j) {
            v1[j] = 2LL * s[j] - j;
        }
        int total1 = (int) n * n * n + (int) n * n;
        sort(v1.begin(), v1.end());
        vector<int> p;
        int total2 = 0;
        if (n > 0) {
            p.resize(n);
            p[0] = v1[0];
            for (int i = 1; i < n; ++i) {
                p[i] = p[i-1] + v1[i];
            }
            total2 = p[n-1];
        }
        int s1 = 0;
        for (int i = 0; i < n; ++i) {
            int w = u[i] - 2;
            int key = -w;
            int k = lower_bound(v1.begin(), v1.end(), key) - v1.begin();
            int count1 = n - k;
            int count2 = k;
            int sum1 = total2;
            int sum2 = 0;
            if (k > 0) {
                sum2 = p[k-1];
                sum1 = total2 - sum2;
            }
            int m = w * (2 * count1 - n) + (sum1 - sum2);
            s1 += m;
        }
        cout << (total1 - s1) / 2 << endl;
    }
    return 0;
}