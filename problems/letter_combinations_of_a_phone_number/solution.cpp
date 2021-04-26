class Solution {
private:
    vector<string> ret;
    int n;
    string s,dig;
    map<int,string>mp;
public:
    vector<string> letterCombinations(string digits) {
        n=digits.size();
        if(!n)return ret;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        s="",dig=digits;
        helper();
        return ret;
    }
    void helper(int i=0){
        if(i==n){
            ret.push_back(s);
        }
        for(char &ch:mp[dig[i]-'0']){
            s+=ch;
            helper(i+1);
            s.pop_back();
        }
        return;
    }
};