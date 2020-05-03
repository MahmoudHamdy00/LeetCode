class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>all;
        set<string>in;
        for(auto it:paths){
            all.insert(it[0]);
            in.insert(it[0]);
            all.insert(it[1]);
        }
        for(auto it:all){
            if(in.find(it)==in.end())return it;
        }
        return NULL;
    }
};