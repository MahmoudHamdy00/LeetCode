class Solution {
public:
    int countVowelStrings(int n) {
        int arr[]={0,0,0,0,1};
        for(int i=1;i<n;++i){
            for(int j=0;j<5;++j){
                for(int k=j+1;k<5;++k)arr[j]+=arr[k];
            }
        }
        int  ans=0;
        for(int i=0;i<5;++i)
            ans+=(i+1)*arr[i];
        return ans;
    }
};