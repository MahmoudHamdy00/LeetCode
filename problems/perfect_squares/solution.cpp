class Solution {
        int target;    vector<int>perfect;
    vector<vector<int>>mem;
public:
    int numSquares(int n) {
        target=n;
        for(int i=1;i*i<=n;i++){
            perfect.push_back(i*i);
        }
        mem=vector<vector<int>>(perfect.size(),vector<int>(n+1,-1));
        return helper();
    }
    int helper(int i=0,int n=0){
        if(n==target)return 0;
        if(i==perfect.size()||perfect[i]>target||n>target)return 1e9;
        int &ret=mem[i][n];
        if(~ret)return ret;
        ret=min(helper(i+1,n),helper(i,n+perfect[i])+1);
        
        return ret;
    }
};