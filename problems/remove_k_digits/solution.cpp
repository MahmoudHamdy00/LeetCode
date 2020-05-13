class Solution {
public:
    string removeKdigits(string num, int k) {
        if((int)num.size()<=k)return "0";
        for(int i=0;i<(int)num.size()-1&&k;i++){
            i=max(i,0);
            if(num[i]>num[i+1]){
                num.erase(i,1);
                k--,i-=2;

            }
        }
        string tmp=num;
        int i=(int)tmp.size()-1;
        sort(tmp.begin(),tmp.end());
        while(k--){
            if(i<0)break;
            int idx=num.find(tmp[i--]);
            num.erase(idx,1);
        }
        for(i=0;i<(int)num.size();i++)if(num[i]!='0')break;
        if(i==(int)num.size())return "0";
        return num.substr(i);
    }
};