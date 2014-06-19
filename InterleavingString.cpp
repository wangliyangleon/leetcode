// https://oj.leetcode.com/problems/interleaving-string/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ("" == s1 && "" == s2 && "" == s3) {
            return true;
        } else if (s1.length() + s2.length() != s3.length()) {
            return false;
        } else {
            vector<vector<int> > trace_flag(s1.length() + 1, vector<int>(s2.length() + 1, 0));
            return _tryInterleave(s1, s2, s3, true, trace_flag) ||
                _tryInterleave(s1, s2, s3, false, trace_flag);
        }
    }

private:
    bool _tryInterleave(string s1, string s2, string s3, bool is_try_s1, vector<vector<int> >& trace_flag) {
        if ("" == s1 && "" == s2 && "" == s3) {
            return true;
        }
        if (is_try_s1) {
            for (int i = 0; i < s1.length(); ++i) {
                if (s1.at(i) == s3.at(i)) {
                    if (0 == (trace_flag.at(s1.length()).at(s2.length()) & 0x1)) {
                        if (_tryInterleave(s1.substr(i + 1, s1.length() - i - 1),
                                    s2, s3.substr(i + 1, s3.length() - i - 1), false, trace_flag)) {
                            return true;
                        }
                        trace_flag[s1.length() - i - 1][s2.length()] |= 0x1;
                    }
                } else {
                    break;
                }
            }
        } else {
            for (int i = 0; i < s2.length(); ++i) {
                if (s2.at(i) == s3.at(i)) {
                    if (0 == (trace_flag.at(s1.length()).at(s2.length()) & 0x10)) {
                        if (_tryInterleave(s1, s2.substr(i + 1, s2.length() - i - 1),
                                    s3.substr(i + 1, s3.length() - i - 1), true, trace_flag)) {
                            return true;
                        }
                        trace_flag[s1.length()][s2.length() - i - 1] |= 0x10;
                    }
                } else {
                    break;
                }
            }
        }
        // cout << "no match " << s1 << "\t" << s2 << "\t" << s3 << endl;
        return false;
    }
};
