    bool exist(vector<vector<char>>& board, string word) {
        if( board.size() && board[0].size() && word.size()){
            for(int i=0;i<board.size();i++)                 // combination of loop and recursion
                for(int j=0;j<board[0].size();j++)
                    if(exist(board, word.begin(), i, j))    // iteraotr seems to lower the speed
                        return true;
        }
        return false;
    }
    
    bool exist(vector<vector<char>> &board, string::iterator iter, int row, int column){
        bool res=false;     // use a variable to store result which may reduce if-clause
        if(*iter==board[row][column]){
            if(*(iter+1)=='\0')     // no element of board should have been matched with word, so needless to use *iter=='\0'
                return true;
            char tmp=board[row][column];
            board[row][column]='\0';
            row>0 ?  res=exist(board, iter+1, row-1, column) : res;
            !res && row<board.size()-1 ? res=exist(board, iter+1, row+1, column) : res;
            !res && column>0 ? res=exist(board, iter+1, row, column-1) : res;
            !res && column<board[0].size()-1 ? res=exist(board, iter+1, row, column+1) : res;
            board[row][column]=tmp;
        }
        return res;
    }
