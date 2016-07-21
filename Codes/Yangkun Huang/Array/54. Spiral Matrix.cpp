    // correct answer
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // fail to handle edge cases
        vector<int> ans;
        if(matrix.empty())
            return ans;
          ans=matrix[0];
        int left=0, right=matrix[0].size()-1, up=1, buttom=matrix.size()-1;
        
        while(left<=right && up<=buttom){
            for(int j=up;j<=buttom && left<=right;j++)
                ans.push_back(matrix[j][right]);
            right--;
            for(int m=right;m>=left && up<=buttom;m--)
                ans.push_back(matrix[buttom][m]);
            buttom--;
            for(int n=buttom;n>=up && left<=right;n--)
                ans.push_back(matrix[n][left]);
            left++;
            for(int i=left;i<=right && up<=buttom;i++)
                ans.push_back(matrix[up][i]);
            up++;
        }
        return ans;
    }
      
      // fail to handle edge cases
      // the condition should write inside the loop
      vector<int> spiralOrder(vector<vector<int>>& matrix) {
          vector<int> ans;
          if(matrix.empty())
              return ans;
            ans=matrix[0];
          int left=0, right=matrix[0].size()-1, up=1, buttom=matrix.size()-1;
          while(left<=right && up<=buttom){
              for(int j=up;j<=buttom;j++)
                  ans.push_back(matrix[j][right]);
              right--;
              for(int m=right;m>=left;m--)
                  ans.push_back(matrix[buttom][m]);
              buttom--;
              for(int n=buttom;n>=up;n--)
                  ans.push_back(matrix[n][left]);
              left++;
              for(int i=left;i<=right;i++)
                  ans.push_back(matrix[up][i]);
              up++;
          }
          return ans;
      }
