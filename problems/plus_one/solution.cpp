class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        digits.back()++;
        for(int i=n-1;i>=1;i--){
            if(digits[i]==10)digits[i]=0,digits[i-1]++;
        }
        if(digits.front()==10){
            digits.front()=0;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};