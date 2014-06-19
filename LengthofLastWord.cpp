// https://oj.leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if ((NULL == s) || (0 == *s)) {
            return 0;
        }
        int result = 0;
        const char *p = s + strlen(s) - 1;
        // r trim
        while ((p >= s) && (' ' == *p)) {
            --p;
        }
        while ((p >= s) && (' ' != *p)) {
            --p;
            ++result;
        }
        return result;
    }
};
