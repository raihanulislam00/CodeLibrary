#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    int l = 1, r = n;
    string s;
    
    while (l < r) {
        int m = (l + r) / 2;
        cout << "? " << m;
        for (int i = 1; i <= m; i++) {
            cout << " " << i;
        }
        cout << endl;
        cout.flush();
        cin >> s;
        
        if (s == "Kaboom") {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    int y = l;
    int a = 1, b = y - 1;
    int x = 1;
    
    while (a < b) {
        int m = (a + b) / 2;
        cout << "? " << m + 1;
        for (int i = 1; i <= m; i++) {
            cout << " " << i;
        }
        cout << " " << y;
        cout << endl;
        cout.flush();
        cin >> s;
        
        if (s == "Kaboom") {
            b = m;
        } else {
            a = m + 1;
        }
    }
    
    if (b >= a) x = a;
    cout << "! " << x << " " << y << endl;
    cout.flush();
    
    return 0;
}