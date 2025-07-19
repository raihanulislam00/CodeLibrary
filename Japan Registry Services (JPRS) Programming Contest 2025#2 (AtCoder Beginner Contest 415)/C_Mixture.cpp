#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int t = (1 << n) - 1;
        vector<bool> v(1 << n, false);
        queue<int> q;
        
        q.push(0);
        v[0] = true;
        bool flag = false;
        
        while (!q.empty() && !flag) {
            int cur = q.front();
            q.pop();
            
            if (cur == t) {
                flag = true;
                break;
            }
            
            for (int i = 0; i < n; i++) {
                int nxt = cur | (1 << i);
                if (nxt != cur && !v[nxt] && s[nxt - 1] == '0') {
                    v[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        
        cout << (flag ? "Yes" : "No") << "\n";
    }
    
    return 0;
}