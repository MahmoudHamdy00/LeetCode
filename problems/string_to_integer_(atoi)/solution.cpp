class Solution {
public:
    int myAtoi(string str) {
        long long num=0;
        bool si=0,ok=0;

        for(char ch:str){
            if(ok&&!isdigit(ch))break;
            if(ch!=' '&&!isdigit(ch)&&ch!='+'&&ch!='-')break;
            if(ch=='-'||ch=='+')ok=1;
            if(ch=='-')si=1;
            if(isdigit(ch))num*=10,num+=ch-'0',ok=1;
            
            if(num>INT_MAX){
                if(si)return INT_MIN;
                return INT_MAX;
            }
            if(num<INT_MIN)return INT_MIN;
        }
        if(si)num*=-1;
        if(num>INT_MAX)return INT_MAX;
        if(num<INT_MIN)return INT_MIN;
        return num;
    }
};