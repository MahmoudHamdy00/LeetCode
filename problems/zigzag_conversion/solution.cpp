class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        int i=0,k=0;
        string arr[1005];
        for(int i=0;i<1000;i++){
                arr[i]="";
            
        }
        while(k<s.size()){
            for(;i<numRows&&k<s.size();i++){
                arr[i]+=s[k++];
            }
            i-=2;
            for(;i>=0&&k<s.size();i--){
                arr[i]+=s[k++];
            }
            i+=2;
        }
        string str="";
        for(int i=0;i<numRows;i++){
          str+=arr[i];   
        }
        return str;
    }
};