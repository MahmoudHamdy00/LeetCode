class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        set<pair<int,int>>st;
        for(int i=0;i<nums.size();++i){
            st.insert({nums[i],i});
        }
        for(int i=0;i<operations.size();++i){
            auto it=st.lower_bound({operations[i][0],-1});
            if(it==st.end()){
                cout<<operations[i][0]<<endl;
                continue;
            }
            int num=it->first;
            int idx=it->second;
            st.erase(it);
            num=operations[i][1];
            st.insert({num,idx});
            nums[idx]=num;
        }
        return nums;
    }
};