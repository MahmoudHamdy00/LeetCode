class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pr;
        for(int i:stones)pr.push(i);
        while(!pr.empty()){
            if(pr.size()==1)return pr.top();
            int fr=pr.top();
            pr.pop();
            int sc=pr.top();
            pr.pop();
            if(fr-sc==0)continue;
            pr.push(abs(fr-sc));
        }
        return 0;
    }
};