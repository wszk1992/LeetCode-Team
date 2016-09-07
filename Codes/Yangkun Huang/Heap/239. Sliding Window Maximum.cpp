    // solution 1 monotonic queue O(1)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) // remove the very left one
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])  // element of dq are in ascending order
                dq.pop_back();                                // update the maximum
            dq.push_back(i);
            if (i>=k-1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    
    // solution 2 max-heap O(nlgk)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;   // need to store the indices
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            pq.push(make_pair(nums[i],i));
            while(pq.top().second<i-k+1)    // cannot work for 'if' because of lazy delete
                pq.pop();
            if(i>=k-1)
                res.push_back(pq.top().first);
        }
        return res;
    }
