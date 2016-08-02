    // how to define 'breadth' and 'depth' 
    // 'breadth' -- search all 4 joint positions then go next
    // 'depth' -- go on one direction until no '1' found then change direction
    // solution 1 DFS using visited matrix
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), num = 0;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // the idea is when find a new '1' label all the connecting '1' as 'visited', and skip them, find next disjoint new '1'
                if (grid[i][j] == '1' && !visited[i][j]) {
                    num++;
                    markIslands(grid, visited, i, j);
                }
            }
        }
        return num;
    }
    void markIslands(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        int m = grid.size(), n = grid[0].size();
        if (r - 1 >= 0 && grid[r - 1][c] == '1' && !visited[r - 1][c])  // same column upper row
            markIslands(grid, visited, r - 1, c);
        if (r + 1 < m && grid[r + 1][c] == '1' && !visited[r + 1][c])   // same column lower row
            markIslands(grid, visited, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1' && !visited[r][c - 1])  // same row left column
            markIslands(grid, visited, r, c - 1);
        if (c + 1 < n && grid[r][c + 1] == '1' && !visited[r][c + 1])   // same row right column
            markIslands(grid, visited, r, c + 1);
    }
    
    // solution 2 BFS
    int numIslands(vector<vector<char>> &grid){
        int res = 0;
        if(grid.size() != 0){
            for(int i = 0; i < grid.size(); ++ i)
                for(int j = 0; j < grid[0].size(); ++ j)
                    if(grid[i][j] == '1'){
                         ++ res;
                         BFS(grid, i, j);
                     }
        }
        return res;
     }
    void BFS(vector<vector<char>> &grid, int x, int y){
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        grid[x][y] = '0';
        while(!q.empty()){
            x = q.front().first, y = q.front().second;
            q.pop();
            if(x > 0 && grid[x - 1][y] == '1'){
                q.push(make_pair(x - 1, y));
                grid[x - 1][y] = '0';
            }
            if(x < grid.size() - 1 && grid[x + 1][y] == '1'){
                q.push(make_pair(x + 1, y));
                grid[x + 1][y] = '0';
            }
            if(y > 0 && grid[x][y - 1] == '1'){
                q.push(make_pair(x, y - 1));
                grid[x][y - 1] = '0';
            }
            if(y < grid[0].size() - 1 && grid[x][y + 1] == '1'){
                q.push(make_pair(x, y + 1));
                grid[x][y + 1] = '0';
            }
        }
    }
    
    // DFS without using visited matrix
    int numIslands(vector<vector<char>> &grid){
        int res = 0;
        if(!grid.empty()){
            for(int i = 0; i < grid.size(); ++ i)
                for(int j = 0; j < grid[0].size(); ++ j)
                    if(grid[i][j] == '1'){
                        ++ res;
                        DFS(grid, i, j);
                    }
        }
        return res;
    }
    void DFS(vector<vector<char>> &grid, int x, int y){
        grid[x][y] = '0';
        if(x > 0 && grid[x - 1][y] == '1')
            DFS(grid, x - 1, y);
        if(y > 0 && grid[x][y - 1] == '1')
            DFS(grid, x, y - 1);
        if(x < grid.size() - 1 && grid[x + 1][y] == '1')
            DFS(grid, x + 1, y);
        if(y < grid[0].size() - 1 && grid[x][y + 1] == '1')
            DFS(grid, x, y + 1);
    }
