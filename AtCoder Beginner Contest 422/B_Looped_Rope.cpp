#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for (int i = 0; i < h; i++) {
        cin >> v[i];
    }
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (v[i][j] == '#') {
                int count = 0;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w && v[ni][nj] == '#') {
                        count++;
                    }
                }
                if (count != 2 && count != 4) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}