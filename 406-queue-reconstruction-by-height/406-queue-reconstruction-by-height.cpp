class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>ret;
        for(int i=0;i<people.size();++i){
            ret.insert(ret.begin()+people[i][1],people[i]);
        }
        return ret;
    }
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]<b[1];
        return a>b;
    }
};