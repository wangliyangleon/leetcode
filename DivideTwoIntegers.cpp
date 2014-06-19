// https://oj.leetcode.com/problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == divisor) {
            return 0;
            // error
        } else if (1 == divisor) {
            return dividend;
        } else if (-1 == divisor) {
            return -dividend;
        } else if ((INT_MIN == divisor) && (INT_MIN == dividend)) {
            return 1;
        } else if (INT_MIN == divisor) {
            return 0;
        }

        int result = 0, sign = 1;
        if (divisor < 0) {
            sign = -sign;
            divisor = -divisor;
        }
        if (dividend < 0) {
            sign = -sign;
            if (INT_MIN == dividend) {
                dividend = INT_MAX - divisor + 1;
                result = 1;
            } else {
                dividend = -dividend;
            }
        }

        int gap = divisor, time = 1;
        while (dividend >= divisor) {
            dividend -= gap;
            if (dividend < 0) {
                dividend += gap;
                gap -= divisor;
                --time;
            } else {
                result += time;
                gap += divisor;
                ++time;
            }
        }
        return sign > 0 ? result : -result;
    }
};
