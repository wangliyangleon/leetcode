// https://oj.leetcode.com/problems/valid-number/
class Solution {
public:
    bool isNumber(const char *s) {
        if (NULL == s || '\0' == *s) {
            return false;
        }

        // 1. trim
        const char* sb = s;
        const char* se = s + strlen(s) - 1;
        while (' ' == *sb) {
            ++sb;
        }
        while (' ' == *se) {
            --se;
        }
        ++se;

        // 2. flags
        bool has_dot = false;
        bool has_e = false;
        bool has_enum = false;

        // 3. sign and 0x
        if ('+' == *sb || '-' == *sb) {
            ++sb;
        }
        if (0 == strncmp("0x", sb, 2) || 0 == strncmp("0X", sb, 2)) {
            sb += 2;
        }
        if ('.' == *sb) {
            ++sb;
            has_dot = true;
        }

        // 4. go!
        if (sb >= se) {
            return false;
        }
        for (const char* p = sb; p < se; ++p) {
            if ('.' == *p) {
                if (has_dot || has_e) {
                    return false;
                } else {
                    has_dot = true;
                }
            } else if ('E' == *p || 'e' == *p) {
                if (has_e || p + 1 == se || p == sb) {
                    return false;
                } else {
                    has_e = true;
                }
                if ('+' == *(p + 1) ||'-' == *(p + 1)) {
                    ++p;
                }
            } else if (*p < '0' || *p > '9') {
                return false;
            } else {
                has_enum = has_e;
            }
        }
        if (has_e && (!has_enum)) {
            return false;
        }
        return true;
    }
};
