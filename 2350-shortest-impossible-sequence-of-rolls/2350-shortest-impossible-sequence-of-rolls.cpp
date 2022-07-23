class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        return solve(0,1,rolls,k);
    }
    int solve(int i,int step,vector<int>& rolls, int k){
        if(i==rolls.size())return step;
        set<int>st;
        int idx=i;
        for(int j=i;j<rolls.size();++j){
            st.insert(rolls[j]);
            if(st.size()==k){
                idx=j;
                break;
            }
        }
        int ret=1e9;
        if(st.size()!=k)return step;
        return solve(idx+1,step+1,rolls,k);
    }
};