// https://oj.leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (0 == matrix.size() || 0 == matrix.at(0).size()) {
            return false;
        }
        // find row
        int row = 0, mid = 0, 
            left = 0, right = matrix.size();
        if (target < matrix.at(0).at(0)) {
            return false;
        } else if (target >= matrix.at(matrix.size() - 1).at(0)) {
            row = matrix.size() - 1;
        } else {
            for (;;) {
                row = (left + right) / 2;
                if ((matrix.at(row).at(0) <= target) && (matrix.at(row + 1).at(0) > target)) {
                    break;
                } else if (matrix.at(row).at(0) <= target) {
                    left = row + 1;
                } else {
                    right = row - 1;
                }
            }
        }
        // find col
        if (target > matrix.at(row).at(matrix.at(row).size() - 1)) {
            return false;
        } else {
            left = 0;
            right = matrix.at(row).size();
            while (left <= right) {
                mid = (left + right) / 2;
                if (matrix.at(row).at(mid) > target) {
                    right = mid - 1;
                } else if (matrix.at(row).at(mid) < target) {
                    left = mid + 1;
                } else {
                    return true;
                }
            }
            return false;
        }
    }
};
