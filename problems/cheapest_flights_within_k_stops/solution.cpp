class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int>distance(n,1e8);
        distance[src] = 0;
        
        for (int i = 0; i<=K;i++)
            
        {    vector<int>temp(distance);
            for (auto e : flights)
            {
                
               
                int a,b,w;
                a = e[0];
                b = e[1];
                w = e[2];
                temp[b] = min(temp[b],distance[a]+w);
                
                
                
                
            }
            
            distance = temp;
            
            
        }
        
        if (distance[dst] == 1e8)
            return -1;
        return distance[dst];
    }
};