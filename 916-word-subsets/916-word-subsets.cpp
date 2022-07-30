class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>mp;
        for(string &s:words2){
            map<char,int>cur;
            for(char &ch:s)
                ++cur[ch];
            for(auto it:cur){
                mp[it.first]=max(it.second,mp[it.first]);            
                //cout<<it.first<<" "<<it.second<<" "<<cur[it.first]<<endl;
            }
        }

        vector<string>v;
        set<string>st;
        for(string &s:words1){
            if(st.count(s))continue;
            map<char,int>cur;
            for(char &ch:s)
                ++cur[ch];
            bool ok=1;
            for(auto it:mp){
                 //cout<<it.first<<" "<<it.second<<" "<<cur[it.first]<<endl;
                if(cur[it.first]<it.second){
                    ok=0;
                    break;
                }    
            }
            //cout<<"FF"<<v.size()<<endl;

            if(ok){
//cout<<s<<endl;
                v.push_back(s);
                st.insert(s);
            }
        }
        return v;        
    }
};