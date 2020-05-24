class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>ret;
        for(int i=0;i<A.size();i++){
            int a=A[i][0],b=A[i][1];
            for(int j=0;j<B.size();j++){
                int c=B[j][0],d=B[j][1];
                if (d < a || b< c)continue;
                int arr[]={a,b,c,d};
                sort(arr,arr+4);
                ret.push_back({arr[1],arr[2]});
            }
        }
        return ret;
    }
};