class Solution {
    int k;
public:
    int distributeCookies(vector<int>& cookies, int k) {
        this->k=k;
        vector<int>v(k);
        return distributeCookies(cookies,0,v);
    }
    int distributeCookies(vector<int>& cookies, int i,vector<int>&v) {
        if(i==cookies.size()){
            int mx=0;
            for(int j=0;j<v.size();++j){
                if(!v[j])return 1e9;
                mx=max(mx,v[j]);
            }
            return mx;
        }
        int ret=1e9;
        for(int j=0;j<v.size();++j){
            v[j]+=cookies[i];
            ret=min(ret,distributeCookies(cookies,i+1,v));
            v[j]-=cookies[i];
        }
        return ret;
    }
};