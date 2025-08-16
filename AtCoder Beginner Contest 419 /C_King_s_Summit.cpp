#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n;
    cin >> n;
    int min1 = LLONG_MAX, max1 = LLONG_MIN;
    int min2 = LLONG_MAX, max2 = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        if (r < min1) min1 = r;
        if (r > max1) max1 = r;
        if (c < min2) min2 = c;
        if (c > max2) max2 = c;
    }

    int x1 = max1 - min1;
    int y1 = max2 - min2;
    int x = (x1 + 1) / 2;
    int y = (y1 + 1) / 2;
    int ans = max(x, y);

    cout << ans << endl;

    return 0;
}