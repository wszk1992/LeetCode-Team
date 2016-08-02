    // solution 1 DFS
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) 
            return NULL;
        if (mp.find(node) == mp.end()) {
            mp[node] = new UndirectedGraphNode(node -> label);
            for (UndirectedGraphNode* neigh : node -> neighbors)
                mp[node] -> neighbors.push_back(cloneGraph(neigh));
        }
        return mp[node];
    }
    
    // solution 2 BFS
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp; // record visited nodes
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) 
            return NULL;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node -> label);
        mp[node] = copy;
        queue<UndirectedGraphNode*> toVisit;
        toVisit.push(node);
        while (!toVisit.empty()) {
            UndirectedGraphNode* cur = toVisit.front();
            toVisit.pop();
            for (UndirectedGraphNode* neigh : cur -> neighbors) {
                if (mp.find(neigh) == mp.end()) {   // check if it has been copied or not
                    UndirectedGraphNode* neigh_copy = new UndirectedGraphNode(neigh -> label); // declare new space
                    mp[neigh] = neigh_copy; // mark as copied
                    toVisit.push(neigh);
                }
                mp[cur] -> neighbors.push_back(mp[neigh]);  //  copy all of its neighbors
            }
        }
        return copy; 
    }
