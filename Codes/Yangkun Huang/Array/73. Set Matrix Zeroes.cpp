    // method 1
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int zeroRow=-1;
        
        // 1. find the first row with 0s
        for(int i=0;i<m && zeroRow == -1;i++)  // be careful with the condition
            for(int j=0;j<n && zeroRow == -1;j++)
                !matrix[i][j] ? zeroRow=i : zeroRow; // if use break can break only one for-loop
       
        if(zeroRow==-1)
            return ;
        // 2. use the first zero row to store zero columns
        for(int i=zeroRow+1;i<m;i++){
            bool haveZeros=false;
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[zeroRow][j]=0;
                    haveZeros=true;
                }
            }
            // 3. go back to set the entire row to 0
           if(haveZeros)
                // for(auto &num:matrix[i])    // be careful with &
                //     num=0;
                matrix[i]=vector<int>(n, 0);
        }
        
        // 4. set zero column to 0
        for(int j=0;j<n;j++)
            if(!matrix[zeroRow][j])
                for(int i=0;i<m;i++)
                   matrix[i][j]=0; 
        
        // 5. set the first zero row to 0
        for(auto &num:matrix[zeroRow])
            num=0;
    }


    // method 2 use other value to replace 0 as a tag, not very strict since every number could appear in  matrix
    void setZeroes(vector<vector<int> > &matrix) {
        int i,j;
        int m=matrix.size();
        int n=matrix[0].size();
        for(i=0;i<m;i++){
            for(j=0;j<n;j++)
                if(matrix[i][j] == 0)
                    matrix[i][j]=GUARD;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++){
                if(matrix[i][j] == -1){ 
                    int p;
                    for(p=0;p<m;p++) if(matrix[p][j] != -1) matrix[p][j]=0;
                    for(p=0;p<n;p++) if(matrix[i][p] != -1) matrix[i][p]=0;
                    matrix[i][j]=0;
                }
            } 
        }
    }
