#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    cout << s.substr(a, n - a - b) << endl;
    return 0;
}