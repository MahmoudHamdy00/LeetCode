class Solution {
    int mem[501][501];
public:
    int minDistance(string word1, string word2) {
        memset(mem,-1,sizeof mem);
        return minDistance(word1,word2,0,0);
    }
    int minDistance(string &word1, string &word2,int i,int j) {
        if(i==word1.size()&&j==word2.size())return 0;
        if(i==word1.size()||j==word2.size())return max(word1.size()-i,word2.size()-j);
        int &ret=mem[i][j];
        if(~ret)return ret;
        ret=minDistance(word1,word2,i+1,j)+1;
        ret=min(ret,minDistance(word1,word2,i,j+1)+1);
        if(word1[i]==word2[j])ret=min(ret,minDistance(word1,word2,i+1,j+1));
        return ret;
    }
};