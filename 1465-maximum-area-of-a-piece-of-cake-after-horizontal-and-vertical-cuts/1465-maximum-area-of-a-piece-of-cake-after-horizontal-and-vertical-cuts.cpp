class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maximum_horizontal_cut=max(horizontalCuts[0],h-horizontalCuts.back());
        for(int i=1;i<horizontalCuts.size();++i){
            maximum_horizontal_cut=max(maximum_horizontal_cut,horizontalCuts[i]-horizontalCuts[i-1]);
        }
                                       
        int maximum_vertical_cuts=max(verticalCuts[0],w-verticalCuts.back());
        for(int i=1;i<verticalCuts.size();++i){
            maximum_vertical_cuts=max(maximum_vertical_cuts,verticalCuts[i]-verticalCuts[i-1]);
        }
        return (1LL* maximum_horizontal_cut*maximum_vertical_cuts)%(int)(1e9+7);
    }
};