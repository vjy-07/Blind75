class Solution {
public:
    bool helper(int row, int col, int idx, vector<vector<char>>& board, string& word){
        if(idx==word.size()) return true;
        int n = board.size();
        int m = board[0].size();
        if(row<0 || row>=n || col<0 || col>=m || board[row][col]=='$' || board[row][col]!=word[idx]){
            return false;
        }
        char temp = board[row][col];
        board[row][col]='$';
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(helper(nrow,ncol,idx+1,board,word)){
                return true;
            }
        }
        board[row][col]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && helper(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
