// https://oj.leetcode.com/problems/restore-ip-addresses/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        _result.clear();
        if ("" == s) {
            return _result;
        }
        _nextPart(0, s, 0, "");
        return _result;
    }

private:
    void _nextPart(int index, string& s, int pos, string cur_str) {
        if (3 == index) {
            string cur_part_str = s.substr(pos, s.length() - pos);
            if (1 == cur_part_str.length() || '0' != cur_part_str.at(0)) {
                int cur_part = atoi(cur_part_str.c_str());
                if (cur_part <= 255) {
                    cur_str += cur_part_str;
                    _result.push_back(cur_str);
                }
            }
        } else {
            for (int i = 1; i <= 3; ++i) {
                if (pos + i >= s.length()) {
                    break;
                }
                string cur_part_str = s.substr(pos, i);
                if (1 == cur_part_str.length() || '0' != cur_part_str.at(0)) {
                    string cur_str_cpy = cur_str;
                    int cur_part = atoi(cur_part_str.c_str());
                    if (cur_part <= 255) {
                        cur_str_cpy += cur_part_str;
                        cur_str_cpy += ".";
                        _nextPart(index + 1, s, pos + i, cur_str_cpy);
                    }
                }
            }
        }
    }
    vector<string> _result;
};
