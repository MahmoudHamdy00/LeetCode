class Solution {
public:
    string maxValue(string n, int x) {
        if(n[0]=='-'){
             for(int i=0;i<n.size();i++){
                int d=n[i]-'0';
                if(d>x){
	                n.insert(n.begin()+i, x+'0');
                    return n;
                }
            }
        }
        else{
            for(int i=0;i<n.size();i++){
                int d=n[i]-'0';
                if(d<x){
	                n.insert(n.begin()+i, x+'0');
                    return n;
                }
            }
        }
        n+=x+'0';
        return n;
    }
};