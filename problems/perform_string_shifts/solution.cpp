class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        for(auto i:shift){
            string tmp;
            if (i[0]==0){
                tmp=s.substr(0,i[1]);
                s.erase(s.begin(),s.begin()+i[1]);
                s+=tmp;
            }
            else{
                tmp=s.substr(s.size()-i[1]);
                s.erase(s.begin()+s.size()-i[1],s.end());
                s=tmp+s;
            }
        }
    return s;
    }
};