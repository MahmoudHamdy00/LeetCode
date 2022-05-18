class Solution {
    static const int N=1e5;
    int lowLink[N],dfsNum[N],curdfsNum=0;
    vector<vector<int>>adj;
    set<vector<int>>bridges;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj=vector<vector<int>>(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        tarjan(0,-1);
        vector<vector<int>>bridges_vector;
        for(auto it:bridges)bridges_vector.push_back(it);
        return bridges_vector;
    }
    void tarjan(int node, int per) {
        lowLink[node] = dfsNum[node] = ++curdfsNum;
        for (auto child : adj[node]) {
            if (!dfsNum[child]) {
                tarjan(child, node);
                lowLink[node] = min(lowLink[node], lowLink[child]);
                if (lowLink[child] > dfsNum[node]) {
                    bridges.insert({ min(node,child), max(node,child) });
                }
            }
            else if (child != per)
                lowLink[node] = min(lowLink[node], dfsNum[child]);
	}
}
};