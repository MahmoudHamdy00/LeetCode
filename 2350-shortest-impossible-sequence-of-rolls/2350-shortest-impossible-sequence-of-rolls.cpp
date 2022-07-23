class Solution {
public:
    int shortestSequence(vector<int>& A, int k) {
        int res = 1;
        unordered_set<int> s;
        for (int& a : A) {
            s.insert(a);
            if (s.size() == k) {
                res++;
                s.clear();
            }
        }
        return res;
    }
};