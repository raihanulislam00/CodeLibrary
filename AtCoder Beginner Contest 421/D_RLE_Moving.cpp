#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Rt, Ct, Ra, Ca;
    cin >> Rt >> Ct >> Ra >> Ca;
    int N;
    int m, L;
    cin >> N >> m >> L;
    vector<char> v1(m);
    vector<int> v2(m);
    for(int i = 0; i < m; i++){
        cin >> v1[i] >> v2[i];
    }
    vector<char> t1(L);
    vector<int> t2(L);
    for(int i = 0; i < L; i++){
        cin >> t1[i] >> t2[i];
    }
    int trg1 = Ra - Rt;
    int trg2 = Ca - Ct;
    int cur1 = 0, curC = 0;
    int ans = 0;
    int i = 0, j = 0;
    int cnt1 = (m>0? v2[0] : 0), cnt2 = (L>0? t2[0] : 0);
    while(i < m && j < L){
        int k = min(cnt1, cnt2);
        char sc = v1[i], tc = t1[j];
        int dr1 = 0, dc1 = 0, dr2 = 0, dc2 = 0;
        if(sc == 'U') dr1 = -1;
        if(sc == 'D') dr1 = 1;
        if(sc == 'L') dc1 = -1;
        if(sc == 'R') dc1 = 1;
        if(tc == 'U') dr2 = -1;
        if(tc == 'D') dr2 = 1;
        if(tc == 'L') dc2 = -1;
        if(tc == 'R') dc2 = 1;
        int dr = dr1 - dr2;
        int dc = dc1 - dc2;
        if(dr == 0 && dc == 0){
            if(cur1 == trg1 && curC == trg2){
                ans += k;
            }
        } else if(dr == 0){
            if(cur1 == trg1){
                int temp = trg2 - curC;
                if(dc != 0 && temp % dc == 0){
                    int h = temp / dc;
                    if(h >= 1 && h <= k){
                        ans++;
                    }
                }
            }
        } else if(dc == 0){
            if(curC == trg2){
                int temp = trg1 - cur1;
                if(dr != 0 && temp % dr == 0){
                    int h = temp / dr;
                    if(h >= 1 && h <= k){
                        ans++;
                    }
                }
            }
        } else {
            int r1 = trg1 - cur1;
            int c1 = trg2 - curC;
            if(r1 % dr == 0 && c1 % dc == 0){
                int h1 = r1 / dr;
                int h2 = c1 / dc;
                if(h1 == h2 && h1 >= 1 && h1 <= k){
                    ans++;
                }
            }
        }
        cur1 += dr * k;
        curC += dc * k;
        cnt1 -= k;
        cnt2 -= k;
        if(cnt1 == 0){
            i++;
            if(i < m) cnt1 = v2[i];
        }
        if(cnt2 == 0){
            j++;
            if(j < L) cnt2 = t2[j];
        }
    }
    cout << ans;
    return 0;
}
