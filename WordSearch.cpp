// https://oj.leetcode.com/problems/word-search/
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (0 == word.length()) {
            return true;
        }
        if (0 == board.size() || 0 == board.at(0).size()) {
            return false;
        }
        bool ret = false;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.at(0).size(); ++j) {
                if (word.at(0) == board.at(i).at(j)) {
                    board[i][j] = 0;
                    if (_try_next(board, word, i, j, 1)) {
                        return true;
                    }
                    board[i][j] = word.at(0);
                }
            }
        }
        return false;
    }

private:
    bool _try_next(vector<vector<char> > board, string& word, int startx, int starty, int index) {
        if (index >= word.length()) {
            return true;
        }

        char cur_target = word.at(index);
        if (startx > 0 && cur_target == board.at(startx - 1).at(starty)) {
            board[startx - 1][starty] = 0;
            if (_try_next(board, word, startx - 1, starty, index + 1)) {
                return true;
            }
            board[startx - 1][starty] = cur_target;
        }

        if (startx < board.size() - 1 && cur_target == board.at(startx + 1).at(starty)) {
            board[startx + 1][starty] = 0;
            if (_try_next(board, word, startx + 1, starty, index + 1)) {
                return true;
            }
            board[startx + 1][starty] = cur_target;
        }

        if (starty > 0 && cur_target == board.at(startx).at(starty - 1)) {
            board[startx][starty - 1] = 0;
            if (_try_next(board, word, startx, starty - 1, index + 1)) {
                return true;
            }
            board[startx][starty - 1] = cur_target;
        }

        if (starty < board.at(0).size() - 1 && cur_target == board.at(startx).at(starty + 1)) {
            board[startx][starty + 1] = 0;
            if (_try_next(board, word, startx, starty + 1, index + 1)) {
                return true;
            }
            board[startx][starty + 1] = cur_target;
        }

        return false;
    }
};
