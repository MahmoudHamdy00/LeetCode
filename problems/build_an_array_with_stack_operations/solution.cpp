class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i=0,cur=1;
        vector<string>v;
        for(int j=1;j<=n;j++){
            v.push_back("Push");

            if(j!=target[i])
                v.push_back("Pop");
            else i++;
            if(i==(int)target.size())return v;

        }
        return v;
    }
};