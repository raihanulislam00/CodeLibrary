#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r, a, b, c = 0;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a <= l && r <= b) c++;
    }
    cout << c << endl;
}