// https://oj.leetcode.com/problems/count-and-say/
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        if (1 == n) {
            return result;
        }
        for (int i = 2; i <= n; ++i) {
            result = _count(result, i);
        }
        return result;
    }

private:
    string _count(string str, int n) {
        unordered_map<int, string>::iterator result_iter = _result_map.find(n);
        if (result_iter != _result_map.end()) {
            return result_iter->second;
        }
        char cur_num = 0;
        int cur_cnt = 0;
        string result = "";
        for (string::const_iterator iter = str.begin();
                iter != str.end(); ++iter) {
            if (*iter != cur_num) {
                if (0 != cur_num) {
                    snprintf(_cvt_buf, 32, "%d%c", cur_cnt, cur_num);
                    result += _cvt_buf;
                }
                cur_num = *iter;
                cur_cnt = 1;
            } else {
                ++cur_cnt;
            }
        }
        snprintf(_cvt_buf, 32, "%d%c", cur_cnt, cur_num);
        result += _cvt_buf;
        _result_map.insert(pair<int, string>(n, result));
        return result;
    }

    char _cvt_buf[32];
    unordered_map<int, string> _result_map;
};
