    // what's the difference between in-place and O(1) space?
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(!row)    return;
        int column=matrix[0].size();
        for(int j=0;j<row/2;j++){
            for(int i=j;i<column-1-j;i++){
                swap(matrix[j][i], matrix[row-1-i][j]);
                swap(matrix[row-1-i][j], matrix[row-1-j][column-1-i]);
                swap(matrix[row-1-j][column-1-i], matrix[i][column-1-j]);
            }
        }
    }
    
    /* clockwise rotate
     * first reverse up to down, then swap the symmetry 
     * 1 2 3     7 8 9     7 4 1
     * 4 5 6  => 4 5 6  => 8 5 2
     * 7 8 9     1 2 3     9 6 3
    */
    void rotate(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
