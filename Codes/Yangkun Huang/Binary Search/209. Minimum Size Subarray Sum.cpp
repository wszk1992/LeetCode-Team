      // O(n) solution
      // can this be solved by dp?
      // no optimal solution to subproblem exists
      // each solution is global optimal
      int minSubArrayLen(int s, vector<int>& nums) {
        int firstPos = 0, sum = 0, minLength = INT_MAX;
        for(int i = 0; i<nums.size(); i++) {
            sum += nums[i];
            while(sum >= s) {
                minLength = min(minLength, i - firstPos + 1);
                sum -= nums[firstPos++];
            }
        }
        return minLength == INT_MAX? 0 : minLength;
      }
      
      // O(nlgn) solution
      int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sums(nums.size() + 1, 0);
        partial_sum(nums.begin(),nums.end(), sums.begin()+1);  // O(n) using dp
        int n = nums.size(), minlen = INT_MAX;
        for (int i = 1; i <= n; i++) { 
            if (sums[i] >= s) {
                auto p = upper_bound(sums.begin(), sums.begin()+i, sums[i] - s);  // O(lgn)
                if (p != sums.end()) 
                    minlen = min(minlen, i - (int)(p-sums.begin()) + 1);
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
     }
