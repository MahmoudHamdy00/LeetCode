class Solution {
public:
    string decodeMessage(string key, string message) {
        int idx[27]={0};
        int j=0;
        for(int i=0;i<key.size();++i){
            if(key[i]==' ')continue;
            if(idx[key[i]-'a']==0){
                idx[key[i]-'a']=++j;;
            }
        }
        for(char &ch:message){
            if(ch==' ')continue;
            ch=idx[ch-'a']+'a'-1;
        }
        return message;
    }
};