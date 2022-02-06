class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg=num<0;
        if(neg)num*=-1;
        string s=to_string(num);
        if(neg)sort(s.rbegin(),s.rend());
        else sort(s.begin(),s.end());
        int idx=0;
        for(int i=0;i<s.size();++i)if(s[i]!='0'){
            idx=i;
            break;
        }
        swap(s[0],s[idx]);
        num=stoll(s);
        if(neg)num*=-1;
        return num;
    }
};