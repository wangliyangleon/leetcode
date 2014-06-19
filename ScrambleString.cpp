// https://oj.leetcode.com/problems/scramble-string/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        if (0 == s1.length()) {
            return true;
        }

        return check_level(s1, s2, 0, s1.length(), 0, s2.length());
    }

private:
    bool check_level(string& s1, string& s2, size_t s1_begin, size_t s1_length, size_t s2_begin, size_t s2_length) {
        if (s1_length != s2_length) {
            // impossible
            return false;
        }
        if (1 == s1_length) {
            return s1.at(s1_begin) == s2.at(s2_begin);
        }

        bool ret = false;
        for (int i = 1; i < s1_length; ++i) {
            size_t s1_left_begin = s1_begin;
            size_t s1_left_length = i;
            size_t s1_right_begin = s1_begin + i;
            size_t s1_right_length = s1_length - i;

            string s1_left_format = s1.substr(s1_left_begin, s1_left_length);
            sort(s1_left_format.begin(), s1_left_format.end());
            string s1_right_format = s1.substr(s1_right_begin, s1_right_length);
            sort(s1_right_format.begin(), s1_right_format.end());

            size_t s2_left_begin = s2_begin;
            size_t s2_left_length = s1_left_length;
            size_t s2_right_begin = s2_begin + s2_left_length;
            size_t s2_right_length = s1_right_length;

            string s2_left_format = s2.substr(s2_left_begin, s2_left_length);
            sort(s2_left_format.begin(), s2_left_format.end());
            string s2_right_format = s2.substr(s2_right_begin, s2_right_length);
            sort(s2_right_format.begin(), s2_right_format.end());

            if (s1_left_format == s2_left_format && s1_right_format == s2_right_format) {
                if (check_level(s1, s2, s1_left_begin, s1_left_length, s2_left_begin, s2_left_length) &&
                        check_level(s1, s2, s1_right_begin, s1_right_length, s2_right_begin, s2_right_length)) {
                    return true;
                }
            };

            s2_left_begin = s2_begin;
            s2_left_length = s1_right_length;
            s2_right_begin = s2_begin + s2_left_length;
            s2_right_length = s1_left_length;

            s2_left_format = s2.substr(s2_left_begin, s2_left_length);
            sort(s2_left_format.begin(), s2_left_format.end());
            s2_right_format = s2.substr(s2_right_begin, s2_right_length);
            sort(s2_right_format.begin(), s2_right_format.end());

            if (s1_left_format == s2_right_format && s1_right_format == s2_left_format) {
                if (check_level(s1, s2, s1_left_begin, s1_left_length, s2_right_begin, s2_right_length) &&
                        check_level(s1, s2, s1_right_begin, s1_right_length, s2_left_begin, s2_left_length)) {
                    return true;
                }
            }
        }
        return false;
    }
};
