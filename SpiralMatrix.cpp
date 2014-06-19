// https://oj.leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (0 == matrix.size() || 0 == matrix.at(0).size()) {
            return result;
        }
        for (int i = 0, j = 0; (i < (matrix.size() + 1) / 2 && j < (matrix.at(0).size() + 1) / 2); ++i, ++j) {
            _go_around(i, j, result, matrix);
        }
        return result;
    }

private:
    void _go_around(int x, int y, vector<int>& vec, vector<vector<int> > &matrix) {
        int row = matrix.size() - x * 2 - 1;
        int col = matrix.at(0).size() - y * 2 - 1;
        if (0 == row && 0 == col) {
            vec.push_back(matrix.at(x).at(y));
        } else if (0 == row) {
            for (int i = 0; i <= col; ++i) {
                vec.push_back(matrix.at(x).at(y + i));
            }
        } else if (0 == col) {
            for (int i = 0; i <= row; ++i) {
                vec.push_back(matrix.at(x + i).at(y));
            }
        } else {
            for (int i = 0; i < col; ++i) {
                vec.push_back(matrix.at(x).at(y + i));
            }
            for (int i = 0; i < row; ++i) {
                vec.push_back(matrix.at(x + i).at(y + col));
            }
            for (int i = 0; i < col; ++i) {
                vec.push_back(matrix.at(x + row).at(y + col - i));
            }
            for (int i = 0; i < row; ++i) {
                vec.push_back(matrix.at(x + row - i).at(y));
            }
        }
    }
};
