class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>v;
        for(auto it:matrix){
            for(int i:it){
                v.push(i);
                if(v.size()>k)v.pop();
            }
        }
        return v.top();
    }
};