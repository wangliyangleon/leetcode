// https://oj.leetcode.com/problems/text-justification/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        if (0 == words.size()) {
            return result;
        }
        int index = 0;
        while (index < words.size()) {
            int end = index + 1;
            size_t cur_size = words.at(index).length();
            size_t word_len = cur_size;
            while (end < words.size()) {
                size_t ext_size = words.at(end).length() + 1;
                if (cur_size + ext_size > L) {
                    break;
                }
                ++end;
                word_len += (ext_size - 1);
                cur_size += ext_size;
            }
            --end;
            if (end == index) {
                result.push_back(words.at(index) + string(L - words.at(index).length(), ' '));
            } else if (end == words.size() - 1) {
                int blank_len = L - word_len;
                string cur_part = words.at(index);
                for (int i = index + 1; i <= end; ++i) {
                    cur_part += (" " + words.at(i));
                    --blank_len;
                }
                cur_part += (string(blank_len, ' '));
                result.push_back(cur_part);
            } else {
                int blank_cnt = end - index, blank_len = L - word_len;
                string cur_part = words.at(index);
                for (int i = index + 1; i <= end; ++i) {
                    cur_part += (string(blank_len / blank_cnt + ((i - index) <= (blank_len % blank_cnt) ? 1 : 0), ' ') + words.at(i));
                }
                result.push_back(cur_part);
            }
            index = end + 1;
        }
        return result;
    }
};
