class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<(int)nums.size();i++){
            if(!nums[i])nums[i]--;;
            
        }
        vector<int>pre;
        pre.push_back(0);
       for(int i=0;i<(int)nums.size();i++){
            pre.push_back(pre.back()+nums[i]);
        }
        map<int,int>mp;
        int ret=0;
       for(int i=0;i<(int)pre.size();i++){
            if(mp.find(pre[i])!=mp.end()){
                ret=max(ret,i-mp[pre[i]]);
           }
           else 
               mp[pre[i]]=i;
        }
        return ret;
        
    }
};