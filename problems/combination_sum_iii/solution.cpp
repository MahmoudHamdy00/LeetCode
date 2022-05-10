class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        for(int i=1;i<=(1<<9);++i){
            vector<int>tmp;
            int sum=0;
            for(int j=0;j<9;++j){
                if(i&(1<<j)){
                    sum+=j+1;
                    tmp.push_back(j+1);                    
                }
            }
            if(sum==n&&tmp.size()==k){
                ans.push_back(tmp);
            }
        }
        return ans;
    }
    
};