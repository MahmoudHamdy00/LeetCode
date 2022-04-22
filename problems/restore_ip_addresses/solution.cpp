class Solution {
    map<string,bool>mp;
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        GenerateAll(0,0,"",0,0,s,ans);
        return ans;
    }
    void GenerateAll(int i,int lst,string cur,bool take,int cnt,string &s,vector<string>&ans){
        //cout<<i<<" "<<lst<<" "<<cur<<endl;
        if(lst>255)return;
        if(i==s.size()){
           // cur.pop_back();
            cur+=to_string(lst);
            //cout<<cur<<endl;
            if(cur.size()==s.size()+3&&!mp[cur]&&cnt==3)
                ans.push_back(cur),mp[cur]=true;
            return;
        }
        GenerateAll(i+1,lst*10+(s[i]-'0'),cur,1,cnt,s,ans);
        if(take)
            GenerateAll(i,0,cur+to_string(lst)+".",0,cnt+1,s,ans);
    }
};