class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();++i){
            int need=target-numbers[i];
            int idx=lower_bound(numbers.begin()+i+1,numbers.end(),need)-numbers.begin();
            if(idx!=numbers.size()&&need==numbers[idx])return {i+1,idx+1};
        }
        return {};
    }
};