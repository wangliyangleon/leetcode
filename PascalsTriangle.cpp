// https://oj.leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (0 == numRows) {
            return result;
        }
        result.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; ++i) {
            vector<int> vec;
            for (int j = 0; j <= i; ++j) {
                if (0 == j || i == j) {
                    vec.push_back(1);
                } else {
                    vec.push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
