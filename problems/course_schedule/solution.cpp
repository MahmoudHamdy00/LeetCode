
    class Solution {
public:
    
    bool dfs(vector<int>graph[],int node,vector<int>&visitedStatus){
	
		// if the course/node is completed
        if(visitedStatus[node]==1){
            return true;
        }
		//if a course/node is already been visited but not completed means a cycle
        if(visitedStatus[node]==-1){
            return false;
        }
		
		//start completing its dependencies
        visitedStatus[node]=-1;
        bool ans = true;
        for(int i=0;i<graph[node].size();i++){
            if(visitedStatus[graph[node][i]]!=1){
                ans = ans & dfs(graph,graph[node][i],visitedStatus);
            }
        }
		//finished all dependencies hence the curr node is finished
        visitedStatus[node]=1;
        return ans;
    }
	
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>graph[numCourses];
        for(int i =0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>visitedStatus(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!dfs(graph,i,visitedStatus)){
                return false;
            }
        }
        return true;
    }
};