class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int,int>mp1,mp2;
        for(auto i:trust)mp1[i[0]]++,mp2[i[1]]++;
        for(int i=1;i<=N;i++)if(mp1.find(i)==mp1.end()&&mp2[i]==N-1)return i;
        return -1;
    }
};