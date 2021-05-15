class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ret=partition(nums,0,nums.size()-1,k-1);
        return ret;
    }
    int partition(vector<int>& numbers, int startRange, int endRange, int k) {
	if (startRange > endRange)return -1;
    int r= rand() % (endRange - startRange + 1) + startRange;
    swap(numbers[endRange],numbers[r]);
	int idx = startRange;
	int val = numbers[endRange];
	for (int i = startRange; i < endRange; i++) {
		if (numbers[i] > val) {
			swap(numbers[i], numbers[idx]);
			idx++;
		}
	}
	swap(numbers[endRange], numbers[idx]);
	if (idx == k) {
		return numbers[idx];
	}
	else if (idx < k) {
		return partition(numbers, idx + 1, endRange, k);
	}
	else
		return partition(numbers, startRange, idx - 1, k);
}
};