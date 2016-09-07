    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto m:matrix)
            for(auto mm:m)
                pq.push(mm);
        while(pq.size()>k)
            pq.pop();
        return pq.top();
    }
