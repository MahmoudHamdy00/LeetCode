class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int,vector<int>,Compfunc>pq;
        int lst=0;
        for(auto&it:courses){
            if(lst+it[0]<=it[1]){
                pq.push(it[0]);
                lst+=it[0];
            }
            else if(!pq.empty()&&pq.top()>it[0]){
                lst-=pq.top();
                pq.pop();
                lst+=it[0];
                pq.push(it[0]);
            }          
        }
        return pq.size();
    }
    struct Compfunc {
        bool operator() (const int &a, const int &b) {
            return a<b;
        }
    };
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
};