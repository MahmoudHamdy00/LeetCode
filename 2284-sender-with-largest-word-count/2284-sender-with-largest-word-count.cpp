class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int>mp;
        for(int i=0;i<messages.size();++i){
            int cnt=1;
            for(char ch:messages[i]){
                if(ch==' ')++cnt;
            }
            mp[senders[i]]+=cnt;
        }
        int mx=0;
        for(auto it:mp)mx=max(mx,it.second);
        string ans="";
        for(auto it:mp)if(it.second==mx){
            if(it.first>ans||ans=="") ans=it.first;
        }
        return ans;
    }
};