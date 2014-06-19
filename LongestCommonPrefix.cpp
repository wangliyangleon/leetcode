// https://oj.leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (0 == strs.size()) {
            return "";
        }
        string result = "";
        char cur_ch = '\0';
        for (int i = 0; i < strs.at(0).size(); ++i) {
            cur_ch = strs.at(0).at(i);
            for (vector<string>::iterator iter = strs.begin() + 1;
                    iter != strs.end(); ++iter) {
                if (i >= iter->size() || cur_ch != iter->at(i)) {
                    return result;
                }
            }
            result += string(1, cur_ch);
        }
        return result;
    }
};
