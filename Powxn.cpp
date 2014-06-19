// https://oj.leetcode.com/problems/powx-n/
class Solution {
public:
    double pow(double x, int n) {
        if (0 == n) {
            return 1.0;
        }

        double result = 1, cur_result = 1;
        int tn = 0;
        bool sign = false;
        if (n < 0) {
            sign = true;
            n = -n;
        }
        while (n > 0) {
            tn = n;
            n &= (n - 1);
            tn -= n;
            tn >>= 1;
            cur_result = x;
            while (tn > 0) {
                cur_result *= cur_result;
                tn >>= 1;
            }
            result *= cur_result;
        }
        return sign ? 1.0 / result : result;
    }
};
