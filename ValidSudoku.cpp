// https://oj.leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int check_map[10];
        char cur_ch;

        // 1. check size
        if (9 != board.size()) {
            return false;
        }

        // 2. check h
        for (vector<vector<char> >::iterator iter = board.begin(); iter != board.end(); ++iter) {
            if (9 != iter->size()) {
                return false;
            }
            memset(check_map, 0, sizeof(check_map));
            for (vector<char>::iterator sub_iter = iter->begin();
                    sub_iter != iter->end(); ++sub_iter) {
                cur_ch = *sub_iter;
                if ('0' <= cur_ch && '9' >= cur_ch) {
                    if (0 == check_map[cur_ch - '0']) {
                        check_map[cur_ch - '0'] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }

        // 3. check v
        for (int i = 0; i < board.at(0).size(); ++i) {
            memset(check_map, 0, sizeof(check_map));
            for (int j = 0; j < board.size(); ++j) {
                cur_ch = board.at(j).at(i);
                if ('0' <= cur_ch && '9' >= cur_ch) {
                    if (0 == check_map[cur_ch - '0']) {
                        check_map[cur_ch - '0'] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }

        // 4. check block
        for (int i = 0; i < 9; ++i) {
            memset(check_map, 0, sizeof(check_map));
            for (int j = 0; j < 9; ++j) {
                cur_ch = board.at(i / 3 * 3 + j / 3).at(i % 3 * 3 + j % 3);
                if ('0' <= cur_ch && '9' >= cur_ch) {
                    if (0 == check_map[cur_ch - '0']) {
                        check_map[cur_ch - '0'] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
