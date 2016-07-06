    // how to write the state equation
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        // left[n] means first '1' on the left, so as right[n] 
        int left[n], right[n], height[n];
        fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
        int maxA = 0;
        for(int i=0; i<m; i++) {
            int cur_left=0, cur_right=n; 
            for(int j=0; j<n; j++) { 
                if(matrix[i][j]=='1') {
                    height[j]++; 
                    // dp property shows here: every left[j] contains left boarder of all previous '1' row matrix[x...i][j]
                    // and calculate current left boundary basing on previous works
                    left[j]=max(left[j],cur_left); 
                }
                else{ 
                    height[j]=0;
                    left[j]=0;
                    cur_left=j+1;
                }
            }
            for(int j=n-1; j>=0; j--) {
                if(matrix[i][j]=='1') 
                    right[j]=min(right[j],cur_right);
                else {
                    right[j]=n;
                    cur_right=j;
                }   
                maxA = max(maxA,(right[j]-left[j])*height[j]);
            }
        }
        return maxA;
    }
