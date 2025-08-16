#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int x;
            cin >> x;
            pq.push(x);
        } else {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
    
    return 0;
}