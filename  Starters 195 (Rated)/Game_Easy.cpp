#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FOR_EQ(i,a,b) for(int i=a;i<=b;i++)

int main() {
    FAST_IO;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort(a.rbegin(), a.rend());
        vector<long long> v(n+1);
        FOR(i,0,n) v[i+1] = v[i] + a[i];
        vector<long long> res(2*n+1, 0);
        FOR_EQ(i,0,n) { 
            int x = 2*i;
            if (x > 2*n) break;
            FOR_EQ(j,0,n-i) { 
                int k = x + j;
                if (k > 2*n) break;
                int m = j + i;
                long long sum = v[m] + 1LL*i*(i+2*j-1)/2;
                res[k] = max(res[k], sum);
            }
        }
        FOR_EQ(k,1,2*n)
            cout << res[k] << (k==2*n ? endl : ' ');
    }
    return 0;
}
