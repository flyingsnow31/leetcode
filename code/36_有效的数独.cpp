class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int su[9];
        for(int n = 0; n < 9; n++) {
            memset(su, 0, sizeof(su));
            for(int i = (n/3)*3; i < (n/3)*3 + 3; i++) {
                for(int j = (n%3)*3; j < (n%3)*3 + 3; j++) {
                    if(board[i][j] == '.') continue;
                    su[board[i][j] - '0' - 1]++;
                    if(su[board[i][j] - '0' - 1] > 1){
                        return false;
                    }
                }
            }
            memset(su, 0, sizeof(su));
            for(int i = 0; i < 9; i++) {
                if(board[n][i] == '.') continue;
                su[board[n][i] - '0' - 1]++;
                if(su[board[n][i] - '0' - 1] > 1){
                    return false;
                }
            }
            memset(su, 0, sizeof(su));
            for(int i = 0; i < 9; i++) {
                if(board[i][n] == '.') continue;
                su[board[i][n] - '0' - 1]++;
                if(su[board[i][n] - '0' - 1] > 1){
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int col[9][9];
        int cube[3][3][9];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(cube, 0, sizeof(cube));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int tmp = board[i][j] - '0' - 1;
                    row[i][tmp]++;
                    col[j][tmp]++;
                    cube[i/3][j/3][tmp]++;
                    if(row[i][tmp] > 1 || col[j][tmp] > 1 || cube[i/3][j/3][tmp] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};