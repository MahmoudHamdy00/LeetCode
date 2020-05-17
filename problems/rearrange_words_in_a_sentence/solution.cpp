class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<pair<int,int>,string>>s;
        string tmp="";
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if(tmp!="")s.push_back({{tmp.size(),0},tmp});
                tmp="";
            }
            else tmp+=text[i];
       
        }
        if(tmp!="")s.push_back({{tmp.size(),0},tmp});
        for(int i=0;i<s.size();i++){
            s[i].first.second=i;
        }
        sort(s.begin(),s.end());
        string ans="";
        for(auto c:s)ans+=c.second+' ';
        for(char& ch:ans)if(isalpha(ch))ch=tolower(ch);
        ans.pop_back();
        ans[0]=toupper(ans[0]);
        return ans;
    }
};