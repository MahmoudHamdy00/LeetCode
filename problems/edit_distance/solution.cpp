class Solution {
    string s,k;
    int mem[1000][1000];
public:
    int minDistance(string word1, string word2) {
        s=word1,k=word2;
        memset(mem,-1,sizeof mem);
        return solve(0,0);
    }
    int solve(int i,int j) {
        if(j==k.size())return s.size()-i;
        if(i==s.size())return k.size()-j;
        if(~mem[i][j])return mem[i][j];
        int &ret=mem[i][j]=0;
        if(s[i]!=k[j]){
            ret=solve(i+1,j+1)+1; //replace
            ret=min(ret,solve(i+1,j)+1);  //remove
            ret=min(ret,solve(i,j+1)+1);  //insert
        }
        else ret=solve(i+1,j+1);
        return ret;
    }
};