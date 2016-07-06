	// only the first and last balloons we are sure of their adjacent balloons before hand
	// for the first we have nums[i-1]*nums[i]*nums[i+1] for the last we have nums[-1]*nums[i]*nums[n].
	// the thought is, at each state, just find the max coins of which balloon is burst at last
	// dp[i][j] means the max coins got bursting balloons between i and j (exclusively, means i and j won't burst)
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));

		for (int len = 1; len < n - 1; len ++) {
			for (int start = 0; start < n - 1 - len; start ++) {
				int end = start + len + 1;

				for (int k = start + 1; k < end; k ++) {
					dp[start][end] = max(dp[start][end], dp[start][k] + dp[k][end] + nums[start] * nums[k] * nums[end]);
				}
			}
		}

		return dp[0][n-1];
	}