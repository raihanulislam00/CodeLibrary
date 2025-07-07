#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> f(m);
    for (int i = 0; i < m; ++i) {
        cin >> f[i];
    }
    sort(f.begin(), f.end());

    int temp = INT_MAX;
    for (int i = 0; i <= m - n; ++i) {
        int diff = f[i + n - 1] - f[i];
        temp = min(temp, diff);
    }
    cout << temp << endl;

    return 0;
}
