// https://oj.leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words_vec;
        string cur_str = "";
        for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
            if (*iter == ' ') {
                if (cur_str.length() > 0) {
                    words_vec.push_back(cur_str);
                    cur_str = "";
                }
                while ((iter != s.end()) && (*iter == ' ')) {
                    ++iter;
                }
            }
            if (iter != s.end()){
                cur_str += string(1, *iter);
            } else {
                break;
            }
        }
        if (cur_str.length() > 0) {
            words_vec.push_back(cur_str);
        }

        s = "";
        for (int i = words_vec.size() - 1; i >= 0; --i) {
            s += words_vec.at(i);
            if (i > 0) {
                s += string(1, ' ');
            }
        }
    }
};
