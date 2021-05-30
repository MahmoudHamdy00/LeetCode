class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return getNum(firstWord)+getNum(secondWord)==getNum(targetWord);
    }
    long long  getNum(string s){
        long long ret=0;
        for(char &ch:s){
           ch-='0'+1;
        }
        return stoi(s);
    }
};