#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int a1, a2;
    cin >> a1 >> a2;
    int a3;
    for (int i = 3; i <= 10; i++) {
        int sum = a1 + a2;
        string s = to_string(sum);
        reverse(s.begin(), s.end());
        a3 = stoll(s);
        a1 = a2;
        a2 = a3;
    }
    cout << a3 << endl;
    return 0;
}