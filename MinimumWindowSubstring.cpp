// https://oj.leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string S, string T) {
        if ("" == T || S.length() < T.length()) {
            return "";
        }

        vector<int> char_cnt(256, 0);
        vector<int> got_cnt(256, 0);
        vector<size_t> pos_vec;
        bool found = false;

        for (string::const_iterator iter = T.begin();
                iter != T.end(); ++iter) {
            ++char_cnt[*iter];
        }

        for (size_t i = 0; i < S.size(); ++i) {
            if (char_cnt.at(S.at(i)) > 0) {
                pos_vec.push_back(i);
            }
        }
        if (0 == pos_vec.size()) {
            return "";
        }

        size_t min_pos = 0, min_len = S.length(), rest_len = T.length();
        const size_t MAX_POS = S.length() - T.length();
        vector<size_t>::const_iterator biter = pos_vec.begin();
        vector<size_t>::const_iterator eiter = pos_vec.begin();
        ++got_cnt[S.at(*biter)];
        --rest_len;

        while ((biter != pos_vec.end()) && (*biter <= MAX_POS)) {
            if (0 == rest_len) {
                found = true;
                size_t cur_len = *eiter - *biter + 1;
                if (cur_len < min_len) {
                    min_len = cur_len;
                    min_pos = *biter;
                }

                char cur_ch = S.at(*biter);
                if (got_cnt.at(cur_ch) == char_cnt.at(cur_ch)) {
                    ++rest_len;
                }
                --got_cnt[S.at(*biter)];
                ++biter;
            } else {
                ++eiter;
                if (pos_vec.end() == eiter) {
                    break;
                }

                char cur_ch = S.at(*eiter);
                if (got_cnt.at(cur_ch) < char_cnt.at(cur_ch)) {
                    --rest_len;
                }
                ++got_cnt[S.at(*eiter)];
            }
        }

        return (found ? S.substr(min_pos, min_len) : "");
    }
};
