// https://oj.leetcode.com/problems/gray-code/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int gc_num = (1 << n);
        for (int i = 0; i < gc_num; ++i) {
            int cur_gc = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >= (1 << j)) &&
                        (((i - (1 << j)) / (1 << (j + 1))) % 2 == 0)) {
                    cur_gc |= (1 << j);
                }
            }
            result.push_back(cur_gc);
        }
        return result;
    }
};
