    // find max minimum
    // buttom up from buttom-right corner
    // since the movement is rightward and downward, it is asymetric for top-down and buttom-up
    // if go from left top, then need two matrix to store intermidiate result
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col= dungeon[0].size(),  i, j;
        vector<int> dp(col+1,INT_MAX);

        for(i=row-1, dp[col-1] = 1; i>=0;--i)
            for(j=col-1; j>=0; --j)                                     // dp[j] means the minimum hp at dungeon[i][j]
                dp[j] = max(1, min(dp[j], dp[j+1]) - dungeon[i][j]);    // if less than 1, set it equal to 1
                                                                        // dp[j+1] is at row[i] dp[j] is at row i+1
        return dp[0];    
    }
