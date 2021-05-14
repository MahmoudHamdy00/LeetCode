class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int l=0,r=height.size()-1;
        while(l<r){
            int h=min(height[l],height[r]);
            int w=r-l;
            ans=max(ans,w*h);
            if(height[l]>height[r])
                r--;
            else 
                l++;
        }
		return ans ;
    }
};