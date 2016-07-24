class Solution {
public:
    int totalNQueens(int n) {
        int num = 0;
        vector<string> s(n, string(n, '.'));
        solveNQueensHelper(num, s, n, 0);
        return num;
    }
    
    void solveNQueensHelper(int& num, vector<string>& s, int& n, int row) {
        if(row == n) {
            num++;
            return;
        }
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(!availablePos(s, n, row, i)) {
                continue;
            }else {
                flag = 1;
                s[row][i] = 'Q';
                solveNQueensHelper(num, s, n, row + 1);
                s[row][i] = '.';
            }
        }
        if(!flag) {
            return;
        }
    }
    
    bool availablePos(vector<string>& s, int& n, int& row, int& col) {
        //45°
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(s[i][j] == 'Q') {
                return false;
            }
        }
        //90°
        for(int i = row; i >= 0; i--) {
            if(s[i][col] == 'Q') {
                return false;
            }
        }
        //135°
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(s[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    
};
