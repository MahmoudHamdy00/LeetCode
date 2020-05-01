// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l=1,r=n,md,ans=n;
        while(l<=r){
            md=l+r>>1;
            if(isBadVersion(md)){
                r=md-1;
                ans=md;
            }
            else l=md+1;
        }
        return ans;
    }
};