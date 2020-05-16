class Solution {
private:
    int gcd(int a, int b) {
	    return (b == 0 ? a : gcd(b, a % b));
    }
public:
    vector<string> simplifiedFractions(int n) {
        set<string>st;
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                int g=gcd(a,b);
                int aa=a/g,bb=b/g;
                string tmp=to_string(aa);
                tmp+='/';
                tmp+=to_string(bb);
                st.insert(tmp);
            }
        }
        vector<string>v;
        for(auto it:st)v.push_back(it);
        return v;
    }
};