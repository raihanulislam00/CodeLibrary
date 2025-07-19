#include <bits/stdc++.h>
using namespace std;
struct Node {
    char l, r;
    int len, p, s, mx;
};
static Node t[2100000];
string str;
Node merge(const Node &a, const Node &b) {
    if (a.len == 0) return b;
    if (b.len == 0) return a;
    Node res;
    res.len = a.len + b.len;
    res.l = a.l;
    res.r = b.r;
    res.mx = max(a.mx, b.mx);
    res.p = a.p;
    res.s = b.s;
    if (a.r == b.l) {
        int c = a.s + b.p;
        res.mx = max(res.mx, c);
        if (a.p == a.len) res.p = a.len + b.p;
        if (b.s == b.len) res.s = b.len + a.s;
    }
    return res;
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].len = 1;
        t[v].l = t[v].r = str[tl];
        t[v].p = t[v].s = t[v].mx = 1;
    } else {
        int tm = (tl + tr) >> 1;
        build(v<<1, tl, tm);
        build(v<<1|1, tm+1, tr);
        t[v] = merge(t[v<<1], t[v<<1|1]);
    }
}
void upd(int v, int tl, int tr, int pos, char c) {
    if (tl == tr) {
        t[v].l = t[v].r = c;
        t[v].p = t[v].s = t[v].mx = 1;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) upd(v<<1, tl, tm, pos, c);
        else upd(v<<1|1, tm+1, tr, pos, c);
        t[v] = merge(t[v<<1], t[v<<1|1]);
    }
}
Node get(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    if (r <= tm) return get(v<<1, tl, tm, l, r);
    else if (l > tm) return get(v<<1|1, tm+1, tr, l, r);
    else return merge(get(v<<1, tl, tm, l, r), get(v<<1|1, tm+1, tr, l, r));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q >> str;
    build(1, 0, n-1);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int i; char x;
            cin >> i >> x;
            upd(1, 0, n-1, i-1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get(1, 0, n-1, l-1, r-1).mx << '\n';
        }
    }
    return 0;
}