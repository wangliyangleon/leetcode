// https://oj.leetcode.com/problems/word-break-ii/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (0 == s.length()) {
            return vector<string>();
        }
        vector<bool> match_vec(s.length(), false);
        for (int i = s.length() - 1; i >= 0; --i) {
            if (dict.end() != dict.find(s.substr(i, s.length() - i))) {
                match_vec[i] = true;
            } else {
                for (int j = s.length() - 1; j > i; --j) {
                    if (match_vec.at(j) && (dict.end() != dict.find(s.substr(i, j - i)))) {
                        match_vec[i] = true;
                        break;
                    }
                }
            }
        }
        if (!match_vec.at(0)) {
            return vector<string>();
        }

        _string_vec.assign(s.length(), vector<string>());
        for (int i = 0; i < s.length(); ++i) {
            if (i == s.length() - 1 || match_vec.at(i + 1)) {
                _try_step(s, i, dict);
            }
        }
        return _string_vec.at(s.length() - 1);
    }

private:
    void _try_step(const string& s, size_t index, const unordered_set<string> &dict) {
        vector<string>& cur_vec = _string_vec.at(index);
        unordered_set<string> dup_dict;
        cur_vec.clear();
        if (dict.end() != dict.find(s.substr(0, index + 1))) {
            cur_vec.push_back(s.substr(0, index + 1));
        }
        for (int i = 0; i < index; ++i) {
            const vector<string>& saved_vec = _string_vec.at(i);
            string cur_substr = s.substr(i + 1, index - i);
            if ((saved_vec.size() > 0) && (dict.end() != dict.find(cur_substr))) {
                for (int j = 0; j < saved_vec.size(); ++j) {
                    string cur_result = saved_vec.at(j) + " " + cur_substr;
                    if (dup_dict.end() == dup_dict.find(cur_result)) {
                        cur_vec.push_back(cur_result);
                        dup_dict.insert(cur_result);
                    }
                }
            }
        }
    }
    vector<vector<string> > _string_vec;
};
