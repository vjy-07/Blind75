class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        grid[row][col]='0';
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};

TC - O(m*n)
SC - O(m*n)
