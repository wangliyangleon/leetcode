// https://oj.leetcode.com/problems/sudoku-solver/
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        _checkCurBoard(board);
    }

private:
    bool _isValidSudoku(const vector<vector<char> > &board, int x, int y) {
        for (int i = 0; i < 9; ++i) {
            if ((i != x) && (board.at(i).at(y) == board.at(x).at(y))) {
                return false;
            }
            if ((i != y) && (board.at(x).at(i) == board.at(x).at(y))) {
                return false;
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int xstart = x / 3 * 3;
                int ystart = y / 3 * 3;
                if (((x != xstart + i) || (y != ystart + j)) &&
                        (board.at(xstart + i).at(ystart + j) == board.at(x).at(y))) {
                    return false;
                }
            }
        }

        return true;
    }

    bool _checkCurBoard(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ('.' == board.at(i).at(j)) {
                    for (int k = 0; k < 9; ++k) {
                        board.at(i).at(j) = '1' + k;
                        if (_isValidSudoku(board, i, j) && _checkCurBoard(board)) {
                            return true;
                        }
                        board.at(i).at(j) = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
