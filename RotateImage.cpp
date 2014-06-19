// https://oj.leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for (int i = 0; i < matrix.size() / 2; ++i) {
            _retate_around(matrix, i);
        }
    }

private:
    void _retate_around(vector<vector<int> > &matrix, int index) {
        int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
        size_t cur_size = matrix.size() - 2 * index;
        for (int i = 0; i < cur_size - 1; ++i) {
            temp1 = matrix.at(index).at(index + i);
            temp2 = matrix.at(index + i).at(index + cur_size - 1);
            temp3 = matrix.at(index + cur_size - 1).at(index + cur_size - 1 - i);
            temp4 = matrix.at(index + cur_size - 1 - i).at(index);

            matrix[index + i][index + cur_size - 1] = temp1;
            matrix[index + cur_size - 1][index + cur_size - 1 - i] = temp2;
            matrix[index + cur_size - 1 - i][index] = temp3;
            matrix[index][index + i] = temp4;
        }   
    }   
};  
