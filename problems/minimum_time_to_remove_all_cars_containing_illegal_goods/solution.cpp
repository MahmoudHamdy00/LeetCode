class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        vector<int>L(n+1),R(n+1);
        L[0]=(s[0]=='1');
        for(int i=1;i<n;++i){
            if(s[i]=='1')L[i]=min(L[i-1]+2,i+1);
            else L[i]=L[i-1];
        }
        R[n-1]=(s[n-1]=='1');
        for(int i=n-1;i>=0;--i){
            if(s[i]=='1')R[i]=min(R[i+1]+2,(n-i));
            else R[i]=R[i+1];
        }
        int ans=min(L[n-1],R[0]);
        for(int i=0;i<n-1;++i){
            ans=min(ans,L[i]+R[i+1]);
        }
        return ans;
    }
};