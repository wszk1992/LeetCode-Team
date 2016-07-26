    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> s(n, string(n, '.'));
        solveNQueens(res, s, n, 0);
        return res;
    }
    
    void solveNQueens(vector<vector<string>>& res, vector<string>& s, int& n, int row) {
        if(row == n) {
            res.push_back(s);
            return;
        }
        for(int column = 0; column < n; column++) {
            if(isValidPos(s, n, row, column)) {
                s[row][column] = 'Q';
                solveNQueens(res, s, n, row + 1);
                s[row][column] = '.';  // reset to find another solutions
            }
        }
    }
    
    bool isValidPos(vector<string> &nQueens, int &n, int row, int col) {
        //check if the column had a queen before.
        for (int i = 0; i < row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
