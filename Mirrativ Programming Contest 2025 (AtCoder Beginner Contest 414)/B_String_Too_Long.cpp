#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    long long t = 0;
    for (int i = 0; i < n; i++) {
        char c;
        long long l;
        cin >> c >> l;
        t += l;
        if (t > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
        s += string((int)l, c);
    }
    cout << s << endl;
}