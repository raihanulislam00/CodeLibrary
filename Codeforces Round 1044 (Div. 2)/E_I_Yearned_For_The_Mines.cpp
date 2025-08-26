#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back
#define maxel(v) *max_element(v.begin(), v.end())
#define minel(v) *min_element(v.begin(), v.end())
#define yes cout << "YES\n";
#define m1 cout << "-1\n";
#define no cout << "NO\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll mod3 = 998244353;
const double pi = 3.141592653589793238;
const long double EPS = 1e-9;
const int MAXN = 1e5 * 5;

template <typename T>
ostream& operator<< (ostream &os, const pair<T, T>& a){
    return os << a.fi << " " << a.se;
}
template <typename T>
istream& operator>> (istream& in, pair<T, T>& a){
    in >> a.fi >> a.se;
    return in;
}
template <typename T>
ostream& operator<< (ostream &os, const vector<T>& a){
    for (int x : a) os << x << " ";
    return os;
}
template <typename T>
istream& operator>> (istream& in, vector<pair<T, T>>& a){
    for (pair<int, int>& x : a) in >> x.fi >> x.se;
    return in;
}
template <typename T>
ostream& operator<< (ostream &os, const vector<pair<T, T>>& a){
    for (pair<int, int> x : a) os << x.fi << " " << x.se << endl;
    return os;
}
template <typename T>
istream& operator>> (istream& in, vector<T>& a){
    for (int& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<< (ostream &os, const set<T>& a){
    for (int x : a) os << x << " ";
    return os;
}
template <typename T>
ostream& operator<< (ostream &os, const map<T, T>& a){
    for (pair<int, int> x : a) os << x.fi << " " << x.se << endl;
    return os;
}
template <typename T>
void printrb(vector<T>* rb, int n) {
    for (int u = 0; u < n; ++u) {
        for (const T& v : rb[u]) {
            cout << u << " -> " << v << '\n';
        }
    }
}
template <typename T>
void print2d(const vec<vec<T>> &vec) {
    for (const auto &row : vec) {
        for (const auto &i : row) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vec<vec<int>> g(n+1);
        for (int i = 0; i < n-1; ++i) {
            int u, v; cin >> u >> v;
            g[u].pb(v); g[v].pb(u);
        }

        auto do_path_checks = [&](vec<pii>& ops){
            vec<int> deg(n+1);
            for (int i = 1; i <= n; ++i) deg[i] = (int)g[i].size();
            int s = 1;
            for (int i = 1; i <= n; ++i) if (deg[i] == 1) { s = i; break; }
            int p = 0, u = s;
            for (int k = 0; k < n; ++k) {
                ops.pb({1, u});
                int nxt = 0;
                for (int v : g[u]) if (v != p) { nxt = v; break; }
                p = u; u = nxt;
                if (!u) break;
            }
        };

        if (n == 2) {
            cout << 2 << endl;
            cout << 1 << " " << 1 << endl;
            cout << 1 << " " << 2 << endl;
            continue;
        }
        if (n == 3) {
            vec<pii> ops;
            do_path_checks(ops);
            cout << (int)ops.size() << endl;
            for (auto &e: ops) cout << e.fi << " " << e.se << endl;
            continue;
        }

        bool is_path = true;
        for (int i = 1; i <= n; ++i) if ((int)g[i].size() > 2) { is_path = false; break; }
        if (is_path) {
            vec<pii> ops;
            do_path_checks(ops);
            cout << (int)ops.size() << endl;
            for (auto &e: ops) cout << e.fi << " " << e.se << endl;
            continue;
        }

        vec<int> par(n+1, 0), ord; ord.pb(1); par[1] = -1;
        for (int i = 0; i < (int)ord.size(); ++i) {
            int u = ord[i];
            for (int v : g[u]) if (v != par[u]) par[v] = u, ord.pb(v);
        }
        vec<vec<int>> ch(n+1);
        for (int u = 2; u <= n; ++u) ch[par[u]].pb(u);


        vec<ll> nk(n+1, 0), k0(n+1, 0), k1(n+1, 0);
        for (int i = n-1; i >= 0; --i) {
            int u = ord[i];
            ll s = 0;
            for (int v : ch[u]) s += max(nk[v], k0[v]);
            nk[u] = s;
            ll base = 0, g1 = 0, g2 = 0;
            for (int v : ch[u]) {
                base += nk[v];
                ll d = k1[v] - nk[v];
                if (d > g1) { g2 = g1; g1 = d; }
                else if (d > g2) g2 = d;
            }
            k1[u] = 1 + base + max(0LL, g1);
            k0[u] = 1 + base + max(0LL, g1) + max(0LL, g2);
        }

        vec<int> keep(n+1, 0);
        function<void(int,int,int)> rec = [&](int u, int pk, int take){
            keep[u] = take;
            if (!take) {
                for (int v : ch[u]) {
                    if (k0[v] >= nk[v]) rec(v, 0, 1);
                    else rec(v, 0, 0);
                }
            } else {
                vec<pair<ll,int>> a;
                a.reserve(ch[u].size());
                for (int v : ch[u]) a.pb({k1[v] - nk[v], v});
                sort(a.rbegin(), a.rend());
                int need = (pk ? 1 : 2), takecnt = 0;
                vec<int> sel;
                for (auto &q : a) if (q.fi > 0 && takecnt < need) sel.pb(q.se), ++takecnt;
                int x = (int)sel.size() >= 1 ? sel[0] : -1;
                int y = (int)sel.size() >= 2 ? sel[1] : -1;
                for (int v : ch[u]) {
                    if (v == x) { rec(v, 1, 1); x = -1; }
                    else if (v == y) { rec(v, 1, 1); y = -1; }
                    else rec(v, 1, 0);
                }
            }
        };
        if (k0[1] >= nk[1]) rec(1, 0, 1);
        else rec(1, 0, 0);

        vec<int> inR;
        inR.reserve(n);
        for (int i = 1; i <= n; ++i) if (keep[i]) inR.pb(i);
        vec<int> inS;
        inS.reserve(n);
        for (int i = 1; i <= n; ++i) if (!keep[i]) inS.pb(i);

        vec<pii> ops;
        for (int v : inS) { ops.pb({1, v}); ops.pb({2, v}); }

        vec<int> deg(n+1, 0), vis(n+1, 0);
        for (int u = 1; u <= n; ++u) if (keep[u]) {
            for (int v : g[u]) if (keep[v]) ++deg[u];
        }
        for (int u = 1; u <= n; ++u) if (keep[u] && deg[u] <= 1 && !vis[u]) {
            int p = 0, x = u;
            while (true) {
                vis[x] = 1;
                ops.pb({1, x});
                int nxt = 0;
                for (int y : g[x]) if (keep[y] && y != p) { nxt = y; break; }
                if (!nxt) break;
                p = x; x = nxt;
            }
        }

        ll lim = (5LL * n) / 4;
        if ((ll)ops.size() > lim) {
            vec<pii> alt;
            do_path_checks(alt);
            ops = alt;
        }

        cout << (int)ops.size() << endl;
        for (auto &e : ops) cout << e.fi << " " << e.se << endl;
    }
    return 0;
}
