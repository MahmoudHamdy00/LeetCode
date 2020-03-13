class Solution {
public:
    string generateTheString(int n) {
        string ans((n&1)?n:n-1,'a');;
       
        return (n&1)?ans:ans+'b';
    }
};