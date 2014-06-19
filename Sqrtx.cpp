// https://oj.leetcode.com/problems/sqrtx/
class Solution {
public:
    int sqrt(int x) {
        long long l = 0, r = x, m = 0;
        while (l <= r) {
            m = (l + r) / 2;
            if (((m * m) <= x) && (((m + 1) * (m + 1)) > x)) {
                return m;
            } else if ((m * m) > x) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return 0;
    }
};
