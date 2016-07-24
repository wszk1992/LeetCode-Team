    // the same idea as 54. Spiral Matrix 
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        if(!n)
            return ans;
        int left=0, right=n-1, top=0, buttom=n-1;
        for(int i=1, j=left;i<=n*n;){
            for(j=left;j<=right && top<=buttom;)
                ans[top][j++]=i++;
            top++;
            for(j=top;j<=buttom && left<=right;)
                ans[j++][right]=i++;
            right--;
            for(j=right;j>=left && top<=buttom;)
                ans[buttom][j--]=i++;
            buttom--;
            for(j=buttom;j>=top && left<=right;)
                ans[j--][left]=i++;
            left++;
        }
        return ans;
    }
