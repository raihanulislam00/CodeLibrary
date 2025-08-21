#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a;
        int m;
        string b, c;
        
        cin >> n >> a;
        cin >> m >> b >> c;
        
        for (int i = 0; i < m; i++) {
            if (c[i] == 'V') {
                a = b[i] + a;
            } else {
                a = a + b[i];
            }
        }
        cout << a << endl;
    }
    return 0;
}