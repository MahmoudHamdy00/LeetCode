class Solution {
    int frq[(int)1e5+5];
public:
    int minimumOperations(vector<int>& nums) {

        int cnt1=0;
        for(int i=0;i<nums.size();i+=2){
            ++frq[nums[i]];
            ++cnt1;
        }
        vector<pair<int,int>>v;
        for(int i=0;i<1e5+5;++i){
            if(frq[i])v.push_back({frq[i],i});
        }
        memset(frq,0,sizeof frq);
        int cnt2=0;
        for(int i=1;i<nums.size();i+=2){
            ++frq[nums[i]];
            ++cnt2;
        }
        vector<pair<int,int>>v2;
        for(int i=0;i<1e5+5;++i){
            if(frq[i])v2.push_back({frq[i],i});
        }
        sort(v.rbegin(),v.rend());    
        sort(v2.rbegin(),v2.rend());
        vector<pair<int,int>>op1,op2;
        for(int i=0;i<min(2,(int)v.size());++i){
            op1.push_back(v[i]);
        }
        
        for(int i=0;i<min(2,(int)v2.size());++i){
            op2.push_back(v2[i]);
        }
        cout<<op1.size()<<" "<<op2.size()<<endl;
        cout<<cnt1<<" "<<cnt2<<endl;
        int ans=1e9;
        for(int i=0;i<op1.size();++i){
            for(int j=0;j<op2.size();++j){
                if(op1[i].second==op2[j].second)continue;
                int c1=op1[i].first;
                int c2=op2[j].first;
                cout<<"c1= "<<c1<<" "<<" c2 "<<c2<<endl;
                ans=min(ans,cnt1-c1+cnt2-c2);

            }    
        }
        if(ans==1e9){
            return min(cnt1,cnt2);
        }
        return ans;
        
    }
};