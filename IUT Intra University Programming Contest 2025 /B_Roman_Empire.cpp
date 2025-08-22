#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int, string>> v = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string ans = "";
        
        for (auto &p : v) {
            while (n >= p.first) {
                ans += p.second;
                n -= p.first;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}
