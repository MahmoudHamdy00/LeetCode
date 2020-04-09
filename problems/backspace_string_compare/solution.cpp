class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s="";
        for (int i=0;i <S.size ();i++){
           if(S [i]!='#')s +=S [i];
            else if (!s.empty())s.pop_back () ;
        }
          string t="";
        for (int i=0;i <
             T.size ();i++){
           if(T [i]!='#')t+=T[i];
            else if (!t.empty())t.pop_back () ;
        }
        return s==t;
    }
};