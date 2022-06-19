class Solution {
public:
    string greatestLetter(string s) {
        for(char ch='z';ch>='a';--ch){
            string ss="";
            ss+=ch-32;
            if(s.find(ch)!=string::npos&&s.find(ch-32)!=string::npos)return ss;
        }
        return "";
    }
};