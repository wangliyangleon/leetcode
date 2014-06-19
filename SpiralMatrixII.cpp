// https://oj.leetcode.com/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int start = 1;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            start = _fill_around(i, start, matrix);
        }
        return matrix;
    }

private:
    int _fill_around(int index, int start, vector<vector<int> >& matrix) {
        matrix[index][index] = start;
        int length = matrix.size() - index * 2 - 1;
        for (int i = 0; i < length; ++i) {
            matrix[index][index + i] = start++;
        }
        for (int i = 0; i < length; ++i) {
            matrix[index + i][index + length] = start++;
        }
        for (int i = 0; i < length; ++i) {
            matrix[index + length][index + length - i] = start++;
        }
        for (int i = 0; i < length; ++i) {
            matrix[index + length - i][index] = start++;
        }
        return start;
    }
};
