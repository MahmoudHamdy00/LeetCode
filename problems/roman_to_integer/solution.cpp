class Solution {
public:
    int romanToInt(string s) {
        int n=0;
        for(int i=(int)s.size()-1;i>=0;i--){
            if(s[i]=='I'){
                n+= 1;
                if(i+1<(int)s.size()&&(s[i+1]=='V'||s[i+1]=='X'))n-=2;
            }
            if(s[i]=='V')n+= 5;
            if(s[i]=='X'){
                n+= 10;
            if(i+1<(int)s.size()&&(s[i+1]=='L'||s[i+1]=='C'))n-=20;
            }
            if(s[i]=='L')n+= 50;
            if(s[i]=='C'){
                n+= 100;
                if(i+1<(int)s.size()&&(s[i+1]=='D'||s[i+1]=='M'))n-=200;
            }
            if(s[i]=='D')n+= 500;
            if(s[i]=='M')n+= 1000;
        }
        return n;
    }
};