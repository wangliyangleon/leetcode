// https://oj.leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sign = (x > 0 ? 1 : -1), result = 0;
        x = (x > 0 ? x : -x);
        while (x > 0) {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        return result * sign;
    }
};
