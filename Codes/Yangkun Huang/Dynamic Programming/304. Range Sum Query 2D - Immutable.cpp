    // method 1 base on Range Sum Query - Immutable
    class NumMatrix {
    public:
        NumMatrix(vector<vector<int>> &matrix) :m(matrix){
            if(matrix.size()!=0)
            {
                // each row range sum
                for(int i=0;i<matrix.size();i++)
                {
                    m[i][0]=0;
                    partial_sum(matrix[i].begin(),matrix[i].end(), m[i].begin()+1);
                }
            }
        }
    
        int sumRegion(int row1, int col1, int row2, int col2) {
            int sum=0;
            for(int i=row1;i<=row2;i++)
                sum+=(m[i][col2+1]-m[i][col1]);
            return sum;
        }
    private:
        vector<vector<int>> m;
    };
    
    // method 2 from discuss
    private:
        int row, col;
        vector<vector<int>> sums;
    public:
        NumMatrix(vector<vector<int>> &matrix) {
            row = matrix.size();
            col = row>0 ? matrix[0].size() : 0;
            sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
            for(int i=1; i<=row; i++) {
                for(int j=1; j<=col; j++) {
                    sums[i][j] = sums[i-1][j] + sums[i][j-1] + matrix[i-1][j-1] - sums[i-1][j-1] ;
                }
            }
        }
    
        int sumRegion(int row1, int col1, int row2, int col2) {
            return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
        }
    };
