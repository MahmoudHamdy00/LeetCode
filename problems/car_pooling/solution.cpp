class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pre(1005);
        for(auto it:trips){
            pre[it[1]]+=it[0];
            pre[it[2]]-=it[0];
        }
        for(int i=1;i<1002;i++){
            pre[i]+=pre[i-1];
            if(pre[i]>capacity)return false;
        }
        return pre[0]<=capacity;
    }
};