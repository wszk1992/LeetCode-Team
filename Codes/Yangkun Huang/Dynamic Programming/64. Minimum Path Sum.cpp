   int minPathSum(vector<vector<int>>& grid) {
        // calculate the first row
        partial_sum( grid[0].begin(),grid[0].end(),grid[0].begin());
        for (int i=1;i<grid.size();i++)
        {
           // calculate the first column
            grid[i][0]+=grid[i-1][0];
            for(int j=1;j<grid[i].size();j++)
                grid[i][j]+=min(grid[i][j-1],grid[i-1][j]);
        }
        return grid[grid.size()-1][grid[grid.size()-1].size()-1];
    }
