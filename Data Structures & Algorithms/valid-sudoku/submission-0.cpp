class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        std::unordered_map<char, int> validCol;
        std::unordered_map<char, int> validRow;
        std::unordered_map<char, int> validBox;

        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (validRow.contains(board[i][j])) {
                    return false;
                }
                validRow[board[i][j]]++;
            }
            validRow.clear();
        }

        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (validCol.contains(board[j][i])) {
                    return false;
                }
                validCol[board[j][i]]++;
            }
            validCol.clear();
        }

        int row = 0;

        for (size_t i = 0; i < 3; i++) {

            int col = 0;

            for (size_t j = 0; j < 3; j++) {

                for (size_t x = row; x < row + 3; x++) {
                    for (size_t y = col; y < col + 3; y++) {
                        if (board[x][y] == '.') {
                            continue;
                        }
                        if (validBox.contains(board[x][y])) {
                            return false;
                        }
                        validBox[board[x][y]]++;
                    }
                }

                validBox.clear();

                col += 3;
            }

            validBox.clear();
            row += 3;
        }

        return true;
    }
};
