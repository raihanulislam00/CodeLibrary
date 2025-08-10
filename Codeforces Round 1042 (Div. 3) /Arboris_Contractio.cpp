#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            int u, v;
            cin >> u >> v;
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> a(n + 1);
        vector<int> d(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
            d[u]++;
            d[v]++;
        }
        vector<bool> v1(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (d[i] == 1)
            {
                v1[i] = true;
            }
        }
        int total = 0;
        int max = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v1[i])
            {
                total++;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            int x = 0;
            for (int v : a[j])
            {
                if (v1[v])
                {
                    x++;
                }
            }
            max = std::max(max, x);
        }

        cout << total - max << endl;
    }
    return 0;
}