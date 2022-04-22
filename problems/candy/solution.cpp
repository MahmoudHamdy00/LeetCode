class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>v(n,1);
        int cnt=0;
        for(int i=1;i<ratings.size();++i){
            int cur=ratings[i];
            int prv=ratings[i-1];
            if(cur>prv)v[i]=v[i-1]+1;
        }
        for(int i=ratings.size()-2;i>=0;--i){
            int cur=ratings[i];
            int prv=ratings[i+1];
            if(cur>prv&&v[i]<=v[i+1])v[i]=v[i+1]+1;
        }
        for(int i:v){
            cout<<i<<" ",
        cnt+=i;
        }
        cout<<endl;
        return cnt;
    }
};