class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ans="";
        char prv=' ';
        for(int i=0;i<sentence.size();++i){
            if(prv==' '&&sentence[i]=='$'&&i+1<sentence.size()&&sentence[i+1]>='0'&&sentence[i+1]<='9'){
                ++i;        
                double tmp=0;
                string tmp2="";
                while(i<sentence.size()&&sentence[i]>='0'&&sentence[i]<='9'){
                    tmp=tmp*10+sentence[i]-'0';
                    tmp2+=sentence[i];
                    ++i;
                }
                if(i==sentence.size()||sentence[i]==' '){
                    tmp-=tmp*discount/100.0;
                    
                    std::ostringstream streamObj2;
                    // Set Fixed -Point Notation
                    streamObj2 << std::fixed;
                    streamObj2 << std::setprecision(2);
                    //Add double to stream
                    streamObj2 << tmp;
                    // Get string from output string stream
                    std::string strObj2 = streamObj2.str();

                    ans+="$"+strObj2;
                    ans+=' ';
                }
                else {
                    ans+="$"+tmp2;
                    ans+=sentence[i];
                }
            }
            else{
               ans+=sentence[i];
            }
            prv=sentence[i];
        }
        while(ans.back()==' ')ans.pop_back();
        return ans;
    }
};