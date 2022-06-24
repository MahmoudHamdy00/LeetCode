class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        long long sum=0;
        for(int i:target)sum+=i,pq.push(i);
        int t=0;
        while(!pq.empty()&&pq.top()!=1){
            int cur=pq.top();pq.pop();
            sum-=cur;
            if(cur<=sum||sum<1)return false;
            cur%=sum;
            sum+=cur;
            if(!cur)cur+=sum;
            pq.push(cur);
        }
        return true;
    }
};
