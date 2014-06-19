// https://oj.leetcode.com/problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        return calc_num(1, n);
    }
private:
    int calc_num(int start, int end) {
        if (start >= end) {
            return 1;
        } else if (start + 1 == end) {
            return 2;
        }
        int ret = 0;
        for (int i = start; i <= end; ++i) {
            ret += calc_num(start, i - 1) * calc_num(i + 1, end);
        }
        return ret;
    }
};
