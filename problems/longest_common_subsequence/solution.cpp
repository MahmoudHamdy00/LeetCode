class Solution {
public:
    int mem[1002][1002];
    string s,k;
    int longestCommonSubsequence(string text1, string text2) {
        s=text1,k=text2;
        memset(mem, -1, sizeof mem);
        return solve(0,0);
    }
    int solve(int i,int j){
        if (i==(int)s.size()||j==(int)k.size())return 0;
        int &ret=mem[i][j];
        if(~ret)return ret;
        ret=solve(i+1,j);
        ret=max(solve(i,j+1),ret);
        if(s[i]==k[j])ret=max(ret,1+solve(i+1,j+1));
        return ret;
    }
};