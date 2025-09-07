#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   int k;
   cin >> n >> k;
   int sz = 1LL << n;
   vector<int> a;
   a.reserve(sz);
   a.push_back(k);
   for(int i = 0; i < n; i++){
       vector<int> b;
       b.reserve(a.size()*2);
       for(int x : a){
           int l = x / 2;
           int r = x - l;
           b.push_back(l);
           b.push_back(r);
       }
       a.swap(b);
   }
   int u = 0;
   int mn = LLONG_MAX, mx = LLONG_MIN;
   for(int x : a){
       mn = min(mn, x);
       mx = max(mx, x);
   }
   u = mx - mn;
   vector<int> c = a;
   int cu = u;
   while(c.size() > 1){
       int dmn = LLONG_MAX, dmx = LLONG_MIN;
       for(int x : c){
           dmn = min(dmn, x);
           dmx = max(dmx, x);
       }
       cu = max(cu, dmx - dmn);
       vector<int> b;
       b.reserve(c.size()/2);
       for(size_t i = 0; i < c.size(); i += 2){
           b.push_back(c[i] + c[i+1]);
       }
       c.swap(b);
   }
   u = cu;
   cout << u << "\n";
   for(size_t i = 0; i < a.size(); i++){
       cout << a[i] << (i+1 < a.size() ? ' ' : '\n');
   }
   return 0;
}