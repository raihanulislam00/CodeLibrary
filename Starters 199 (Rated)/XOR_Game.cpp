#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        int S = 0;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            S ^= A[i];
        }

        if (n > 100) {
            cout << S << '\n';
        } else {
            int best = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    long new_value = A[i] ^ A[j];
                    int total_after_Alice = S ^ A[j];
                    int min_score = LLONG_MAX;

                    for (int k = 0; k < n; k++) {
                        int x;
                        if (k == i) {
                            x = new_value;
                        } else {
                            x = A[k];
                        }
                        int score = total_after_Alice ^ x;
                        if (score < min_score) {
                            min_score = score;
                        }
                    }

                    if (min_score > best) {
                        best = min_score;
                    }
                }
            }
            cout << best << '\n';
        }
    }

    return 0;
}