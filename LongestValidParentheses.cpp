// https://oj.leetcode.com/problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        if (0 == s.length()) {
            return 0;
        }

        int max = 0;
        vector<int> lvlen_vec(s.length(), 0);
        for (int i = s.length() - 2; i >= 0; --i) {
            if ('(' == s.at(i)) {
                size_t checkpos = i + lvlen_vec.at(i + 1) + 1;
                if ((checkpos < s.length()) && (')' == s.at(checkpos))) {
                    lvlen_vec[i] = lvlen_vec.at(i + 1) + 2;
                    if (checkpos + 1 < s.length()) {
                        lvlen_vec[i] += lvlen_vec.at(checkpos + 1);
                    }
                }
                if (max < lvlen_vec.at(i)) {
                    max = lvlen_vec.at(i);
                }
            }
        }
        return max;
    }
};
