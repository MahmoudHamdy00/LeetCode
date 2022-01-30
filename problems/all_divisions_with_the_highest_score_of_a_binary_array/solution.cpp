class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<long long>ones((int)nums.size()+5); 
        vector<long long>zeros((int)nums.size()+5);
        for(int i=0;i<nums.size();++i){
            zeros[i]=(nums[i]==0);
            if(i)
            zeros[i]+=zeros[i-1];
        }
        for(int i=nums.size()-1;i>=0;--i){
            ones[i]=(nums[i]==1);
            ones[i]+=ones[i+1];
        }
      

        vector<int>ret;
        long long  mx=ones[0];
        for(int i=1;i<(int)nums.size();++i){
            mx=max(mx,zeros[i-1]+ones[i]);
        }
        mx=max(mx,zeros[nums.size()-1]);
        if(mx==ones[0])ret.push_back(0);
        if(mx==zeros[(int)nums.size()-1])ret.push_back((int)nums.size());
        for(int i=1;i<(int)nums.size();++i){
            if(mx==zeros[i-1]+ones[i])ret.push_back(i);
        }
        
        return ret;
    }
};