class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return ;
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<m;i++){
            if(board[0][i] == 'O')
                DFS(board,0,i);
            if(board[n-1][i] == 'O')
                DFS(board,n-1,i);
        }
         for(int i=0;i<n;i++){
            if(board[i][0] == 'O')
                DFS(board,i,0);
            if(board[i][m-1] == 'O')
                DFS(board,i,m-1);
        }
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '$') board[i][j] = 'O';
                
            }
        }
    }
    
    void DFS(vector<vector<char>>& board,int i,int j){
        if(i < 0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = '$';
        DFS(board,i+1,j);
        DFS(board,i,j+1);
        DFS(board,i-1,j);
        DFS(board,i,j-1);
    }
};
