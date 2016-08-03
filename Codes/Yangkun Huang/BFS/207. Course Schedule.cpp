    // solution 1 topological sort -- Kahn's algorithm BFS
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);  // adjacency list
        vector<int> indegree(numCourses,0);         
        for(auto edge : prerequisites){
            graph[edge.second].push_back(edge.first); // point from second to first
            ++indegree[edge.first];                   // second is the prerequisites
        }
        queue<int> Q;
        for(int i = 0;i < numCourses;i++)             // collect all the vertices which have 0 indegree
            if(indegree[i] == 0)
                Q.push(i);
        int counter = 0;
        while(!Q.empty()){
            for(auto v : graph[Q.front()])
                if(--indegree[v] == 0)  // remove the edge and push 0 indegree vertex into candidate queue
                    Q.push(v);
            ++counter;
            Q.pop();
        }
        return counter == numCourses;
    }
    
    // solution 2 DFS use two vector to record visited vertices
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int> > g(numCourses, list<int>());
        for(int i = 0; i<prerequisites.size(); i++)
            g[prerequisites[i].first].push_back(prerequisites[i].second);
        // visited[] can be discarded, but will largely increase time complexity
        vector<bool> visited(prerequisites.size(), false);     // records vertices which have been visited previously(prune recursion)
        vector<bool> visitingList(prerequisites.size(), false);// records vertices being searched under current recursion(find circle) 
         for(int i = 0; i<g.size(); i++)            
            if(isCycle(g, visited, visitingList, i))
                return false;
        return true;
     }
    bool isCycle(vector<list<int>>& g, vector<bool>& visited, vector<bool>& visitingList, int n) {
        if(visited[n] != true){      // not visited before, go check
            visited[n] = visitingList[n] = true;
            for(auto iter:g[n]) 
                if(visitingList[iter]|| isCycle(g, visited, visitingList, iter))
                    return true;
        }// finish current check and reset, means it is not on the way of current searching
        return visitingList[n] = false;  // if write like this, visitingList[iter] must be check before isCycle()
    }
