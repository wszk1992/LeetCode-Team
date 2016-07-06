    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size(), uniquePaths=0;
        vector<int> upCeil(n,1), leftCeil(m,1);
        // calculate the first row and the first column
        for (int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1)
                fill(leftCeil.begin()+i,leftCeil.end(),0);
        }
        for (int j=0;j<n;j++){
            if(obstacleGrid[0][j]==1)
                fill(upCeil.begin()+j,upCeil.end(),0);            
        }
        if(m==1) return upCeil[n-1];
        if(n==1) return leftCeil[m-1];
        for (int i=1;i<m;i++){
            for (int j=1;j<n;++j){
                if(obstacleGrid[i][j]==1){
                    uniquePaths=0;
                    upCeil[j]=uniquePaths;
                    leftCeil[i]=uniquePaths;
                }
                else{
                    uniquePaths=leftCeil[i]+upCeil[j];
                    upCeil[j]=uniquePaths;
                    leftCeil[i]=uniquePaths;
                }
            }
        }
        return uniquePaths;
    }
