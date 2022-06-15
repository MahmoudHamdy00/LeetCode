class Solution {
    vector<vector<int>>adj_list;
    int mem[1005];
    map<string,int>string_to_int;
    string int_to_string[1001];
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;++i){
            if(string_to_int.find(words[i])==string_to_int.end()){
                int id=string_to_int.size();
                string_to_int[words[i]]=id;
                int_to_string[id]=words[i];
            }
        }
        adj_list=vector<vector<int>>(n+1);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(is_predecessor(words[i],words[j]))adj_list[string_to_int[words[i]]].push_back(string_to_int[words[j]]);
            }
        }
        memset(mem,-1,sizeof mem);
        int ret=0;
        for(string s:words)ret=max(ret,dfs(string_to_int[s]));
        return ret;
    }
    bool is_predecessor(string &a,string& b){
        if(a.size()>=b.size())return 0;
        bool ok=0;
        for(int i=0,j=0;i<b.size();++i){
            if(a[j]==b[i])++j;
            else if(ok) return 0;
            else ok=1;
        }
        return 1;
    }
    int dfs(int node){
        int& ret=mem[node];
        if(~ret)return ret;
        ret=0;
        for(int nxt:adj_list[node]){
            ret=max(ret,dfs(nxt));
        }
        ret+=1;
        return ret;
    }
};



/*
//dfs solution
class Solution {
    map<string,vector<string>>adj_list;
    map<string,int>mp;
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(words[i].size()+1==words[j].size())adj_list[words[i]].push_back(words[j]);
            }
        }
        int ret=0;
        string t="1";
        for(string s:words)ret=max(ret,dfs(s,t));
        return ret;
    }
    bool is_predecessor(string &a,string& b){
        if(a=="1")return 1;
        if(a.size()>=b.size())return 0;
        bool ok=0;
        for(int i=0,j=0;i<b.size();++i){
            if(a[j]==b[i])++j;
            else if(ok) return 0;
            else ok=1;
        }
        return 1;
    }
    int dfs(string& node,string &prv){
        if(!is_predecessor(prv,node))return 0;
        if(mp.find(node)!=mp.end())return mp[node];
        int ret=0;
        for(string nxt:adj_list[node]){
            ret=max(ret,dfs(nxt,node));
        }
        return mp[node]=ret+1;
    }
};
*/




/*
//this is a dp solution
class Solution {
    int mem[1005][1005];
    map<string,int>string_to_int;
    string int_to_string[1001];
public:
    static bool cmp(string &a,string &b){
        return a.size()<b.size();
    }
    bool is_predecessor(string &a,string& b){
        if(a.size()>=b.size())return 0;
        bool ok=0;
        for(int i=0,j=0;i<b.size();++i){
            if(a[j]==b[i])++j;
            else if(ok) return 0;
            else ok=1;
        }
        return 1;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<words.size();++i){
            if(string_to_int.find(words[i])==string_to_int.end()){
                int id=string_to_int.size();
                string_to_int[words[i]]=id;
                int_to_string[id]=words[i];
            }
        }
        for(int i=0;i<words.size();++i)mem[words.size()][i]=1;
        for(int i=words.size()-1;i>=0;--i){
            for(int lst=0;lst<=i;++lst){
                int &ret=mem[i][lst];
                ret=mem[i+1][lst];
                if(is_predecessor(int_to_string[lst],words[i]))
                    ret=max(ret,mem[i+1][string_to_int[words[i]]]+1);
            }
        }
        int ret=0;
        for(int i=words.size()-1;i>=0;--i)
            for(int lst=0;lst<=words.size();++lst){
                    ret=max(ret,mem[i][lst]);
            }
        return ret;
    }
    int longestStrChain(int i,int lst,vector<string>& words) {
        if(i==words.size())return 0;
        int &ret=mem[i][lst];
        if(~ret)return ret;
        ret=longestStrChain(i+1,lst,words);
        if(is_predecessor(int_to_string[lst],words[i]))
            ret=max(ret,longestStrChain(i+1,string_to_int[words[i]],words)+1);
        return ret;      
    }
};
*/