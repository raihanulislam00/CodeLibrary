#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        for (int l = 0; l < n; l++) {
            priority_queue<int> mh;
            priority_queue<int, vector<int>, greater<int>> pp;
            int m = INT_MAX;

            for (int r = l; r < n && r < l + 200; r++) {
                int x = a[r];
                if (x < m) {
                    m = x;
                }

                if (mh.empty() || x <= mh.top()) {
                    mh.push(x);
                } else {
                    pp.push(x);
                }

                int k = r - l + 1;
                int d = (k + 2) / 2;

                if (mh.size() < d) {
                    if (!pp.empty()) {
                        int t = pp.top();
                        pp.pop();
                        mh.push(t);
                    }
                } else if (mh.size() > d) {
                    int t = mh.top();
                    mh.pop();
                    pp.push(t);
                }

                int med = mh.top();
                ans = max(ans, med - m);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
