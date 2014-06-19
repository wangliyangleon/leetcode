// https://oj.leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        if (0 == s.length()) {
            return 0;
        }
        vector<int> save_vec(s.length() + 1, -1);
        return _tryCurStr(s, save_vec);
    }
private:
    int _tryCurStr(string s, vector<int>& save_vec) {
        if (-1 == save_vec.at(s.length())) {
            if ('0' == s.at(0)) {
                save_vec[s.length()] = 0;
            } else if (1 == s.length()) {
                save_vec[s.length()] = 1;
            } else if (2 == s.length()) {
                int cvt = atoi(s.c_str());
                if (cvt > 26) {
                    if (0 == cvt % 10) {
                        save_vec[s.length()] = 0;
                    } else {
                        save_vec[s.length()] = 1;
                    }
                } else {
                    if (0 == cvt % 10) {
                        save_vec[s.length()] = 1;
                    } else {
                        save_vec[s.length()] = 2;
                    }
                }
            } else {
                if (atoi(s.substr(0, 2).c_str()) > 26) {
                    save_vec[s.length()] = _tryCurStr(s.substr(1, s.length() - 1), save_vec);
                } else {
                    save_vec[s.length()] = _tryCurStr(s.substr(1, s.length() - 1), save_vec) +
                        _tryCurStr(s.substr(2, s.length() - 2), save_vec);
                }
            }
        }
        return save_vec.at(s.length());
    }
};
