    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, pair<int, int>>> pq;
        for(auto n1:nums1)
            for(auto n2:nums2)
                pq.push(make_pair(-(n1+n2), make_pair(n1, n2)));
        while(k-->0 && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
