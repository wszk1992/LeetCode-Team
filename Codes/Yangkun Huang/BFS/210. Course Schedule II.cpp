    // solution 1 BFS topological sort
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses), res;
        for(auto edge:prerequisites){
            graph[edge.second].push_back(edge.first);  // store outward edges
            indegree[edge.first]++;
        }
        queue<int> Q;
        for(int i=0;i<indegree.size();i++)
            if(!indegree[i])
                Q.push(i);
        while(!Q.empty()){
            res.push_back(Q.front());
            for(auto adjacent_vertex:graph[Q.front()])   // search from adjacent vertex of front_course
                if(--indegree[adjacent_vertex]==0)
                    Q.push(adjacent_vertex);
            Q.pop();
        }
        for(auto i:indegree)    // if there is a vertex which has non-zero indegree, then the graph is not a DAG
            if(i)
                return {};
        return res;
    }
    
    // solution 2 DFS
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false), visitingList(numCourses, false);
        vector<int> res;
        for(auto edge:prerequisites)
            graph[edge.first].push_back(edge.second);  // store inward edges rather than outward edges reducing reverse operation
        for(int i=0;i<numCourses;i++){
            if(hasCycle(graph, visited, visitingList, res, i))
                return {};
        }
        // reverse(res.begin(), res.end());
        return res;
    }
    bool hasCycle(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& visitingList, vector<int>& res, int i){
        if(!visited[i]){
            visited[i]=visitingList[i]=true;
            for(auto adj_v:graph[i])
                if(visitingList[adj_v] || hasCycle(graph, visited, visitingList, res, adj_v))
                    return true;
            res.push_back(i);
        }
        return visitingList[i]=false;
    }
