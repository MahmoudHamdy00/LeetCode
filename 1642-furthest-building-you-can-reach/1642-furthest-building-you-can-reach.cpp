class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        priority_queue<int,vector<int>,greater<int>>ladders_used;
        for(int i=0;i<heights.size()-1;++i){
            int need=heights[i+1]-heights[i];
            if(need<=0)continue;
            if(ladders){
                ladders_used.push(need);
                --ladders;
                continue;
            }
            pq.push(need);
            bricks-=need;
            while(!ladders_used.empty()&&ladders_used.top()<pq.top()){
                int change_from_bricks_to_ladder=pq.top();pq.pop();
                int change_from_ladder_to_bricks=ladders_used.top();ladders_used.pop();
                pq.push(change_from_ladder_to_bricks);
                ladders_used.push(change_from_bricks_to_ladder);
                bricks+=change_from_bricks_to_ladder;
                bricks-=change_from_ladder_to_bricks;
            }
            if(bricks<0)return i;
        }
        return heights.size()-1;
    }
};