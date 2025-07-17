#include <bits/stdc++.h>
using namespace std;
typedef long double                         ld;
typedef unsigned                            ui;
typedef long long                           lli;
typedef unsigned long long                  ulli;
typedef vector<int32_t>                     vi;
typedef vector<ld>                          vld;
typedef vector<ui>                          vui;
typedef vector<lli>                         vlli;
typedef vector<ulli>                        vulli;
typedef list<int32_t>                       lsi;
typedef list<ld>                            lsld;
typedef list<ui>                            lsui;
typedef list<lli>                           lslli;
typedef list<ulli>                          lsulli;
typedef set<int32_t>                        si;
typedef set<ld>                             sld;
typedef set<ui>                             sui;
typedef set<lli>                            slli;
typedef set<ulli>                           sulli;

typedef pair<lli, lli>                      pii;
typedef pair<lli, lli>                      pll;

#define int                                 int64_t
#define endl                                "\n"
#define inp(n)                              int n; cin >> n
#define Inp(n)                              lli n; cin >> n
#define inpstr(s)                           string s; cin >> s
#define inp2(a,b)                           int a,b; cin >> a >> b
#define Inp2(a,b)                           lli a,b; cin >> a >> b
#define inparr(arr,n)                       int arr[n]; f0(t_ind, n) cin >> arr[t_ind]
#define Inparr(arr,n)                       lli arr[n]; f0(t_ind, n) cin >> arr[t_ind]
#define f0(i,n)                             for(int32_t i = 0; i <  (n); i++)
#define f1(i,n)                             for(int32_t i = 1; i <= (n); i++)
#define rep0(i,l,r)                         for(int32_t i=(l); i <  (r); i++)
#define rep1(i,l,r)                         for(int32_t i=(l); i <= (r); i++)
#define testIn                              cin >> test
#define tests                               for(int32_t testNo=1; testNo <= (test); testNo++)
#define all(x)                              (x).begin(), (x).end()
#define rall(x)                             (x).rbegin(), (x).rend()
#define asrt(v)                             sort(all(v))
#define dsrt(v)                             sort(rall(v))
#define revStr(str)                         string(rall(str))
#define len(a)                              ((int64_t)(a).size())
#define front_zero(n)                       __builtin_clzll(n)
#define back_zero(n)                        __builtin_ctzll(n)
#define total_one(n)                        __builtin_popcountll(n)
#define lcm(a, b)                           (((a)*(b))/gcd(a,b))
#define mem(a, b)                           memset(a, b, sizeof(a))
#define pb                                  push_back
#define pf                                  push_front
#define mp                                  make_pair
#define ff                                  first
#define ss                                  second
#define maxi                                maximize
#define mini                                minimize   
#define yes                                 cout << "yes" << endl
#define no                                  cout << "no" << endl
#define Yes                                 cout << "Yes" << endl
#define No                                  cout << "No" << endl
#define YES                                 cout << "YES" << endl
#define NO                                  cout << "NO" << endl
#define finish                              return 0
#define clean                               fflush(stdout)
#define Inf                                 (int32_t)(1e9)
#define INF                                 (lli)(1e18)
#define Eps                                 (ld)(1e-9)
#define EPS                                 (ld)(1e-18)
#define PI                                  (ld)(3.141592653589793238462643383279502884197169L)
#define MOD                                 (int32_t)(1e9+7)
#define MXN                                 (int32_t)(1e5+7)

long long pow(long long a, long long b) {
    long long ans = 1;
    for(int i=0; i<b; i++){
        ans = ans*a;
    }
    return ans;
}

template<typename dataType1>
inline void print(dataType1 a) {cout << a << endl;}

template<typename dataType1, typename dataType2>
inline void print(dataType1 a, dataType2 b) {cout << a << " " << b << endl;}

template<typename dataType1, typename dataType2, typename dataType3>
inline void print(dataType1 a, dataType2 b, dataType3 c) {cout << a << " " << b << " " << c << endl;}

template<typename dataType1, typename dataType2, typename dataType3, typename dataType4>
inline void print(dataType1 a, dataType2 b, dataType3 c, dataType4 d) {cout << a << " " << b << " " << c << " " << d << endl;}

template<typename dataType>
inline void printarr(dataType* arr, int32_t n) {f0(i,n) cout << arr[i] << " "; cout << endl;}

template<typename dataType>
inline dataType abs(dataType k) {if (k >= 0) return k; else return (-k);}

template<typename dataType>
inline bool isEqual(dataType a, dataType b) {return (abs((dataType)(a-b)) < 1e-9);}

template<typename dataType>
inline void maximize(dataType &a, dataType b) {if (a < b) a = b;}

template<typename dataType>
inline void minimize(dataType &a, dataType b) {if (a > b) a = b;}


int32_t solve1(int32_t testNo) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n),v0, v1(n), v2(n);
    v0.reserve(3LL*n+1);
    v0.push_back(k);
    f0(i,n){
        cin>>v[i]>>v1[i]>>v2[i];
        v0.push_back(v[i]);
        v0.push_back(v1[i]);
        v0.push_back(v2[i]);
    }
    asrt(v0);
    v0.erase(unique(all(v0)), v0.end());
    int M = v0.size();
    vector<int> l(n), r(n), a(n);
    auto temp = [&](int x) {
        return int(lower_bound(all(v0), x) - v0.begin());
    };
    f0(i,n){
        l[i] = temp(v[i]);
        r[i] = temp(v1[i]);
        a[i] = temp(v2[i]);
    }
    int start = temp(k);
    vector<vector<int>> seg(4*M+5);
    f0(i,n){
        int l1 = l[i];
        int r1 = r[i];
        stack<array<int,3>> st;
        st.push({1,0,M-1});
        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            int node = cur[0], left = cur[1], right = cur[2];
            if(l1 <= left && right <= r1){
                seg[node].pb(i);
            } else {
                int mid = (left + right) >> 1;
                if(l1 <= mid){
                    st.push({node*2, left, mid});
                }
                if(r1 > mid){
                    st.push({node*2+1, mid+1, right});
                }
            }
        }
    }
    vector<char> vc(M);
    vector<char> u(n);
    queue<int> q;
    vc[start] = 1;
    q.push(start);
    int ans = v0[start];
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        maxi(ans, v0[pos]);
        int node = 1, left = 0, right = M-1;
        while(true){
            if(!seg[node].empty()){
                for(int idx : seg[node]){
                    if(!u[idx]){
                        u[idx] = 1;
                        int nxt = a[idx];
                        if(!vc[nxt]){
                            vc[nxt] = 1;
                            q.push(nxt);
                        }
                    }
                }
                seg[node].clear();
            }
            if(left == right) break;
            int mid = (left + right) >> 1;
            if(pos <= mid){
                node = node*2;
                right = mid;
            } else {
                node = node*2+1;
                left = mid+1;
            }
        }
    }
    print(ans);
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
    testIn;
    tests {
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
