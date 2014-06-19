// https://oj.leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        string cvt_s = "";
        for (string::const_iterator iter = s.begin();
                iter != s.end(); ++iter) {
            if ((*iter >= 'a' && *iter <= 'z') || (*iter >= '0' && *iter <= '9')) {
                cvt_s += string(1, *iter);
            } else if (*iter >= 'A' && *iter <= 'Z') {
                cvt_s += string(1, *iter - 'A' + 'a');
            }
        }

        int index_left = 0, index_right = 0;
        if (0 == cvt_s.length() % 2) {
            index_left = cvt_s.length() / 2 - 1;
            index_right = cvt_s.length() / 2;
        } else {
            index_left = cvt_s.length() / 2 - 1;
            index_right = cvt_s.length() / 2 + 1;
        }
        while (index_left >= 0) {
            if (cvt_s.at(index_left) != cvt_s.at(index_right)) {
                return false;
            }
            --index_left;
            ++index_right;
        }
        return true;
    }
};
