    // the idea is to label those 'O' on edges and their adjacent 'O' as '.', then alter all '.' to 'O' and all 'O' to 'X'
    // use DFS on this problem could cause recusion stack overflow, since zig zag 'O's from top to buttom make too much recursive call
    // while 200. Number of Islands makes recursive call only in one direction, it is less likely to suffer a stack overflow
    void solve(vector<vector<char>>& board) {
        if(!board.empty()){
            for(int i=0;i<board.size();i++){
                solve(board, i, 0); // first column
                if(board.size()>1)
                    solve(board, i, board[0].size()-1);    // last column
            }
            for(int j=1;j<board[0].size();j++){
                solve(board, 0, j); // first row
                if(board[0].size()>1)
                    solve(board, board.size()-1, j);
            }
            for(auto &b:board)
                for(auto &c:b)
                    c=='.' ? c='O' : (c=='O' ? c='X' : c);
        }
    }
    
    void solve(vector<vector<char>>& board, int row, int column){
        if(board[row][column]=='O'){
            board[row][column]='.';
            queue<pair<int, int>> q;
            q.push(make_pair(row, column));
            while(!q.empty()){
                int x=q.front().first, y=q.front().second;
                q.pop();
                if(x>0 && board[x-1][y]=='O'){
                    board[x-1][y]='.';
                    q.push(make_pair(x-1, y));
                }
                if(y > 0 && board[x][y - 1] == 'O'){
                    q.push(make_pair(x, y - 1));
                    board[x][y - 1] = '.';
                }
                if(x < board.size() - 1 && board[x + 1][y] == 'O'){
                    q.push(make_pair(x + 1, y));
                    board[x + 1][y] = '.';
                }
                if(y < board[0].size() - 1 && board[x][y + 1] == 'O'){
                    q.push(make_pair(x, y + 1));
                    board[x][y + 1] = '.';
                }
            }
        }
    }
