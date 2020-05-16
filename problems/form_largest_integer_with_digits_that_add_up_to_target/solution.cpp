class Solution {
private:
    vector<int>v;
    int t;
    vector<pair<string,bool>>mem;
public:
    string maxx(string a,string b){
        if(a.size()>b.size())  return a;
        else if(a.size()<b.size())return b;
        else return max(a,b);
    }
    string largestNumber(vector<int>& cost, int target) {
        v=cost,t=target;
        mem=vector<pair<string,bool>>(target+5,make_pair("-1",false));
        
        string ans=solve(t).first;;
        return (ans==""?"0":ans);
    }

    pair<string,bool> solve(int cur){
        if(cur==0)
            return {"",1};

        pair<string,bool> &ret=mem[cur];
        if(ret.first!="-1")return ret;
        ret.first="";
        for(int i=0;i<9;i++){
            if(cur>=v[i]){
                pair<string ,bool>r=solve(cur-v[i]);
                if(r.second)
                    ret.first=maxx(ret.first,char(i+1+'0')+r.first),ret.second=1;
            }
        }
        return ret;
    }

};