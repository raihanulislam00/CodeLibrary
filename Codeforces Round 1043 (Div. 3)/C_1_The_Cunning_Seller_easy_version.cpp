#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> pow3(40);
    pow3[0] = 1;
    for(int i = 1; i < 40; i++){
        pow3[i] = pow3[i-1] * 3;
    }
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        int i = 0;
        while(n > 0){
            int d = n % 3;
            if(d){
                if(i == 0){
                    ans += d * 3;
                } else {
                    ans += d * (pow3[i+1] + (int)i * pow3[i-1]);
                }
            }
            n /= 3;
            i++;
        }
        cout << ans;
        if(t) cout << '\n';
    }
    return 0;
}
