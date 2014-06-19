// https://oj.leetcode.com/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int tx = x / 10, sign = 1;
        while (tx > 0) {
            sign *= 10;
            tx /= 10;
        }
        while (x > 0) {
            if (x / sign != x % 10) {
                return false;
            }
            x %= sign;
            x /= 10;
            sign /= 100;
        }
        return true;
    }
};
