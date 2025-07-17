#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        unordered_set<char> v;
        string s = to_string(x);
        for (char c : s) {
            v.insert(c);
        }
        
        int y = 0;
        for (; y <= 9; ++y) {
            string str = to_string(y);
            for (char c : str) {
                if (v.count(c)) {
                    cout << y << endl;
                    y = 10; 
                    break;
                }
            }
        }
    }
    return 0;
}