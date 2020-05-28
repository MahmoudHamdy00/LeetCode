class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>v;
        for(int i=0;i<=num;i++)v.push_back( __builtin_popcount(i));
        return v;
    }
};