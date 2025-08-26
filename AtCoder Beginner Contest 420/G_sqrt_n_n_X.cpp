#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll X; cin >> X;
    __int128 D128 = 1 - (__int128)4 * X;
    ll D = (ll)D128;
    ll E = D > 0 ? D : -D;
    vector<ll> divs;
    for (ll i = 1; i * i <= E; i++) {
        if (E % i == 0) {
            divs.push_back(i);
            if (i * i != E) divs.push_back(E / i);
        }
    }
    vector<ll> ans;
    if (D > 0) {
        for (ll d : divs) {
            for (int sgn = -1; sgn <= 1; sgn += 2) {
                ll p = sgn * d;
                if (D % p != 0) continue;
                ll q = D / p;
                if (((p + q) & 1) == 0) {
                    ll A = (p + q) / 2;
                    ll B = (q - p) / 2;
                    if ((A & 1) && (B % 2 == 0)) ans.push_back((A - 1) / 2);
                }
            }
        }
    } else {
        for (ll d : divs) {
            for (int sgn = -1; sgn <= 1; sgn += 2) {
                ll p = sgn * d;
                ll q = -(E / d) * sgn;
                if (((p + q) & 1) == 0) {
                    ll A = (p + q) / 2;
                    ll B = (q - p) / 2;
                    if ((A & 1) && (B % 2 == 0)) ans.push_back((A - 1) / 2);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << (i + 1 < (int)ans.size() ? ' ' : '\n');
    }
}
