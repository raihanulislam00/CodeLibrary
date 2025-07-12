#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;

class SegmentTree {
public:
    vector<ll> v;
    int n;

    SegmentTree(int size) {
        n = size;
        v.assign(4 * n, INF);
    }

    void update(int idx, int l, int r, int pos, ll val) {
        if (l == r) {
            v[idx] = min(v[idx], val);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * idx, l, mid, pos, val);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, val);
        }
        v[idx] = min(v[2 * idx], v[2 * idx + 1]);
    }

    void update(int pos, ll val) {
        update(1, 0, n - 1, pos, val);
    }

    ll query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return INF;
        }
        if (ql <= l && qr >= r) {
            return v[idx];
        }
        int mid = (l + r) / 2;
        ll l1 = query(2 * idx, l, mid, ql, qr);
        ll r1 = query(2 * idx + 1, mid + 1, r, ql, qr);
        return min(l1, r1);
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<ll> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    vector<ll> dp(N, INF);
    dp[0] = 0;

    SegmentTree e(N);
    SegmentTree w(N);

    e.update(0, dp[0] - x[0]);
    w.update(0, dp[0] + x[0]);

    vector<vector<int>> e1(N);
    vector<vector<int>> w1(N);

    vector<tuple<int, int, int, int, ll>> e2;
    vector<tuple<int, int, int, int, ll>> w2;

    for (int i = 0; i < M; i++) {
        int l, r, L, R;
        ll c;
        cin >> l >> r >> L >> R >> c;
        l--; r--; L--; R--;
        if (r < L) {
            e2.push_back({l, r, L, R, c});
            for (int j = l; j <= r; j++) {
                e1[j].push_back(e2.size() - 1);
            }
        } else if (R < l) {
            w2.push_back({l, r, L, R, c});
            for (int j = l; j <= r; j++) {
                w1[j].push_back(w2.size() - 1);
            }
        }
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, idx] = pq.top();
        pq.pop();
        if (d != dp[idx]) continue;

        e.update(idx, dp[idx] - x[idx]);
        w.update(idx, dp[idx] + x[idx]);

        for (int idx1 : e1[idx]) {
            auto [l, r, L, R, c] = e2[idx1];
            ll b = e.query(l, r);
            if (b == INF) continue;
            b += c;
            for (int j = L; j <= R; j++) {
                ll temp = b + x[j];
                if (temp < dp[j]) {
                    dp[j] = temp;
                    pq.push({dp[j], j});
                }
            }
        }

        for (int idx1 : w1[idx]) {
            auto [l, r, L, R, c] = w2[idx1];
            ll b = w.query(l, r);
            if (b == INF) continue;
            b += c;
            for (int j = L; j <= R; j++) {
                ll temp = b - x[j];
                if (temp < dp[j]) {
                    dp[j] = temp;
                    pq.push({dp[j], j});
                }
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (dp[i] >= INF) {
            cout << -1;
        } else {
            cout << dp[i];
        }
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}