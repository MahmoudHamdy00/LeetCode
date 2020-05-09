class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans=abs(360/12*(hour+(minutes/60.0))-minutes*(360/60));
        return min(ans,360-ans);
        
    }
};