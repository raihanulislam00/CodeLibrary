#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (k == 0) {
            int s = 0;
            for (int x : a) s += x;
            cout << s << endl;
            continue;
        }
        vector<int> freq(n + 2, 0);
        for (int x : a) {
            if (x <= n) {
                freq[x]++;
            }
        }
        int temp = 0;
        while (freq[temp] > 0) temp++;
        if (temp == 0) {
            if (k % 2 == 0) {
                cout << n << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            bool flag = true;
            for (int i = 0; i < temp; i++) {
                if (freq[i] != 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                int sum1 = (int) temp * (temp - 1) / 2;
                if (n - temp >= 2) {
                    if (k % 2 == 1) {
                        cout << sum1 + (int) temp * (n - temp) << endl;
                    } else {
                        cout << sum1 + (int) (temp + 1) * (n - temp) << endl;
                    }
                } else {
                    cout << sum1 + (int) temp * (n - temp) << endl;
                }
            } else {
                int x = temp;
                for (int i = 0; i < temp; i++) {
                    if (freq[i] != 1) {
                        x = i;
                        break;
                    }
                }
                if (k == 1) {
                    int cnt = 0;
                    int tmp = 0;
                    for (int i = 0; i < temp; i++) {
                        if (freq[i] == 1) {
                            cnt += i;
                            tmp++;
                        }
                    }
                    cout << cnt + (int) temp * (n - tmp) << endl;
                } else {
                    int t1 = (int) x * (x - 1) / 2;
                    if (k % 2 == 0) {
                        cout << t1 + (int) x * (n - x) << endl;
                    } else {
                        cout << t1 + (int) (x + 1) * (n - x) << endl;
                    }
                }
            }
        }
    }
    
    return 0;
}