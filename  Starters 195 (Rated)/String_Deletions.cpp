#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)

int main(){
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int temp = 1;
        FOR(i,1,n) {
            if (s[i] == s[0]) temp++;
            else break;
        }
        int suf = 1;
        FOR(i,1,n) {
            if (s[n-1-i] == s[n-1]) suf++;
            else break;
        }
        if (s[0] == s[n-1]) {
            if (temp + suf >= n) cout << n << endl;
            else cout << temp + suf << endl;
        } else {
            if (temp + suf >= n) cout << n << endl;
            else {
                char a = s[temp];
                char b = s[n-1-suf];
                if (a == b) cout << temp + suf << endl;
                else cout << temp + suf + 1 << endl;
            }
        }
    }
    return 0;
}
