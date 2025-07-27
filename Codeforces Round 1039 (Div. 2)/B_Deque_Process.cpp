#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int t; 
   cin>>t;
   while(t--){
       int n; 
       cin>>n;
       vector<int> p(n);
       for(int i=0;i<n;i++) cin>>p[i];
       int l=0, r=n-1;
       deque<int> d;
       string s;
       s.reserve(n);
       auto f = [&](const deque<int>& d, int x){
           if(d.size()<4) return false;
           int a=d[d.size()-4], b=d[d.size()-3];
           int c=d[d.size()-2], e=d[d.size()-1];
           if(a<b && b<c && c<e && e<x) return true;
           if(a>b && b>c && c>e && e>x) return true;
           return false;
       };
       for(int i=0;i<n;i++){
           bool flag = (l<=r && !f(d, p[l]));
           bool ok = (l<=r && !f(d, p[r]));
           char ch;
           if(flag && !ok) {
               ch='L';
           } else if(ok && !flag) {
               ch='R';
           } else if(flag && ok){
               deque<int> dL = d;
               if(dL.size()==4) dL.pop_front();
               dL.push_back(p[l]);
               bool b1=false;
               if(l+1<=r){
                   bool l1 = !f(dL, p[l+1]);
                   bool r1 = !f(dL, p[r]);
                   if(!l1 && !r1) b1=true;
               }
               deque<int> d1 = d;
               if(d1.size()==4) d1.pop_front();
               d1.push_back(p[r]);
               bool b2=false;
               if(l<=r-1){
                   bool l2 = !f(d1, p[l]);
                   bool r2 = !f(d1, p[r-1]);
                   if(!l2 && !r2) b2=true;
               }
               if(b1 && !b2) ch='R';
               else if(b2 && !b1) ch='L';
               else ch='L';
           } else {
               ch='L';
           }
           if(ch=='L'){
               s.push_back('L');
               if(d.size()==4) d.pop_front();
               d.push_back(p[l]);
               l++;
           } else {
               s.push_back('R');
               if(d.size()==4) d.pop_front();
               d.push_back(p[r]);
               r--;
           }
       }
       cout<<s<<endl;
   }
   return 0;
}