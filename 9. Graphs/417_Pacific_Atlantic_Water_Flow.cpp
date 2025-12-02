class Solution {
public:
    void dfs(vector<vector<int>>& heights, int r, int c, int pre, vector<vector<bool>>& visited){
        int n= heights.size();
        int m= heights[0].size();
        if(r<0 || r>=n || c<0 || c>=m || heights[r][c]<pre || visited[r][c]){
            return;
        }
        visited[r][c]=true;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nrow= r+drow[i];
            int ncol= c+dcol[i];
            dfs(heights, nrow, ncol, heights[r][c],visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pVis(n,vector<bool> (m,false));
        vector<vector<bool>> aVis(n,vector<bool> (m,false));

        for(int j=0;j<m;j++){
            dfs(heights, 0, j, INT_MIN, pVis);
            dfs(heights, n-1, j, INT_MIN, aVis);
        }
        for(int i=0;i<n;i++){
            dfs(heights, i, 0, INT_MIN, pVis);
            dfs(heights, i, m-1, INT_MIN, aVis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pVis[i][j] && aVis[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};