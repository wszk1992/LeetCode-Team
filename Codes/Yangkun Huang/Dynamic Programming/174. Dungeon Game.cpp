    // find max minimum
    // buttom up from buttom-right corner
    // since the movement is rightward and downward, it is asymetric for top-down and buttom-up
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col= dungeon[0].size(),  i, j;
        vector<int> dp(col+1,INT_MAX);

        for(i=row-1, dp[col-1] = 1; i>=0;--i)
        for(j=col-1; j>=0; --j)
            dp[j] = max(1, min(dp[j], dp[j+1]) - dungeon[i][j]); // dp[j] means the minimum hp at dungeon[i][j]
                                                                 // if less than 1, set it equal to 1
        return dp[0];    
    }



        // find max minimum
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        if(!m)
            return 0;
        int n=dungeon[0].size();
        vector<int> dp(n, 0);
        vector<vector<int>> mini(m, vector<int>(n, INT_MAX));
        partial_sum(dungeon[0].begin(), dungeon[0].end(), dp.begin());
        mini[0][0]=dungeon[0][0];
        for(int i=1;i<dungeon[0].size();i++){
            mini[0][i]=min(mini[0][i-1], dungeon[0][i-1]+dungeon[0][i]);
        }
        
        for(int d=1;d<dungeon.size();d++){
            dungeon[d][0]+=dungeon[d-1][0];
            mini[d][0]=min(mini[d-1][0], dungeon[d][0]);
        }
        
        int tmp=INT_MIN;
        for(int i=1;i<dungeon.size();i++){
            
            int left=dungeon[i][0];
            
            for(int j=1; j<dungeon[i].size();j++){
                dungeon[i][j]+=max(dp[j], left);
                dp[j]>left ? tmp=mini[i-1][j] : mini[i][j-1];
                mini[i][j]=min(tmp, dungeon[i][j]);
                dp[j]=dungeon[i][j];
                left=dungeon[i][j];
            }
        }
            for(auto a:mini){
                for(auto c:a)
                    cout<<c<<" ";
                    cout<<endl;
            }
        return -mini[m-1][n-1]+1;
    }
