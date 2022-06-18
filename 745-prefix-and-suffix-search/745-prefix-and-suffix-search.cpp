class WordFilter {
    unordered_map<string,int>mp;
public:
    WordFilter(vector<string>& words) {
           for(int i=0;i<words.size();++i){
               string prefix="";
               for(int j=0;j<words[i].size();++j){
                   prefix+=words[i][j];
                   for(int k=0;k<words[i].size();++k){
                       string tmp=prefix;
                       tmp+='-';
                       tmp+=words[i].substr(k);
                       mp[tmp]=i+1;
                   }
               }
           }
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix+"-"+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */