        // method 1 O(n^2) time
        int lengthOfLIS(vector<int>& nums) {
        // how to decide to set a new start
        // how to use an old state to generate a new state
        // first find a brute force method
        // how to find a brute force method
        // all the dp problems should be solved iteratively
         // 遍历到当前位置时获得的最大长度 VS 包含当前位置结尾的最长序列的长度
                const int size = nums.size();
                if (size == 0) { return 0; } 
                vector<int> dp(size, 1);
                int length =1;
                for (int i = 1; i < size; ++i) {
                    for (int j = 0; j < i; ++j) {
                        if (nums[j] < nums[i]) {
                            dp[i] = max(dp[i], dp[j]+1);
                        }
                       
                    }
                    length = max (length, dp[i]);
                }
                return length;
            }


        // method 2 O(nlogn) time
        // http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
        // keep track of an auxilary array, use the end element to denote a certain subsequence
        // each time encounter a new element, find its right position in auxilary arrary or discard it
        int lengthOfLIS(vector<int>& nums) {
            vector<int> res;
            for(int i=0; i<nums.size(); i++) {
                auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
                if(it==res.end()) res.push_back(nums[i]);
                else *it = nums[i];
            }
            return res.size();
        }
                
