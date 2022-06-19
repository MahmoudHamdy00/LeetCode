class Solution {
    unordered_map<string,priority_queue<string>>mp;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(string s:products){
            string cur="";
            for(char ch:s){
                cur+=ch;
                mp[cur].push(s);
                if(mp[cur].size()>3)mp[cur].pop();
            }
        }
        vector<vector<string>>ret;
        string s="";
        for(char ch:searchWord){
            s+=ch;
            int idx=mp[s].size()-1;
            vector<string>c(idx+1);
            while(!mp[s].empty()){
                c[idx]=mp[s].top();
                mp[s].pop();
                --idx;
            }
            ret.push_back(c);
        }
        return ret;;
    }
};