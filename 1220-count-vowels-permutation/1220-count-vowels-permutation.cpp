class Solution {
    int n,mod;
    int mem[20005][6];
    map<char,int>mp;
public:
    int countVowelPermutation(int n) {
        this->n=n;mod=1e9+7;
        memset(mem,-1,sizeof mem);
        mp={{'a',0},{'e',1},{ 'i',2},{ 'o',3}, {'u',4},{'0',5}};
        return solve(0,'0');
    }
    int solve(int i,char prv){
        if(i==n)return 1;
        int &ret=mem[i][mp[prv]];
        if(~ret)return ret;
        if(prv=='0') ret=(((solve(i+1,'a')+solve(i+1,'e'))%mod+solve(i+1,'i'))%mod+solve(i+1,'o'))%mod+solve(i+1,'u');
        if(prv=='a') ret=solve(i+1,'e');    
        if(prv=='e') ret=solve(i+1,'a')+solve(i+1,'i');
        if(prv=='i') ret=((solve(i+1,'a')+solve(i+1,'e'))%mod+solve(i+1,'o'))%mod+solve(i+1,'u');
        if(prv=='o') ret=solve(i+1,'i')+solve(i+1,'u');   
        if(prv=='u') ret=solve(i+1,'a');   
        return ret%=mod;
    }
};