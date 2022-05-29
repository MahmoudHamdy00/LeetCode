class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mx=0;
        for(int i=0;i<words.size();++i){
            int frq[26]={0};
            for(char ch:words[i])++frq[ch-'a'];
            for(int j=i+1;j<words.size();++j){
                bool ok=1;
                for(char ch:words[j]){
                    if(frq[ch-'a']){
                        ok=0;
                        break;
                    }
                }
                if(ok)mx=max(mx,(int)(words[i].size()*words[j].size()));
            }   
        }
        return mx;
    }
};