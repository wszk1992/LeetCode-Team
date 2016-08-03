class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }
        int num = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, ++num);
                }
            }
        }
        return num;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col, int& num) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
            return;
        }
        grid[row][col] = num + '1';
        dfs(grid, row - 1, col, num);
        dfs(grid, row + 1, col, num);
        dfs(grid, row, col - 1, num);
        dfs(grid, row, col + 1, num);
    }
};