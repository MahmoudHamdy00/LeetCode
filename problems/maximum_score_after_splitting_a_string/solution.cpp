class Solution {
public:
    int maxScore(string s) {
        int one = count(s.begin(),s.end(), '1');
        int z=0;
        int mx=0;
        if(one==s.size()||one==0)return (int)s.size()-1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1')one--;
            else z++;
            mx=max(mx,z+one);
        }
        
        return mx;
    }
};