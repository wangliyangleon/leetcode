// https://oj.leetcode.com/problems/pascals-triangle-ii/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last_line(1, 1);
        vector<int> cur_line;
        for (int i = 0; i < rowIndex; ++i) {
            cur_line.assign(1, 1);
            for (int j = 1; j <= i; ++j) {
                cur_line.push_back(last_line.at(j - 1) + last_line.at(j));
            }
            cur_line.push_back(1);
            cur_line.swap(last_line);
        }
        return last_line;
    }
};
