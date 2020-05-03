class Solution {
public:
   
    int kthSmallest(vector<vector<int>>& mat, int k) {
        multiset<int>st;
        st.insert(0);
        for(auto row:mat){
            multiset<int>cur;
            for(int x:row){
                for (auto it:st){
                    cur.insert(x+it);
                    
                    if((int)cur.size()>k)cur.erase(--cur.end());
                }
            }
            st=cur;
        }
        for(auto it:st){
            k--;
            cout<<it<<" ";
            if(k==0)return it;
        }
        return -1 ;
    }

};