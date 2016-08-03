class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> vertex(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        vector<int> res;
        queue<int> q;
        for(int i = 0; i < prerequisites.size(); i++) {
            vertex[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int num = 0;
        while(!q.empty()) {
            vector<int> next = vertex[q.front()];
            res.push_back(q.front());
            q.pop();
            for(int i = 0; i < next.size(); i++) {
                if(--indegree[next[i]] == 0) {
                    q.push(next[i]);
                }
            }
            num++;
        }
        return num == numCourses ? res : vector<int>();
    }
};