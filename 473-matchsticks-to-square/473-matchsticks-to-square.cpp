class Solution {
    int s1,s2,s3,s4;
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.rbegin(), matchsticks.rend());
        int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum % 4 != 0) return false;
        s1=s2=s3=s4=sum/=4;
        return solve(0,matchsticks);
    }
    int solve(int i,vector<int>& matchsticks){
        if(i==matchsticks.size())return s1==s2&&s2==s3&&s3==s4&&s1==0;
        s1-=matchsticks[i];
        if(s1>=0&&solve(i+1,matchsticks))return true; 
        s1+=matchsticks[i];
        s2-=matchsticks[i];
        if(s2>=0&&solve(i+1,matchsticks))return true; 
        s2+=matchsticks[i];
        s3-=matchsticks[i];
        if(s3>=0&&solve(i+1,matchsticks))return true; 
        s3+=matchsticks[i];
        s4-=matchsticks[i];
        if(s4>=0&&solve(i+1,matchsticks))return true; 
        s4+=matchsticks[i];
        return false;
    }
};