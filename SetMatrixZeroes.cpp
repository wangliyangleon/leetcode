// https://oj.leetcode.com/problems/set-matrix-zeroes//
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row_cnt = matrix.size();
        int col_cnt = matrix.at(0).size();
        if (0 == row_cnt || 0 == col_cnt) {
            return;
        }
        vector<int> zero_rows;
        vector<int> zero_cols;
        for (int i = 0; i < row_cnt; ++i) {
            for (int j = 0; j < col_cnt; ++j) {
                if (0 == matrix.at(i).at(j)) {
                    zero_rows.push_back(i);
                    zero_cols.push_back(j);
                }
            }
        }

        for (int i = 0; i < zero_rows.size(); ++i) {
            matrix.at(zero_rows.at(i)).assign(col_cnt, 0);
        }
        for (int i = 0; i < zero_cols.size(); ++i) {
            for (int j = 0; j < row_cnt; ++j) {
                matrix[j][zero_cols.at(i)] = 0;
            }
        }
    }
};
