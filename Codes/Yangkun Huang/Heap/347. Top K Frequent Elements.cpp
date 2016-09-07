    // solution 1 using max-heap O(nlgk)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> count;
        for(auto n:nums)
            count[n]++;
        priority_queue<pair<int, int>> pq;  // default p_queue is a max-heap
        for(auto c:count)
            pq.push(make_pair(c.second, c.first));  // sort by frequency(.second)
        while(k-->0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    // solution 2 using bucket sort O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums)
            ++m[num];
        
        vector<vector<int>> buckets(nums.size() + 1); 
        for (auto p : m)
            buckets[p.second].push_back(p.first);   // group nums by frequency(.second)
        
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
    
    // solution 3 using lamda expression
    // https://discuss.leetcode.com/topic/45780/c-13-lines-with-sorting-on-vector-of-pairs/4
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto n : nums) freq[n]++;
        vector<pair<int, int>> pairs;
        for (auto f : freq) pairs.push_back(f);
        sort(pairs.begin(), pairs.end(), [=](pair<int, int>&a, pair<int, int>&b) {return a.second > b.second;});
        vector<int> res;
        for (int i = 0;  i < k; i++) res.push_back(pairs[i].first);
        return res;
    }
