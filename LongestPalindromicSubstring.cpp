// https://oj.leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        if ("" == s) {
            return s;
        }
        int cur_max_index = 0, cur_max_center = 0;
        int max_palin_len = 0, max_palin_index = 0;
        int index_before = 0, index_after = 0, cur_palin_len = 0;
        string str = "|";
        for (int i = 0; i < s.length(); ++i) {
            str += s.substr(i, 1);
            str += "|";
        }
        vector<int> palin_len_vec(str.length(), 0);
        for (int i = 0; i < str.length(); ++i) {
            if (i < cur_max_index) {
                cur_palin_len = min(cur_max_index - i, palin_len_vec.at(2 * cur_max_center - i));
            } else {
                cur_palin_len = 0;
            }
            while ((i > cur_palin_len) && (i + cur_palin_len < str.length()) &&
                    (str.at(i - cur_palin_len) == str.at(i + cur_palin_len))) {
                ++cur_palin_len;
                if (i + cur_palin_len > cur_max_index) {
                    cur_max_index = i + cur_palin_len;
                    cur_max_center = i;
                    if (cur_palin_len > max_palin_len) {
                        max_palin_len = cur_palin_len;
                        max_palin_index = i;
                    }
                }
            }
            palin_len_vec[i] = cur_palin_len;
        }

        string result = "";
        for (int i = max_palin_index - max_palin_len + 1; i < max_palin_index + max_palin_len; ++i) {
            if ('|' != str.at(i)) {
                result += str.substr(i, 1);
            }
        }
        return result;
    }
};
