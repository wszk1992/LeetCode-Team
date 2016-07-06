     // method 1 O(1) space O(n^3) time
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()<1)
            return 0;
        int area=0;
        for(auto i:matrix[0])
            i-48? area=1:area=area;
        for(auto j:matrix)
            j[0]-48? area=1:area=area;
        for(int k=0;k<min(matrix.size(),matrix[0].size());k++)
          for(int i=matrix.size()-1;i>0;i--)
            for(int j=matrix[i].size()-1;j>0;j--)
                if(matrix[i][j]>48)
                    {
                        area=max(area,1);
                        if(matrix[i][j]==matrix[i][j-1]&&matrix[i][j-1]==matrix[i-1][j]&&matrix[i][j]==matrix[i-1][j-1])
                        {
                         
                            matrix[i][j]+=1;
                            area=max(area,matrix[i][j]-48);
                        }
                    }
        return area*area;
    }
    
    // method 2 one matrix
    int maximalSquare(vector<vector<char>>& matrix) {
         int m = matrix.size();
         if (!m) return 0;
         int n = matrix[0].size();
         vector<vector<int> > size(m, vector<int>(n, 0));
         int maxsize = 0;
         for (int j = 0; j < n; j++) {
             size[0][j] = matrix[0][j] - '0';
             maxsize = max(maxsize, size[0][j]);
         }
         for (int i = 1; i < m; i++) {
             size[i][0] = matrix[i][0] - '0';
             maxsize = max(maxsize, size[i][0]);
         }
         for (int i = 1; i < m; i++) {
             for (int j = 1; j < n; j++) {
                 if (matrix[i][j] == '1') {  // only need row i-1 and column j-1, it can be reduced to two vectors
                                             // one records column j-1, one records row i-1
                     size[i][j] = min(size[i - 1][j - 1], min(size[i - 1][j], size[i][j - 1])) + 1;
                     maxsize = max(maxsize, size[i][j]);
                 }
             }
         }
         return maxsize * maxsize;
     }
    
    // method 3 two vectors 
    // using two arrays can reduce to 8ms
    int maximalSquare(vector<vector<char>>& matrix) {
         int m = matrix.size();
         if (!m) return 0;
         int n = matrix[0].size();
         vector<int> pre(m, 0);
         vector<int> cur(m, 0);
         int maxsize = 0;
         for (int i = 0; i < m; i++) {
             pre[i] = matrix[i][0] - '0';
             maxsize = max(maxsize, pre[i]);
         }
         for (int j = 1; j < n; j++) {
             cur[0] = matrix[0][j] - '0';
             maxsize = max(maxsize, cur[0]);
             for (int i = 1; i < m; i++) {   // pre records column j-1
               if (matrix[i][j] == '1') {  // cur maintain matrix[0 to i][j] and matrix[i+1 to end][j-1]
                    cur[i] = min(cur[i - 1], min(pre[i - 1], pre[i])) + 1;
                    maxsize = max(maxsize, cur[i]);
                 }
               else
                    cur[i]=0;
             }
             swap(pre, cur);
          }
          return maxsize * maxsize;
     }
    
    // method 4 one vector
    int maximalSquare(vector<vector<char>>& matrix) {
         if (matrix.empty()) return 0;
         int m = matrix.size(), n = matrix[0].size();
         vector<int> dp(m + 1, 0);
         int maxsize = 0, pre = 0;
         for (int j = 0; j < n; j++) {
             for (int i = 0; i <m; i++) {
                 int temp = dp[i+1];
                 if (matrix[i][j] == '1') {                      // dp is not used immediately, so it cannot be reduced to O(1) extra space
                     dp[i+1] = min(dp[i+1], min(dp[i], pre)) + 1;// dp[1 to i+1] represents matrix[0 to i][j]
                     maxsize = max(maxsize, dp[i+1]);            // dp[i+2 to end] represents matrix[i+1 to end][j-1]
                 }
                 else dp[i+1] = 0; 
                 pre = temp;
             }
         }
         return maxsize * maxsize;
    }
