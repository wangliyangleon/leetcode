// https://oj.leetcode.com/problems/surrounded-regions/
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row_cnt = 0, col_cnt = 0;
        if ((2 > (row_cnt = board.size())) ||
                (2 > (col_cnt = board.at(0).size()))) {
            return;
        }

        union item_t {
            struct {
                int x;
                int y;
            };
            long long index;
        };
        stack<item_t> keep_O;
        item_t item, item_check;

#define CHECK_AND_PUSH_ITEM(IDX_X, IDX_Y, ITEM)     \
        if ('O' == board.at((IDX_X)).at((IDX_Y))) {     \
            ITEM.x = IDX_X;                             \
            ITEM.y = IDX_Y;                             \
            keep_O.push(ITEM);                          \
            board[IDX_X][IDX_Y] = 'T';                  \
        }                                               \

        // init stack
        for (int i = 0; i < row_cnt; ++i) {
            CHECK_AND_PUSH_ITEM(i, 0, item);
            CHECK_AND_PUSH_ITEM(i, col_cnt - 1, item);
        }
        for (int i = 1; i < col_cnt - 1; ++i) {
            CHECK_AND_PUSH_ITEM(0, i, item);
            CHECK_AND_PUSH_ITEM(row_cnt - 1, i, item);
        }

        while (!keep_O.empty()) {
            item.index = keep_O.top().index;
            keep_O.pop();
            if (item.x > 0) {
                CHECK_AND_PUSH_ITEM(item.x - 1, item.y, item_check);
            } 
            if (item.x < row_cnt - 1) {
                CHECK_AND_PUSH_ITEM(item.x + 1, item.y, item_check)
            }
            if (item.y > 0) {
                CHECK_AND_PUSH_ITEM(item.x, item.y - 1, item_check)
            }
            if (item.y < col_cnt - 1) {
                CHECK_AND_PUSH_ITEM(item.x, item.y + 1, item_check)
            }
        }

        // restruct
        for (int i = 0; i < row_cnt; ++i) {
            for (int j = 0; j < col_cnt; ++j) {
                if ('T' == board.at(i).at(j)) {
                    board[i][j] = 'O';
                }
                else if ('O' == board.at(i).at(j)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
