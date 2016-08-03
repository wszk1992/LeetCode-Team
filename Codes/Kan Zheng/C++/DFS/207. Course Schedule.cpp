class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> vertex(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for(int i = 0; i < prerequisites.size(); i++) {
            vertex[prerequisites[i].first].push_back(prerequisites[i].second);
            indegree[prerequisites[i].second]++;
        }
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int num = 0;
        while(!q.empty()) {
            vector<int> next = vertex[q.front()];
            q.pop();
            for(int i = 0; i < next.size(); i++) {
                if(--indegree[next[i]] == 0) {
                    q.push(next[i]);
                }
            }
            num++;
        }
        return num == numCourses;
    }
};

//try dfs
