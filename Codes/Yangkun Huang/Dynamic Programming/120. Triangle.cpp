	// method 1 change the original vector
	int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j)
                // triangle[i][j] stores the least sum from buttom up to entry [i][j]
                triangle[i][j] += min(triangle[i + 1][j],triangle[i + 1][j + 1]); 
        return triangle [0][0];
    }
	
	// method 2 not change the original vector
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		vector<int> minlen(triangle.back());
		for (int layer = n-2; layer >= 0; layer--) // For each layer
		{
			for (int i = 0; i <= layer; i++) // Check its every 'node'
			{
				// Find the lesser of its two children, and sum the current value in the triangle with it.
				// In each loop, minlen[i] stores the least sum which reacha trianle[layer][i]
				minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
			}
		}
		return minlen[0];
	}
