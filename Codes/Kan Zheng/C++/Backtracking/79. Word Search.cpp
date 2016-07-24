//back tracking
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) {
            return false;
        }
        
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(helper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if(word[index] != board[row][col]) {
            return false;
        }
        if(index == word.size() - 1) {
            return true;
        }
        board[row][col] = '.';
        //top
        if(row > 0 && helper(board, word, row - 1, col, index + 1)) {
            return true;
        }
        //left
        if(col > 0 && helper(board, word, row, col - 1, index + 1)) {
            return true;
        }
        //bottom
        if(row < board.size() - 1 && helper(board, word, row + 1, col, index + 1)) {
            return true;
        }
        //right
        if(col < board[0].size() - 1 && helper(board, word, row, col + 1, index + 1)) {
            return true;
        }
        board[row][col] = word[index];
        return false;
    }
    
};
 
