class Solution {
private:
    vector<int> accu;
    int sum;
public:
    Solution(vector<int>& w) {
        sum = 0;
        for(auto &num:w){
            sum += num;
            accu.emplace_back(sum);
        }
    }
    
    int pickIndex() {
        int left = 0, right = accu.size();
        int tgt = rand() % sum + 1;
        while(left !=right){
            int mid = left + (right-left) / 2;
            if(accu[mid] < tgt) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};