class Solution {
    int mem[605][105][105];
public:
    int findMaxForm(vector<string>& strs, int mm, int nn) {
        memset(mem,0,sizeof mem);
        vector<vector<int>>v;
        for(auto it:strs){
            int ones=0,zeros=0;
            for(char ch:it){
                ch=='0'?++zeros:++ones;
            }
            v.push_back({zeros,ones});
        }
        for(int i=v.size()-1;i>=0;--i){
            for(int m=0;m<=mm;++m){
                for(int n=0;n<=nn;++n){    
                    int &ret=mem[i][m][n];
                    ret=mem[i+1][m][n];  
                    if(m>=v[i][0]&&n>=v[i][1])
                        ret=max(ret,mem[i+1][m-v[i][0]][n-v[i][1]]+1);
                }
            }
        }
       for(int i=v.size()-1;i>=0;--i){
            cout<<mem[i][mm][nn]<<" ";
        }
        return mem[0][mm][nn];
    }
};