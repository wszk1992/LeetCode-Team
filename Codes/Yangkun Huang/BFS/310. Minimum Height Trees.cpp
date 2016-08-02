    // the basic idea is delete leaf level by level
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int>  degree(n),res;
        vector<unordered_set<int>> graph(n);
        for(auto e:edges){              // set up graph and calculate degrees
            degree[e.first]++;
            degree[e.second]++;
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        for(int remain=n; remain>2;){   // a graph can have at most two MHTs 
            vector<int> del;            // nodes to delete
            for(int j=0; j<n; j++)
                if(degree[j]==1) {      // find leaves
                    remain--;
                    del.push_back(j);
                    degree[j]=-1;
                }
            for(auto vertex: del)       // delete this node and its edges 
                for(auto neigh: graph[vertex]) 
                    degree[neigh]--;
        }
        for(int i=0; i<n; i++) 
            if(degree[i]>=0) 
                res.push_back(i);
        return res;
    }
