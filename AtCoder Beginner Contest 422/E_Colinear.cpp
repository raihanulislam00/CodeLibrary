#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    vector<int> X(n), Y(n);
    for(int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
    }
    int need = n/2 + 1;
    mt19937_64 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> d(0, n-1);
    for(int trials = 0; trials < 15; trials++){
        int i = d(rng);
        int j = d(rng);
        if(i == j) continue;
        int x1 = X[i], y1 = Y[i];
        int x2 = X[j], y2 = Y[j];
        int a = y2 - y1;
        int b = x1 - x2;
        int c = x2*y1 - x1*y2;
        int count = 0;
        for(int k = 0; k < n; k++){
            int x = X[k], y = Y[k];
            if(a*x + b*y + c == 0) {
                if(++count >= need){
                    cout << "Yes\n" << a << " " << b << " " << c << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
