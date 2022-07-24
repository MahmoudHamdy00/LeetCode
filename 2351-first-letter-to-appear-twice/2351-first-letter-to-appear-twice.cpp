class Solution {
public:
    char repeatedCharacter(string s) {
        int arr[27]={0};
        for(char ch:s){
            ++arr[ch-'a'];
            if(arr[ch-'a']==2)return ch;
        }
        return '1';
    }
};