class Solution {
private:
    void dfs(vector<vector<int>>& visited,vector<vector<char>>& grid,int row,int col){
        visited[row][col] = 1;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && grid[nrow][ncol] == '1' && visited[nrow][ncol] == 0){
                dfs(visited,grid,nrow,ncol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(visited,grid,i,j);
                }
            }
        }
        return cnt;
    }
};
