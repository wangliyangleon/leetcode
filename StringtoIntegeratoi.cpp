// https://oj.leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    int atoi(const char *str) {
        const char* p = str;
        const char* tp = str;
        size_t num_length = 0;
        int sign = 1, result = 0;

        // trim
        while (*p == ' ') {
            ++p;
        }

        // get sign
        if ('-' == *p) {
            sign = -1;
            ++p;
        } else if ('+' == *p) {
            ++p;
        }
        // rtrim
        tp = p;
        while ((*tp >= '0') && (*tp <= '9')) {
            ++tp;
            ++num_length;
        }

        // check INT_MAX and INT_MIN: +-2147483647
        const char* const INT_MAX_STR = "2147483647";
        if (num_length > strlen(INT_MAX_STR)) {
            return sign > 0 ? INT_MAX : INT_MIN;
        } else if (num_length == strlen(INT_MAX_STR)) {
            for (int i = 0; i < num_length; ++i) {
                if (p[i] > INT_MAX_STR[i]) {
                    return sign > 0 ? INT_MAX : INT_MIN;
                } else if (p[i] < INT_MAX_STR[i]) {
                    break;
                }
            }
        }

        // get result
        for (int i = 0; i < num_length; ++i) {
            result *= 10;
            result += (p[i] - '0');
        }
        return result * sign;
    }
};
