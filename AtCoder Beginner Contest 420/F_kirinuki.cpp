#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M; long long K;
    if(!(cin>>N>>M>>K)) return 0;
    vector<string> S(N);
    for(int i=0;i<N;i++) cin>>S[i];
    vector<int> h(M,0), L(M), R(M), st;
    long long ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) h[j] = (S[i][j]=='.' ? h[j]+1 : 0);
        st.clear();
        for(int j=0;j<M;j++){
            while(!st.empty() && h[st.back()]>=h[j]) st.pop_back();
            L[j]=st.empty()?-1:st.back();
            st.push_back(j);
        }
        st.clear();
        for(int j=0;j<M;j++){
            while(!st.empty() && h[st.back()]>h[j]){
                R[st.back()]=j;
                st.pop_back();
            }
            st.push_back(j);
        }
        while(!st.empty()){
            R[st.back()]=M;
            st.pop_back();
        }
        for(int j=0;j<M;j++){
            if(h[j]==0) continue;
            long long a = j - L[j];
            long long b = R[j] - j;
            long long t = K / (long long)h[j];
            if(t<=0) continue;
            long long xmax = a < t ? a : t;
            if(xmax<=0) continue;
            long long p = t - b + 1;
            if(p<0) p=0;
            if(p>xmax) p=xmax;
            long long cnt = p*b;
            long long rem = xmax - p;
            if(rem>0){
                long long sum = rem*(t+1) - ( ( (p+1) + xmax ) * rem )/2;
                cnt += sum;
            }
            ans += cnt;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
