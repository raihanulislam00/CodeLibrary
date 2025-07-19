#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    cin >> N >> M;

    vector<pair<int, int>> v;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        int d = A - B;
        v.push_back({A, d});
    }

    sort(v.begin(), v.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> h;
    int crn = N;
    int ans = 0;
    int idx = 0;

    while (true) {
        while (idx < M && v[idx].first <= crn) {
            h.push({v[idx].second, v[idx].first});
            idx++;
        }

        while (!h.empty() && h.top().second > crn) {
            h.pop();
        }

        if (h.empty()) break;

        auto [d, A] = h.top();
        h.pop();

        if (crn < A) continue;

        int k = (crn - A) / d + 1;
        ans += k;
        crn -= k * d;
    }

    cout << ans << endl;

    return 0;
}