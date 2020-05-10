class Solution {
public:
    int N;
    vector<vector<int>> edg; vector<bool> has;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       cout<<endl;
        N=n,has=hasApple;
        edg= vector<vector<int>>(n+1);
        for(int i=0;i<(int)edges.size();i++){
            edg[edges[i][0]].push_back(edges[i][1]);
        }
        return  helper().second;
    }
    pair<bool ,int> helper(int i=0,int dist=0){
        pair<bool ,int>ret={has[i],0};
        for(int nxt:edg[i]){
            pair<bool ,int> cur=helper(nxt);
            if(cur.first){
                ret.second+=cur.second+2;
                ret.first=1;
            }
        }
        return ret;
    }
};