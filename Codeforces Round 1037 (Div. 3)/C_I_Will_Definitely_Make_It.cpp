#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
#define f0(i,n) for(int32_t i = 0; i < (n); i++)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define finish return 0

int32_t solve1(int32_t testNo) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    f0(i, n) cin >> a[i];
    int temp = a[k - 1];
    int temp1 = *max_element(a.begin(), a.end());
    if (temp == temp1) {
        YES;
        finish;
    }
    set<int> st;
    for (int x : a) st.insert(x);
    vector<int> b(st.begin(), st.end());
    int idx = lower_bound(b.begin(), b.end(), temp) - b.begin();
    bool flag = true;
    for (int i = idx; i < (int)b.size() - 1; i++) {
        if (b[i + 1] - b[i] > temp) {
            flag = false;
            break;
        }
    }
    if (flag) YES;
    else NO;
    finish;
}

int32_t solve2(int32_t testNo) { finish; }
int32_t solve3(int32_t testNo) { finish; }

int32_t main() {
    #if defined __has_include
        #if __has_include("LOCAL.hh")
            #include "LOCAL.hh"
        #endif
    #endif
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        using namespace std::chrono;
        cout << fixed << setprecision(9);
        auto begin = steady_clock::now();
    #else
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif
    int32_t test = 1;
    cin >> test;
    for (int32_t testNo = 1; testNo <= test; testNo++) {
        solve1(testNo);
    }
    #ifdef LOCAL
        auto end = steady_clock::now();
        cout << "\nTime : " 
             << (ld)duration_cast<nanoseconds>
                (end - begin).count()/1000000000 
             << "s" << endl;
    #endif
    finish;
}