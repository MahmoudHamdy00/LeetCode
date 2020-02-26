class Solution {
public:
int numRabbits(vector<int> &answers)
{
    int frq[1000] = {0};

    for (int i : answers)
    {
        frq[i]++;
    }
    int ans = 0;
    for (int i = 0; i < 1000; i++)
    {
        int l=0,r=10000,md,mn;
        while (l<=r)
        {
            md=l+r>>1;
            if (md * (i + 1) >= frq[i])
                mn=md,r=md-1;
            else
                l=md+1;
        }
        ans += mn * (i + 1);
    }
    return max(ans, (int)answers.size());
}
};